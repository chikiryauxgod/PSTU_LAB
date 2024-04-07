#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

int main()
{
    srand(time(nullptr));

    vector<int> five_thousand_elements;
    for (int i = 0; i < 5000; i++)
    {
        five_thousand_elements.push_back(rand() % 100);
        if ((i + 1) % 100 == 0) {
            int size = five_thousand_elements.size();
            int cap = five_thousand_elements.capacity();
            double ratio = static_cast<double>(cap) / size;
            cout << endl << size << " - size of " << size << " el vector." << endl;
            cout << cap << " - capacity " << size << " el vector." << endl;
            cout << ratio << " - ratio for " << size << " el vector." << endl;
        }
    }

    return 0;
}
