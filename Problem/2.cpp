// #include <bits/stdc++.h>
// using namespace std;

// class Solution
// {
// public:
//     ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
//     {
//         ListNode *dummyHead = new ListNode(0); // 虛擬頭節點
//         ListNode *current = dummyHead;
//         int carry = 0; // 進位

//         while (l1 != nullptr || l2 != nullptr || carry != 0)
//         {
//             int x = (l1 != nullptr) ? l1->val : 0;
//             int y = (l2 != nullptr) ? l2->val : 0;
//             int sum = x + y + carry;

//             carry = sum / 10;                       // 計算進位
//             current->next = new ListNode(sum % 10); // 建立新節點
//             current = current->next;

//             if (l1 != nullptr)
//                 l1 = l1->next;
//             if (l2 != nullptr)
//                 l2 = l2->next;
//         }

//         return dummyHead->next; // 返回頭節點的下一個節點
//     }
// };
