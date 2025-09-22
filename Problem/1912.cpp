#include <bits/stdc++.h>
using namespace std;

// 用來唯一標識一部電影（某間店的一個拷貝）
struct MovieCopy
{
    int shop;
    int movie;
    int price;
};

// 比較器：用於每個 movie 的「未租清單」
struct UnrentedCmp
{
    bool operator()(const MovieCopy &a, const MovieCopy &b) const
    {
        if (a.price != b.price)
            return a.price < b.price; // 價格小的排前面
        return a.shop < b.shop;       // 同價 → shop 編號小的排前面
    }
};

// 比較器：用於「已租清單」
struct RentedCmp
{
    bool operator()(const MovieCopy &a, const MovieCopy &b) const
    {
        if (a.price != b.price)
            return a.price < b.price;
        if (a.shop != b.shop)
            return a.shop < b.shop;
        return a.movie < b.movie; // 最後才比 movie id
    }
};

class MovieRentingSystem
{
private:
    // 1. 快速查詢價格 (shop,movie) → price
    unordered_map<long long, int> priceMap;

    // 2. 每部電影的未租集合
    unordered_map<int, multiset<MovieCopy, UnrentedCmp>> unrented;

    // 3. 全部已租電影的集合
    multiset<MovieCopy, RentedCmp> rented;

    // 將 (shop, movie) 編成唯一 key
    long long encodeKey(int shop, int movie)
    {
        return ((long long)shop << 20) | movie;
    }

public:
    MovieRentingSystem(int n, vector<vector<int>> &entries)
    {
        // 初始化容器
        for (auto &e : entries)
        {
            int shop = e[0], movie = e[1], price = e[2];
            priceMap[encodeKey(shop, movie)] = price;
            unrented[movie].insert({shop, movie, price});
        }
    }

    vector<int> search(int movie)
    {
        // TODO:
        // 1. 在 unrented[movie] 找前 5 筆
        // 2. 取出 shop 編號放入 vector<int>
        // 3. 回傳
        vector<int> TopFiveShop;
        auto &ms = unrented[movie];
        int count = 0;
        for (auto it = ms.begin(); it != ms.end() && count < 5; ++it, ++count)
        {
            TopFiveShop.push_back(it->shop);
        }

        return TopFiveShop;
    }

    void rent(int shop, int movie)
    {
        // TODO:
        // 1. 找到對應的 MovieCopy
        // 2. 從 unrented[movie] 移除
        // 3. 插入 rented multiset
        int price = priceMap[encodeKey(shop, movie)];
        MovieCopy mc = {shop, movie, price};

        auto &ms = unrented[movie]; // 取得該 movie 的未租 multiset
        auto it = ms.find(mc);      // 在 multiset 裡尋找這個拷貝
        if (it != ms.end())
        {
            ms.erase(it);
        }

        rented.insert(mc);
    }

    void drop(int shop, int movie)
    {
        // TODO:
        // 1. 找到對應的 MovieCopy
        // 2. 從 rented multiset 移除
        // 3. 插回 unrented[movie]
        int price = priceMap[encodeKey(shop, movie)];
        MovieCopy mc = {shop, movie, price};

        // auto &ms = rented[movie];
        auto it = rented.find(mc);
        if (it != rented.end())
        {
            rented.erase(it);
        }

        unrented[movie].insert(mc);
    }

    vector<vector<int>> report()
    {
        // TODO:
        // 1. 從 rented multiset 取前 5 筆
        // 2. 每筆轉成 {shop, movie} 放入結果
        // 3. 回傳
        vector<vector<int>> result;
        int count = 0;
        for (auto it = rented.begin(); it != rented.end() && count < 5; ++it, ++count)
        {
            result.push_back({it->shop, it->movie});
        }
        return result;
    }
};
