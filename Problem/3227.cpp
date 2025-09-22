#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool doesAliceWin(string s) {
        int count = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' ||s[i] == 'U'){
                count++;
            }
        }    
        if(count == 0){
            return false;
        }
        else {
            return true;
        }
    }
};

int main(){
    Solution sol;
    string s;
    s = "leetcoder";
    cout << sol.doesAliceWin(s);
    return 0;
}