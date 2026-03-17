#include<iostream>
using namespace std;

//两数之和
/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0;
        int j = 0;
        for (i = 0; i < nums.size(); i++)
        {
            for (j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return { i,j };
                }
            }
        }
        return { i,j };
    }
};
*/

//字母异位词分组
/*
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (string& str : strs)
        {
            string key = str;
            sort(key.begin(), key.end());
            m[key].emplace_back(str);
        }
        vector<vector<string>> v;
        for (auto e = m.begin(); e != m.end(); e++)
        {
            v.emplace_back(e->second);
        }
        return v;
    }
};
*/

int main()
{

    return 0;
}
