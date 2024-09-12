#include <stdio.h>
#include <tgbot/tgbot.h>
#include <ctime>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include <iomanip>
#include <sstream>
#include <vector>

using namespace std;
using json = nlohmann::json;
string apiKey = "ZZZ ВПЕРЕД СЛОНЫ";

vector<string> bot_commands = { "start", "city" };

size_t callbackWrite(void* contents, size_t size, size_t nmemb, void* userp);

string weatherParse(const string& weatherData) {
    try {
        cout << "Weather data received: " << weatherData << endl; 
        json data = json::parse(weatherData);
        if (data["code"] != 200) {
            return "City is not found";
        }

        string cityName = data["name"];
        string weatherDescription = data["weather"][0]["description"];
        float temperature = data["main"]["temp"];
        stringstream temperature_ss;
        temperature_ss << fixed << setprecision(2) << temperature;
        string temperature_str = temperature_ss.str();
        string weatherInfo = "Weather in " + cityName + ": " + weatherDescription + ", " + temperature_str + " *C";
        return weatherInfo;
    }
    catch (const json::parse_error& e) {
        return "Failed to parse weather data: " + string(e.what());
    }
}

string weatherGet(const string& city) {
    string url = "http://api.openweathermap.org/data/2.5/weather?q=" + city + "&appid=" + apiKey + "&units=metric";
    CURL* curl;
    CURLcode res;
    string readBuffer;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callbackWrite);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if (res != CURLE_OK) {
            return "Failed to get weather data...";
        }
    }

    return readBuffer;
}

size_t callbackWrite(void* contents, size_t size, size_t nmemb, void* userp) {
    ((string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main() {
    TgBot::Bot bot("7328362343:AAHQmKQ7gTl-hjciwmEuo5E1FWOzaYWCciE");

    bot.getEvents().onCommand("start", [&bot](TgBot::Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "Hi, " + message->chat->firstName + "!");
        });

    bot.getEvents().onCommand("city", [&bot](TgBot::Message::Ptr message) {
        string city = message->text;
        if (city.empty()) {
            bot.getApi().sendMessage(message->chat->id, "Please write a city name like this: /city Moscow");
        }
        else {
            string weatherData = weatherGet(city);
            string weatherInfo = weatherParse(weatherData);
            bot.getApi().sendMessage(message->chat->id, weatherInfo);
        }
        });

    bot.getEvents().onAnyMessage([&bot](TgBot::Message::Ptr message) {
        printf("User wrote %s\n", message->text.c_str());

        for (const auto& command : bot_commands) {
            if (message->text.find("/" + command) == 0) {
                return;
            }
        }

        bot.getApi().sendMessage(message->chat->id, "I don't know this command...");
        });

    try {
        printf("Bot username: %s\n", bot.getApi().getMe()->username.c_str());
        TgBot::TgLongPoll longPoll(bot);
        while (true) {
            printf("Long poll started\n");
            longPoll.start();
        }
    }
    catch (TgBot::TgException& e) {
        printf("error: %s\n", e.what());
    }
    return 0;
}
