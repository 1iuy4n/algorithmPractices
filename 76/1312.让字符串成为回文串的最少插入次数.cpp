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
    int f(string &s, int l, int r){
        if(l>=r){
            return 0;
        }
        if(s[l]==s[r]){
            return f(s, l+1, r-1);
        } else{
            return min(f(s, l+1, r), f(s, l, r-1))+1;
        }
    }
    int minInsertions(string s) {
        return f(s, 0, s.size()-1);
    }
};


class Solution2 {
public:
    static const int MAX_N = 501;
    int dp[MAX_N][MAX_N];
    void build(){
        for(int i=0; i<MAX_N; i++){
            for(int j=0; j<MAX_N; j++){
                dp[i][j] = -1;
            }
        }
    }
    int f(string &s, int l, int r){
        if(l>=r){
            return 0;
        }
        if(dp[l][r]==-1){
            if(s[l]==s[r]){
                dp[l][r] = f(s, l+1, r-1);
            } else{
                dp[l][r] = min(f(s, l+1, r), f(s, l, r-1))+1;
            }
        }
        return dp[l][r];
    }
    int minInsertions(string s) {
        build();
        return f(s, 0, s.size()-1);
    }
};


class Solution3 {
public:
    static const int MAX_N = 501;
    int dp[MAX_N][MAX_N];
    void build(){
        for(int i=0; i<MAX_N; i++){
            for(int j=0; j<MAX_N; j++){
                dp[i][j] = 0;
            }
        }
    }
    int minInsertions(string s) {
        build();
        int n = s.size();
        for(int i=0; i<n-1; i++){
            dp[i][i+1] = s[i]==s[i+1] ? 0 : 1;
        }
        for(int i=n-2; i>=0; i--){
            for(int j=i+1; j<n; j++){
                if(s[i]==s[j]){
                    dp[i][j] = dp[i+1][j-1];
                } else{
                    dp[i][j] = min(dp[i+1][j], dp[i][j-1])+1;
                }
            }
        }
        return dp[0][n-1];
    }
};


class Solution {
public:
    static const int MAX_N = 501;
    int dp[MAX_N];
    void build(){
        for(int j=0; j<MAX_N; j++){
            dp[j] = 0;
        }
    }
    int minInsertions(string s) {
        build();
        int n = s.size();
        dp[n-1] = 0;
        for(int i=n-2; i>=0; i--){
            int pre = 0, curr;
            dp[i] = 0;
            for(int j=i+1; j<n; j++){
                curr = dp[j];
                if(s[i]==s[j]){
                    dp[j] = pre;
                } else{
                    dp[j] = min(dp[j], dp[j-1])+1;
                }
                pre = curr;
            }
        }   
        return dp[n-1];
    }
};


int main(){
    
    
    
    return 0;
}