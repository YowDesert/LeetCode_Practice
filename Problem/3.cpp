// beat 83.21%

// class Solution
// {
// public:
//     int lengthOfLongestSubstring(string s)
//     {
//         unordered_map<char, int> charIndexMap; // 存儲字符的索引位置
//         int maxLength = 0;
//         int start = 0; // 滑動窗口的起始位置

//         for (int end = 0; end < s.size(); ++end)
//         {
//             // 如果字符已經在窗口內，更新窗口的起始位置
//             if (charIndexMap.find(s[end]) != charIndexMap.end())
//             {
//                 start = max(start, charIndexMap[s[end]] + 1);
//             }
//             // 更新當前字符的索引
//             charIndexMap[s[end]] = end;
//             // 計算當前窗口的長度並更新最大長度
//             maxLength = max(maxLength, end - start + 1);
//         }

//         return maxLength;
//     }
// };