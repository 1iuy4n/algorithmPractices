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


class Solution {
public:
    int f(int l, int r, int m, vector<int>&nums){
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int len = nums.size(), ans = -1;
        for(int m=1; m<len-1; m++){
            ans = max(ans, f(1, 1, m, nums));
        }
    }
};





int main(){
    
    
    
    return 0;
}