#include<bits/stdc++.h>
using namespace std;

// we can use the property of xor to find the two unique numbers in the array. we can xor all the elements in the array to get the xor of the two unique numbers. then we can find the rightmost set bit in the xor result to divide the numbers into two groups. one group will have the rightmost set bit and the other group will not have the rightmost set bit. then we can xor all the numbers in each group to get the two unique numbers.

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        int a=0;
        for(int i=0;i<n;i++){
            a^=nums[i];
        }
        int idx=0;
        while(a){
            if(a&1) break;
            idx++;
            a>>=1;
        }
        a=0;
        int b=0;
        for(int i=0;i<n;i++){
            if((nums[i]>>idx)&1){
                a^=nums[i];
            }
            else{
                b^=nums[i];
            }
        }
        return {a,b};
    }
};