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


class solve1{
private:
    static const int MAX_N = 51;
    int dp[MAX_N][MAX_N];
public:
    void build(){
        for(int i=0; i<MAX_N; i++){
            for(int j=0; j<MAX_N; j++){
                dp[i][j] = -1;
            }
        }
    }
    int f(string &s, int l, int r){
        if(l==r){
            return 1;
        }
        if(dp[l][r]==-1){
            if(s[l]==s[r]){
                dp[l][r] = min(f(s, l+1, r),f(s, l, r-1));
            } else{
                int ans = INT_MAX;
                for(int m=l; m<r; m++){
                    ans = min(f(s, l, m)+f(s, m+1, r), ans);
                }
                dp[l][r] = ans;
            }
        }
        return dp[l][r];
    }
    int test(string &s){
        build();
        int n = s.size();
        return f(s, 0, n-1);   
    }
};


class solve{
private:
    static const int MAX_N = 51;
    int dp[MAX_N][MAX_N];
public:
    void build(){
        for(int i=0; i<MAX_N; i++){
            for(int j=0; j<MAX_N; j++){
                dp[i][j] = 1;
            }
        }
    }
    int test(string &s){
        build();
        int n = s.size();
        for(int l=n-1; l>=0; l--){
            for(int r=l+1; r<n; r++){
                if(s[l]==s[r]){
                    dp[l][r] = min(dp[l+1][r], dp[l][r-1]);
                } else{
                    int ans = INT_MAX;
                    for(int m=l; m<r; m++){
                        ans = min(dp[l][m]+dp[m+1][r], ans);
                    }
                    dp[l][r] = ans;
                }
            }
        }
        return dp[0][n-1];   
    }
};



int main(){
    
    string s;
    cin>>s;
    solve getflag;
    cout<<getflag.test(s);
    
    return 0;
}