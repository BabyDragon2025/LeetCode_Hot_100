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

//三数之和
/*class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            if(i>=1 &&nums[i]==nums[i-1])
            {
                continue;
            }
            int l=i+1;
            int r=n-1;
            int target=-nums[i];
            while(l<r)
            {
                if(nums[l]+nums[r]==target)
                {
                    ans.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                    while(l<r&&nums[l]==nums[l-1])
                    {
                        l++;
                    }
                    while(l<r&&nums[r]==nums[r+1])
                    {
                        r--;
                    }
                }
                else if(nums[l]+nums[r]<target)
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
        }
        return ans;
    }
};*/

//接雨水
/*class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n==0)
        {
            return 0;
        }
        vector<int> LeftMax(n);
        LeftMax[0]=height[0];;
        for(int i=1;i<n;i++)
        {
            LeftMax[i]=max(LeftMax[i-1],height[i]);
        }

        vector<int> RightMax(n);
        RightMax[n-1]=height[n-1];;
        for(int i=n-2;i>=0;i--)
        {
            RightMax[i]=max(RightMax[i+1],height[i]);
        }

        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=min(LeftMax[i],RightMax[i])-height[i];
        }
        return ans;
    }
};*/


//无重复字符最长子串
/*
* class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> umap;
        int l=0;
        int res=0;
        int length=s.size();
        for(int r=0;r<length;r++)
        {
            if(umap.find(s[r])!=umap.end())
            {
                l=max(l,umap[s[r]]+1);
            }
            umap[s[r]]=r;
            res=max(res,r-l+1);
        }
        return res;
    }
};
*/


//找到字符串中所有字母异位词
/*
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size();
        unordered_map<char,int> umap1;
        unordered_map<char,int> umap2;
        vector<int> res;
        for(auto e:p)
        {
            umap1[e]++;
        }
        for(int l=0,r=0;r<n;r++)
        {
            umap2[s[r]]++;
            if(r-l+1>p.size())
            {
                if(umap2[s[l]]==1)
                {
                    umap2.erase(s[l]);
                }
                else
                {
                    umap2[s[l]]--;
                }
                l++;
            }
            if(umap1==umap2)
            {
                res.push_back(l);
            }
        }
        return res;
    }
};*/


//和为k的子数组
/*
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> v(n+1);
        for(int i=0;i<n;i++)
        {
            v[i+1]=v[i]+nums[i];
        }

        unordered_map<int,int> umap;
        int res=0;
        for(auto e:v)
        {
            res+=umap.count(e-k)?umap[e-k]:0;
            umap[e]++;
        }
        return res;
    }
};*/


//滑动窗口最大值
/*
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> q;

        for(int i=0;i<nums.size();i++)
        {
            while(!q.empty()&&nums[i]>=nums[q.back()])
            {
                q.pop_back();
            }
            q.push_back(i);
            while(!q.empty()&&q.front()<=i-k)
            {
                q.pop_front();
            }
            if(i>=k-1)
            {
                res.push_back(nums[q.front()]);
            }
        }
        return res;
    }
};*/



//最大子数组和
/*
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]>0)
            {
                nums[i]+=nums[i-1];
            }
            if(nums[i]>res)
            {
                res=nums[i];
            }
        }
        return res;
    }
};*/


//合并区间
/*
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res;
        int n=intervals.size();
    for(int i=0;i<n;i++)
    {
        int a=intervals[i][1];
        int t=i+1;
        while(t<n && a>=intervals[t][0])
        {
            a=max(a,intervals[t][1]);
            t++;
        }
        res.push_back({intervals[i][0],a});
        i=t-1;
    }
    return res;
    }
};*/

int main()
{

    return 0;
}
