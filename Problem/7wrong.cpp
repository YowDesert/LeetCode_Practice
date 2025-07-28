// #include <bits/stdc++.h>

// using namespace std;

// class Solution
// {
// public:
//     int reverse(int x)
//     {
//         bool minus = false;
//         if (x < 0)
//         {
//             minus = true;
//             x = abs(x);
//         }
//         string str = to_string(x);
//         string AnsStr;
//         for (int i = str.size() - 1; i >= 0; i--)
//         {
//             AnsStr.push_back(str[i]);
//         }

//         int LongNum = stoi(AnsStr);

//         minus ? LongNum *= -1 : LongNum;

//         if (!(LongNum >= pow(2, 31) * -1 && LongNum <= pow(2, 31) - 1))
//         {
//             return 0;
//         }
//         else
//         {
//             return LongNum;
//         }
//     }
// };