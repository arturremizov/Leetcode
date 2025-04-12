#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <cmath>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        vector<string> palindromes = generatePalidromes(n);
        unordered_set<string> seen;
        long long result = 0;
        for (string palindrome : palindromes) {
            if (stoll(palindrome) % k != 0) continue;

            string key = palindrome;
            sort(key.begin(), key.end());
            if (seen.count(key)) continue;
            seen.insert(key);

            result += countPermutations(palindrome);
        }
        return result;
    }
private:
    vector<string> generatePalidromes(int n) {
        int half = (n + 1) / 2;
        int start = pow(10, (half - 1));
        int end = pow(10, half);
        vector<string> palidromes;
        for (int num = start; num < end; ++num) {
            string firstHalf = to_string(num);
            string secondHalf = firstHalf;
            reverse(secondHalf.begin(), secondHalf.end());
            if (n % 2 == 1) {
                secondHalf.erase(0, 1);
            }
            palidromes.push_back(firstHalf + secondHalf);
        }
        return palidromes;
    }
    long long countPermutations(string palindrome) {
        unordered_map<char, int> freq;
        for (char c : palindrome) freq[c]++;
        
        long long total = factorial(palindrome.length());
        for (auto [_, count] : freq) {
            total /= factorial(count);
        }

        if (freq.count('0')) {
            freq['0']--;
            long long totalZero = factorial(palindrome.length() - 1);
            for (auto [_, count] : freq) {
                totalZero /= factorial(count);
            }
            total -= totalZero;
        }
        return total;
    }

    long long factorial(int num) {
        long factorial = 1;
        for (int i = 1; i <= num; ++i) {
            factorial *= i;
        }
        return factorial;
    }
};

int main() {
    Solution solution; 
    cout << solution.countGoodIntegers(3, 5) << endl; // 27
}