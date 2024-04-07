#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string word1 = "fish", word2 = "fosh";
    const size_t& size1 = word1.size(), & size2 = word2.size();
    size_t** table = new size_t * [size1];
    for (size_t i = 0; i < size1; i++)
    {
        table[i] = new size_t[size2]{};
    }


    for (size_t i = 0; i < size1; i++)
    {
        for (size_t j = 0; j < size2; j++) 
        {
            if (word1[i] == word2[j])
            {
                if (i > 0 && j > 0)
                {
                    table[i][j] = table[i - 1][j - 1] + 1;
                }
                else
                {
                    table[i][j] = 1;
                }
            }
            else
            {
                if (i > 0 && j > 0)
                {
                    table[i][j] = max(table[i - 1][j], table[i][j - 1]);
                }
                else if (i == 0 && j > 0)
                {
                    table[i][j] = table[i][j - 1];
                }
                else if (i > 0 && j == 0)
                {
                    table[i][j] = table[i - 1][j];
                }
                else
                {
                    table[i][j] = 0;
                }
            }
        }
    }


    for (size_t i = 0; i < size1; i++)
    {
        for (size_t j = 0; j < size2; j++)
        {
            cout << table[i][j] << ' ';
        }
        cout << endl;
    }


    for (size_t i = 0; i < size1; i++)
    {
        delete[] table[i];
    }
    delete[] table;

    return 0;
}
