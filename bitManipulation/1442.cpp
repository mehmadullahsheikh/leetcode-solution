#include<bits/stdc++.h>
using namespace std;

// we can use a prefix xor array to store the xor of the elements from the start to the current index. we can then iterate through all the pairs of indices (i, k) and check if the xor of the elements from i to k is 0. if it is 0, then we can count the number of triplets that can be formed with these indices. the number of triplets that can be formed with these indices is (k - i) because we can choose any index j such that i < j <= k to form a triplet (i, j, k).

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int cnt = 0;

        vector<int> preXor(n);
        preXor[0] = arr[0];

        for(int i = 1; i < n; i++){
            preXor[i] = arr[i] ^ preXor[i-1];
        }

        for(int i = 0; i < n; i++){
            for(int k = i + 1; k < n; k++){
                int xorVal = preXor[k] ^ (i > 0 ? preXor[i-1] : 0);

                if(xorVal == 0){
                    cnt += (k - i); 
                }
            }
        }

        return cnt;
    }
};