#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxFreqSum(string s) {
        int cnt[26] = {0};
        static const bool V[26] = {
            1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0
        };
        int maxV = 0, maxC = 0;

        for (char ch : s) {
            char c = (ch >= 'A' && ch <= 'Z') ? (ch - 'A' + 'a') : ch;
            int idx = c - 'a';
            int x = ++cnt[idx];
            if (V[idx]) maxV = (x > maxV ? x : maxV);
            else        maxC = (x > maxC ? x : maxC);
        }
        return maxV + maxC;
    }
};




// static unordered_set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};

// class Solution {
// public:
//     bool isVowels(char c){
//         return vowels.count(c);
//     }

//     int ReturnMaxNumber( unordered_map<char,int> Times){
//         int maxNumber = 0;
//         for(int i = 0;i<Times.size();i++){
//             if(maxNumber < Times[i]){
//                 maxNumber = Times[i];
//             }
//         }
//         return maxNumber;

//     }

//     int maxFreqSum(string s) {
//         unordered_map<char,int> VowelsTimes;
//         unordered_map<char,int> consonantsTimes;
//         for(int i = 0;i<s.size();i++){
//             if(isVowels(s[i])){
//                 VowelsTimes[s[i]]++;
//             }
//             else{
//                 consonantsTimes[s[i]]++;
//             }
//         }

//         return ReturnMaxNumber(VowelsTimes) + ReturnMaxNumber(consonantsTimes);
//     }
// };

// int main(){
//     Solution sol;
//     string s;
//     cout << sol.maxFreqSum(s) << endl;
// }