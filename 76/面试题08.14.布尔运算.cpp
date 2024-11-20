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

// 记忆化搜索
class Solution1 {
public:
    static const int MAX_N = 50;
    int dp[MAX_N][MAX_N][2]; //0表示false，1表示true的数量
    void build(){
        for(int i=0; i<MAX_N; i++){
            for(int j=0; j<MAX_N; j++){
                dp[i][j][0] = -1;
                dp[i][j][1] = -1;
            }
        }
    }
    int f(int l, int r, int need, string &s){
        if(l==r){
            return need==s[l]-'0' ? 1 : 0;
        }
        if(dp[l][r][need]==-1){
            int ans = 0;
            if(need==1){
                for(int m=l+1; m<r; m+=2){
                    if(s[m]=='&'){
                        ans += f(l, m-1, 1, s)*f(m+1, r, 1, s);
                    } else if(s[m]=='|'){
                        ans += f(l, m-1, 1, s)*f(m+1, r, 1, s)+f(l, m-1, 0, s)*f(m+1, r, 1, s)+f(l, m-1, 1, s)*f(m+1, r, 0, s);
                    } else if(s[m]=='^'){
                        ans += f(l, m-1, 1, s)*f(m+1, r, 0, s)+f(l, m-1, 0, s)*f(m+1, r, 1, s);
                    }
                }
            } else{
                for(int m=l+1; m<r; m+=2){
                    if(s[m]=='&'){
                        ans += f(l, m-1, 1, s)*f(m+1, r, 0, s)+f(l, m-1, 0, s)*f(m+1, r, 0, s)+f(l, m-1, 0, s)*f(m+1, r, 1, s);
                    } else if(s[m]=='|'){
                        ans += f(l, m-1, 0, s)*f(m+1, r, 0, s);
                    } else if(s[m]=='^'){
                        ans += f(l, m-1, 1, s)*f(m+1, r, 1, s)+f(l, m-1, 0, s)*f(m+1, r, 0, s);
                    }
                }
            }
            dp[l][r][need] = ans;
        }
        return dp[l][r][need];
    }
    int countEval(string s, int result) {
        build();
        int len = s.size();
        return f(0, len-1, result, s);
    }
};


//动态规划
class Solution {
public:
    static const int MAX_N = 50;
    int dp[MAX_N][MAX_N][2]; //0表示false，1表示true的数量
    void build(){
        for(int i=0; i<MAX_N; i++){
            for(int j=0; j<MAX_N; j++){
                dp[i][j][0] = 0;
                dp[i][j][1] = 0;
            }
        }
    }
    int countEval(string s, int result) {
        build();
        int len = s.size();
        for(int i=0; i<len; i++){
            dp[i][i][0] = s[i]-'0'==0 ? 1 : 0;
            dp[i][i][1] = s[i]-'1'==0 ? 1 : 0;
        }
        for(int l = len-1; l>=0; l--){
            for(int r = l+1; r<len; r++){
                for(int m=l+1; m<r; m+=2){
                    if(s[m]=='&'){
                        dp[l][r][1] += dp[l][m-1][1]*dp[m+1][r][1];
                    } else if(s[m]=='|'){
                        dp[l][r][1] += dp[l][m-1][1]*dp[m+1][r][1]+dp[l][m-1][0]*dp[m+1][r][1]+dp[l][m-1][1]*dp[m+1][r][0];
                    } else if(s[m]=='^'){
                        dp[l][r][1] += dp[l][m-1][1]*dp[m+1][r][0]+dp[l][m-1][0]*dp[m+1][r][1];
                    }
                }
                for(int m=l+1; m<r; m+=2){
                    if(s[m]=='&'){
                        dp[l][r][0] += dp[l][m-1][1]*dp[m+1][r][0]+dp[l][m-1][0]*dp[m+1][r][0]+dp[l][m-1][0]*dp[m+1][r][1];
                    } else if(s[m]=='|'){
                        dp[l][r][0] += dp[l][m-1][0]*dp[m+1][r][0];
                    } else if(s[m]=='^'){
                        dp[l][r][0] += dp[l][m-1][1]*dp[m+1][r][1]+dp[l][m-1][0]*dp[m+1][r][0];
                    }
                }
            }
        }
        return dp[0][len-1][result];
    }
};

int main(){
    
    
    
    return 0;
}