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

//最长连续序列
/*class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> un_set;
        for(auto e:nums)
        {
            un_set.insert(e);
        }

        int longestStreak=0;
        for(const int& num:un_set)
        {
            if(!un_set.count(num-1))
            {
                int currentNum=num;
                int currentStreak=1;
                while(un_set.count(currentNum+1))
                {
                    currentNum+=1;
                    currentStreak+=1;
                }
                longestStreak=max(longestStreak,currentStreak);
            }
            
        }

        return longestStreak;
    }
};*/

//移动零
/*class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int right=0;
        while(right<n)
        {
            if(nums[right])
            {
                swap(nums[right],nums[left]);
                left++;
            }
            right++;
        }
    }
};*/

//盛最多水的容器
/*class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int ans=0;
        while(l<r)
        {
            int area=min(height[l],height[r])*(r-l);
            ans=max(area,ans);
            if(height[l]<=height[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return ans;
    }
};*/
int main()
{

    return 0;
}
