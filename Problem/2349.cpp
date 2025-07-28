#include <bits/stdc++.h>

using namespace std;

class NumberContainers
{
private:
    unordered_map<int, int> index_to_number;        // 存放 index -> number
    unordered_map<int, set<int>> number_to_indices; // 存放 number -> 所有 index（有序）

public:
    NumberContainers()
    {
        // 初始化：雖然 unordered_map 本身會自動初始化，但寫出來讓結構更清楚
        index_to_number = unordered_map<int, int>();
        number_to_indices = unordered_map<int, set<int>>();
    }

    void change(int index, int number)
    {
        // 若 index 已經存有數字，先移除舊數字的對應索引
        if (index_to_number.count(index))
        {
            int old_number = index_to_number[index];
            number_to_indices[old_number].erase(index);
            if (number_to_indices[old_number].empty())
            {
                number_to_indices.erase(old_number);
            }
        }

        // 更新數據
        index_to_number[index] = number;
        number_to_indices[number].insert(index);
    }

    int find(int number)
    {
        if (number_to_indices.count(number) && !number_to_indices[number].empty())
        {
            return *number_to_indices[number].begin(); // 回傳最小索引
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */