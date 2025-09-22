#include <bits/stdc++.h>

using namespace std;

class FoodRatings
{
public:
    unordered_map<string, pair<string, int>> CountryFood;
    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
    {
        for (int i = 0; i < foods.size(); i++)
        {
            CountryFood.insert({foods[i], {cuisines[i], ratings[i]}});
        }
    }

    void changeRating(string food, int newRating)
    {
        CountryFood[food].second = newRating;
    }

    string highestRated(string cuisine)
    {
        int max = -1;
        string HigestFood;
        for (auto kv : CountryFood)
        {
            string cuisines = kv.second.first;
            int rating = kv.second.second;
            if (cuisines == cuisine)
            {
                if (rating >= max)
                {
                    max = rating;
                    HigestFood = kv.first;
                }
            }
        }

        return HigestFood;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */