#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <utility>
#include <set>
#include <stack>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;


class Solution1 {
public:
    static const int MAX_N = 305;
    int dp[MAX_N][MAX_N];
    void build(){
        for(int i=0; i<MAX_N; i++){
            for(int j=0; j<MAX_N; j++){
                dp[i][j] = -1;
            }
        }
    }
    int f(int l, int r, vector<int>&nums){
        if(l==r || l==r-1){
            return 0;
        }
        if(dp[l][r]==-1){
            int ans = INT_MIN;
            for(int m=l+1; m<r; m++){
                ans = max(ans, f(l, m, nums)+f(m, r, nums)+nums[m]*nums[l]*nums[r]);
            }
            dp[l][r] = ans;
        }
        return dp[l][r];
    }
    int maxCoins(vector<int>& nums) {
        build();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int len = nums.size(), ans = -1;
        for(int m=1; m<len-1; m++){
            ans = max(ans, f(0, m, nums)+f(m, len-1, nums)+nums[m]);
        }
        dp[0][len-1] = ans;
        for(int i=0; i<len; i++){
            for(int j=0; j<len; j++){
                // cout<<dp[i][j]<<" ";
                printf("%d\t", dp[i][j]);
            }
            // cout<<"\n";
            printf("\n");
        }
        return ans;
    }
};


class Solution {
public:
    static const int MAX_N = 305;
    int dp[MAX_N][MAX_N];
    void build(){
        for(int i=0; i<MAX_N; i++){
            for(int j=0; j<MAX_N; j++){
                dp[i][j] = 0;
            }
        }
    }
    int maxCoins(vector<int>& nums) {
        build();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int len = nums.size(), ans = -1;
        for(int l=len-1; l>=0; l--){
            for(int r=l+2; r<len; r++){
                int ans = -1;
                for(int m=l+1; m<r; m++){
                    ans = max(ans, dp[l][m]+dp[m][r]+nums[m]*nums[l]*nums[r]);
                }
                dp[l][r] = ans;
            }
        }
        // for(int i=0; i<len; i++){
        //     for(int j=0; j<len; j++){
        //         printf("%d\t", dp[i][j]);
        //     }
        //     printf("\n");
        // }
        return dp[0][len-1];
    }
};



int main(){
    
    
    
    return 0;
}