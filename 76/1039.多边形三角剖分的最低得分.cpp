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
    int f(vector<int> & values, int l, int r){
        if(l==r-1){
            return 0;
        } else if(l==r-2){
            return values[l]*values[l+1]*values[r];
        } else{
            int ans = INT_MAX;
            for(int m=l+1; m<r; m++){
                ans = min(f(values, l, m)+f(values, m, r)+values[l]*values[m]*values[r], ans);
            }
            return ans;
        }
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        return f(values, 0, n-1);
    }
};


class Solution2 {
public:
    static const int MAX_N = 51;
    int dp[MAX_N][MAX_N];
    void build(){
        for(int i=0; i<MAX_N; i++){
            for(int j=0; j<MAX_N; j++){
                dp[i][j] = -1;
            }
        }
    }
    int f(vector<int> & values, int l, int r){
        if(l==r-1){
            return 0;
        } else if(l==r-2){
            return values[l]*values[l+1]*values[r];
        } else{
            if(dp[l][r]==-1){
                int ans = INT_MAX;
                for(int m=l+1; m<r; m++){
                    ans = min(f(values, l, m)+f(values, m, r)+values[l]*values[m]*values[r], ans);
                }
                dp[l][r] =  ans;
            }
            return dp[l][r];
        }
    }
    int minScoreTriangulation(vector<int>& values) {
        build();
        int n = values.size();
        return f(values, 0, n-1);
    }
};



class Solution {
public:
    static const int MAX_N = 51;
    int dp[MAX_N][MAX_N];
    void build(){
        for(int i=0; i<MAX_N; i++){
            for(int j=0; j<MAX_N; j++){
                dp[i][j] = -1;
            }
        }
    }
    int f(vector<int> & values, int l, int r){
        if(l==r-1){
            return 0;
        } else if(l==r-2){
            return values[l]*values[l+1]*values[r];
        } else{
            if(dp[l][r]==-1){
                int ans = INT_MAX;
                for(int m=l+1; m<r; m++){
                    ans = min(f(values, l, m)+f(values, m, r)+values[l]*values[m]*values[r], ans);
                }
                dp[l][r] =  ans;
            }
            return dp[l][r];
        }
    }
    int minScoreTriangulation(vector<int>& values) {
        build();
        int n = values.size();
        for(int l=0; l<n-1; l++){
            dp[l][l+1] = 0;
        }
        for(int l=0; l<n-1; l++){
            for(int r = l+2; r<n; r++){
                dp[l][r] = values[l]*values[l+1]*values[r];
                for(int m = l+1; m<r; m++){
                    dp[l][r] = min(dp[l][m]+dp[m][r]+values[l]*values[m]*values[r])
                }
            }
        }
        return f(values, 0, n-1);
    }
};


int main(){
    
    
    
    return 0;
}