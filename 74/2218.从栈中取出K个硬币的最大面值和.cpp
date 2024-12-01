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
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int> > values(n);
        vector<vector<int> > weights(n);
        for(int i=0; i<n; i++){
            int m = piles[i].size();
            for(int j=0, preValues=0, preWeights=0; j<min(m, k); j++){
                preValues += piles[i][j];
                preWeights += 1;
                values[i].push_back(preValues);
                weights[i].push_back(preWeights);
            }
        }

        vector<vector<int> > dp(n+1, vector<int>(k+1, 0));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=k; j++){
                dp[i][j] = dp[i-1][j];
                for(int m=0; m<values[i-1].size(); m++){
                    if(j>=weights[i-1][m]){
                        dp[i][j] = max(dp[i][j], dp[i-1][j-weights[i-1][m]]+values[i-1][m]);
                    }
                }
            }
        }
        return dp[n][k];
    }
};



class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();

        vector<int> dp(k+1, 0);
        for(int i=1; i<=n; i++){
            int r = piles[i-1].size();
            for(int j=1; j<min(r, k); j++){
                piles[i-1][j] += piles[i-1][j-1];
            }
            for(int j=k; j>=0; j--){
                for(int m=0; m<min(r, k); m++){
                    if(j>=m+1){
                        dp[j] = max(dp[j], dp[j-m-1]+piles[i-1][m]);
                    }
                }
            }
        }
        return dp[k];
    }
};





int main(){
    
    Solution test;
    vector<vector<int> > piles = {{1,100,3},{7,8,9}};
    int k=2;
    cout<<test.maxValueOfCoins(piles, k);
    
    return 0;
}