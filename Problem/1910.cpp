#include <iostream>
#include <string>

using namespace std;
class Solution
{
public:
    string removeOccurrences(string s, string part)
    {
        int partLocation = s.find(part);
        while (partLocation > -1)
        {
            s.erase(partLocation, part.size());
            partLocation = s.find(part);
        }
        return s;
    }
};