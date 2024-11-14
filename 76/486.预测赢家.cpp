#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
#include <utility>
#include <set>
#include <stack>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

typedef long long ll;



class Solution1 {
public:
    int f(vector<int>& nums, int l, int r){
        if(l==r){
            return nums[l];
        } else if(l==r-1){
            return max(nums[l], nums[r]);
        } else{
            int p1 = nums[l]+min(f(nums, l+2, r), f(nums, l+1, r-1));
            int p2 = nums[r]+min(f(nums, l, r-2), f(nums, l+1, r-1));
            return max(p1, p2);
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        int numSum = 0, len = nums.size();
        for(int num:nums){
            numSum += num;
        }
        int player1score = f(nums, 0, len-1);
        return numSum <= 2*player1score;
    }
};

class Solution2 {
public:
    static const int MAX_N = 21;
    int dp[MAX_N][MAX_N];
    void build(){
        for(int i=0; i<MAX_N; i++){
            for(int j=0; j<MAX_N; j++){
                dp[i][j] = -1;
            }
        }
    }
    int f(vector<int>& nums, int l, int r){
        if(l==r){
            return nums[l];
        } else if(l==r-1){
            return max(nums[l], nums[r]);
        } else{
            if(dp[l][r]==-1){
                int p1 = nums[l]+min(f(nums, l+2, r), f(nums, l+1, r-1));
                int p2 = nums[r]+min(f(nums, l, r-2), f(nums, l+1, r-1));
                dp[l][r] = max(p1, p2);
            }
            return dp[l][r];
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        build();
        int numSum = 0, len = nums.size();
        for(int num:nums){
            numSum += num;
        }
        int player1score = f(nums, 0, len-1);
        return numSum <= 2*player1score;
    }
};


class Solution3 {
public:
    static const int MAX_N = 21;
    int dp[MAX_N][MAX_N];
    bool predictTheWinner(vector<int>& nums) {
        int numSum = 0, len = nums.size();
        for(int num:nums){
            numSum += num;
        }
        for(int i=0; i<len; i++){
            dp[i][i] = nums[i];
        }
        for(int l=len-1; l>=0; l--){
            for(int r=l+1; r<len; r++){
                if(l+1==r){
                    dp[l][r] = max(nums[l], nums[r]);
                } else{
                    dp[l][r] = max(nums[l]+min(dp[l+2][r], dp[l+1][r-1]), nums[r]+min(dp[l][r-2], dp[l+1][r-1]));
                }
            }
        }
        return numSum <= 2*dp[0][len-1];
    }
};


int main(){
    
    
    
    return 0;
}