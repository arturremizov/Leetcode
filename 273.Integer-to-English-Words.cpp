#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";

        vector<string> postfix({"", " Thousand", " Million", " Billion"});
        vector<string> resultStrings;
        int i = 0;
        while (num) {
            int digits = num % 1000;
            string s = getString(digits);
            if (!s.empty()) {
                resultStrings.insert(resultStrings.begin(), s + postfix[i]);
            }
            num /= 1000;
            ++i;
        }

        return join(resultStrings);
    }
private:
    string getString(int num) {
        vector<string> resultStrings;

        int hundreds = num / 100;
        if (hundreds) {
            string s = onesMap[hundreds] + " Hundred";
            resultStrings.push_back(s); 
        }

        int lastTwoDigits = num % 100;
        if (lastTwoDigits >= 20) {
            int tens = lastTwoDigits / 10;
            int ones = lastTwoDigits % 10;

            resultStrings.push_back(tensMap[tens * 10]); 
            if (ones > 0) {
                resultStrings.push_back(onesMap[ones]); 
            }
        } else if (lastTwoDigits > 0) {
            resultStrings.push_back(onesMap[lastTwoDigits]); 
        }
        return join(resultStrings);
    }

    string join(vector<string> strings) {
        string result;
        for (int i = 0; i < strings.size(); i++) {
            result += strings[i];
            if (i < strings.size() - 1) {
                result += " ";
            }
        }
        return result;
    }

    unordered_map<int, string> onesMap = {    
        {1, "One"},
        {2, "Two"},
        {3, "Three"},
        {4, "Four"},
        {5, "Five"},
        {6, "Six"},
        {7, "Seven"},
        {8, "Eight"},
        {9, "Nine"},
        {10, "Ten"},
        {11, "Eleven"},
        {12, "Twelve"},
        {13, "Thirteen"},
        {14, "Fourteen"},
        {15, "Fifteen"},
        {16, "Sixteen"},
        {17, "Seventeen"},
        {18, "Eighteen"},
        {19, "Nineteen"}
    };

    unordered_map<int, string> tensMap = {
        {20, "Twenty"},
        {30, "Thirty"},
        {40, "Forty"},
        {50, "Fifty"},
        {60, "Sixty"},
        {70, "Seventy"},
        {80, "Eighty"},
        {90, "Ninety"}
    };
};

int main() {
    Solution solution; 
    cout << solution.numberToWords(123) << endl; // One Hundred Twenty Three
    cout << solution.numberToWords(12345) << endl; // Twelve Thousand Three Hundred Forty Five
    cout << solution.numberToWords(1234567) << endl; // One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven
}