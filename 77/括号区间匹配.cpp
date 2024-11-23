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
            dp[i][j] = -1;
        }
    }
}
int f(string &s, int l, int r){
    if(l>r){
        return 0;
    } else if(l==r){
        return 1;
    }
    if(dp[l][r]==-1){
        int dp1=INT_MAX, dp2=INT_MAX;
        if((s[l]=='(' && s[r]==')') || (s[l]=='[' && s[r]==']')){
            dp1 = f(s, l+1, r-1);
        }
        int ans = INT_MAX;
        for(int m=l; m<r; m++){
            ans = min(ans, f(s, l, m)+f(s, m+1, r));
        }
        dp2 = ans;
        dp[l][r] = min(dp1, dp2);
    }
    return dp[l][r];
}

int main(){
    
    build();
    string s;
    cin>>s;
    int len = s.size();
    int ans =  f(s, 0, len-1);
    cout<<ans;
    
    return 0;
}