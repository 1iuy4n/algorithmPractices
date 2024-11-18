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


class Solution0 {
public:
    static const int MAX_N = 101;
    int dp[MAX_N][MAX_N];
    void build(){
        for(int i=0; i<MAX_N; i++){
            for(int j=0; j<MAX_N; j++){
                dp[i][j] = -1;
            }
        }
    }
    int f(int l, int r, int cutsL, int cutsR, vector<int>& cuts){
        if(cutsL==cutsR){
            return 0;
        }
        if(dp[cutsL][cutsR]==-1){
            int ans = INT_MAX;
            for(int m = cutsL; m<cutsR; m++){
                ans = min(ans, r-l+f(l, cuts[m], cutsL, m, cuts)+f(cuts[m], r, m+1, cutsR, cuts));
            }
            dp[cutsL][cutsR] = ans;
        }
        return dp[cutsL][cutsR];
    }
    int minCost(int n, vector<int>& cuts) {
        build();
        sort(cuts.begin(), cuts.end(), less<>());
        int ans = INT_MAX;
        for(int l=0, r=n, m=0; m <cuts.size(); m++){
            ans = min(ans, n+f(0, cuts[m], 0, m, cuts)+f(cuts[m], n, m+1, cuts.size(), cuts));
        }
        return ans;
    }
};


class Solution1 {
public:
    static const int MAX_N = 105;
    int dp[MAX_N][MAX_N];
    void build(){
        for(int i=0; i<MAX_N; i++){
            for(int j=0; j<MAX_N; j++){
                dp[i][j] = -1;
            }
        }
    }
    int f(int cutsL, int cutsR, vector<int>& cuts){
        if(cutsL==cutsR){
            return 0;
        }
        if(dp[cutsL][cutsR]==-1){
            int ans = INT_MAX;
            for(int m = cutsL; m<cutsR; m++){
                ans = min(ans, f(cutsL, m, cuts)+f(m+1, cutsR, cuts));
            }
            dp[cutsL][cutsR] = ans+cuts[cutsR]-cuts[cutsL-1];
        }
        return dp[cutsL][cutsR];
    }
    int minCost(int n, vector<int>& cuts) {
        build();
        sort(cuts.begin(), cuts.end(), less<>());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        int ans = INT_MAX;
        for(int l=0, r=n, m=1; m <cuts.size()-1; m++){
            ans = min(ans, f(1, m, cuts)+f(m+1, cuts.size()-1, cuts));
        }
        return ans+n;
    }
};


class Solution {
public:
    static const int MAX_N = 105;
    int dp[MAX_N][MAX_N];
    void build(){
        for(int i=0; i<MAX_N; i++){
            for(int j=0; j<MAX_N; j++){
                dp[i][j] = -1;
            }
        }
    }
    int f(int cutsL, int cutsR, vector<int>& cuts){
        if(cutsL==cutsR){
            return 0;
        }
        if(dp[cutsL][cutsR]==-1){
            int ans = INT_MAX;
            for(int m = cutsL; m<cutsR; m++){
                ans = min(ans, f(cutsL, m, cuts)+f(m+1, cutsR, cuts));
            }
            dp[cutsL][cutsR] = ans+cuts[cutsR]-cuts[cutsL-1];
        }
        return dp[cutsL][cutsR];
    }
    int minCost(int n, vector<int>& cuts) {
        build();
        sort(cuts.begin(), cuts.end(), less<>());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        int ans = INT_MAX;
        for(int l=0, r=n, m=1; m <cuts.size()-1; m++){
            ans = min(ans, f(1, m, cuts)+f(m+1, cuts.size()-1, cuts));
        }
        return ans+n;
    }
};


int main(){
    
    
    
    return 0;
}