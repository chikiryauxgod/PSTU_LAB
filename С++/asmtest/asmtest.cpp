#include <iostream>

extern "C" const char* what();

int main()
{
    std::cout << what() << "\n";
    return 0;
}
