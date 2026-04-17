#include<bits/stdc++.h>
using namespace std;

// first we can store the indices of each number in a map. then for each number in the array, we can find the mirror of that number and then find the indices of the mirror in the map and then find the minimum distance between the indices and the current index. we can use binary search to find the indices in log(n) time. with circular distance calculation. if there is no mirror for the number in the current index, then we can ignore that number.

class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<string,vector<int>> mp;
        int n=nums.size();
        int ans=INT_MAX;

        for(int i=0;i<n;i++){
            string a=to_string(nums[i]);
            mp[a].push_back(i);
        }

        for(int i=0;i<n;i++){
            string a=to_string(nums[i]);

            while(a.size()-1>=0 && a[a.size()-1]=='0'){
                a.pop_back();
            }

            reverse(a.begin(),a.end());

            if(mp.count(a)){
                auto &vec = mp[a];   

                auto it = upper_bound(vec.begin(), vec.end(), i);  

                if(it != vec.end())
                    ans = min(ans, abs(i - *it));

            }
        }

        if(ans==INT_MAX) return -1;
        return ans;
    }
};