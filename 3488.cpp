class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int,vector<int>> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        int m=queries.size();
        vector<int> ans(m,0);
        for(int i=0;i<m;i++){
            auto &it=mp[nums[queries[i]]];
            if(it.size()==1){
                ans[i]=-1;
            }
            else{
                int idx=queries[i];
                auto tt=lower_bound(it.begin(),it.end(),idx);
                int mn=INT_MAX;
                if(tt!=it.begin()){
                    mn=min(mn,abs(*(tt-1)-idx));
                }
                else{
                    int id=*prev(it.end());
                    mn=min(mn,n-id+idx);
                }
                if(tt!=prev(it.end())){
                    mn=min(mn,*(tt+1)-idx);
                }
                else{
                    mn=min(mn,n-*tt+*(it.begin()));
                }
                 ans[i]=mn;
            }
            
        }
        return ans;
    }
};