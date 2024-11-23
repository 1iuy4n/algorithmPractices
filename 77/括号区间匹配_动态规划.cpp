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

const int MAX_N = 101;
int dp[MAX_N][MAX_N];

void build(){
    for(int i=0; i<MAX_N; i++){
        for(int j=0; j<MAX_N; j++){
            dp[i][j] = 0;
        }
    }
}
int main(){
    
    build();
    string s;
    cin>>s;
    int len = s.size();
    for(int i=0; i<len; i++){
        dp[i][i] = 1;
    }
    for(int l=len-1; l>=0; l--){
        for(int r = l+1; r<len; r++){
            int dp1=INT_MAX, dp2=INT_MAX;
            if((s[l]=='(' && s[r]==')') || (s[l]=='[' && s[r]==']')){
                dp1 = dp[l+1][r-1];
            }
            for(int m=l; m<r; m++){
                dp2 = min(dp2, dp[l][m]+dp[m+1][r]);
            }
            dp[l][r] = min(dp1, dp2);
        }
    }
    cout<<dp[0][len-1];
    
    return 0;
}