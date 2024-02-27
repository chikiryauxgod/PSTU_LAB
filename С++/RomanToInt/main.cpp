#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> nums;
        nums['I'] = 1;
        nums['V'] = 5;
        nums['X'] = 10;
        nums['L'] = 50;
        nums['C'] = 100;
        nums['D'] = 500;
        nums['M'] = 1000;

        int result = 0;
        int prevValue = 0;
        for (int i = 0; i < s.length(); i++) {
            int currentValue = nums[s[i]];
            if (prevValue < currentValue)
            {
                result -= prevValue;
            }
            else
            {
                result += prevValue;
            }
            prevValue = currentValue;
        }
        result += prevValue;
        return result;
    }
};

int main() {
    Solution sol;
    cout << sol.romanToInt("MCMXCIV") << endl;
    return 0;
}
