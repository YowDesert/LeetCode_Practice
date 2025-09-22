#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string sortVowels(string s) {
        vector<int> index;
        vector<int> character;
        for(int i =0;i<s.size();i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' ||s[i] == 'U')
            {
                index.push_back(i);
                character.push_back(s[i]);
            }   
        }
        sort(character.begin(),character.end());
        for(int i = 0;i<index.size();i++){
            s[index[i]] = character[i];
        }
        return s;
    }
};

int main(){
    Solution sol;
    string s;
    s = "lEetcOde";
    cout << sol.sortVowels(s)<<endl;
}