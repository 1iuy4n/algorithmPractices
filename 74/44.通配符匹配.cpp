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
    int n, m;
    bool f(string &s, string &p, int i, int j){
        if(i==n){
            if(j==m){
                return true;
            } else if(p[j]=='*'){
                return f(s, p, i, j+1);
            } else{
                return false;
            }
        } else if(j==m){
            return false;
        } else{
            if(p[j]=='*'){
                return f(s, p, i, j+1) || f(s, p, i+1, j);
            } else if(p[j]=='?' || s[i]==p[j]){
                return f(s, p, i+1, j+1);
            } else{
                return false;
            }
        }
    }
    bool isMatch(string s, string p) {
        n = s.size(), m = p.size();
        return f(s, p, 0, 0);
    }
};






class Solution2 {
public:
    static const int MAX_N = 2001;
    vector<vector<int> > dp = vector<vector<int> >(MAX_N, vector<int> (MAX_N, 0));
    int n, m;
    bool f(string &s, string &p, int i, int j){
        if(i==n){
            if(j==m){
                return true;
            } else if(p[j]=='*'){
                return f(s, p, i, j+1);
            } else{
                return false;
            }
        } else if(j==m){
            return false;
        } else{
            if(dp[i][j]==0){
                bool ans;
                if(p[j]=='*'){
                    ans = f(s, p, i, j+1) || f(s, p, i+1, j);
                } else if(p[j]=='?' || s[i]==p[j]){
                    ans = f(s, p, i+1, j+1);
                } else{
                    ans = false;
                }
                dp[i][j] = ans ? 1 : -1;
            }
            return dp[i][j]==1;
        }
    }
    bool isMatch(string s, string p) {
        n = s.size(), m = p.size();
        return f(s, p, 0, 0);
    }
};







class Solution3 {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool> > dp = vector<vector<bool> >(n+1, vector<bool> (m+1, false));
        dp[n][m] = true;
        for(int j=m-1; j>=0; j--){
            if(p[j]=='*'){
                dp[n][j] = dp[n][j+1];
            } else{
                dp[n][j] = false;
            }
        }
        for(int i=0; i<n; i++){
            dp[i][m] = false;
        }
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(p[j]=='*'){
                    dp[i][j] = dp[i][j+1] || dp[i+1][j];
                } else if(p[j]=='?' || s[i]==p[j]){
                    dp[i][j] = dp[i+1][j+1];
                } else{
                    dp[i][j] = false;
                }
            }
        }
        return dp[0][0];
    }
};



class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<bool> dp = vector<bool> (m+1, false);
        dp[m] = true;
        for(int j=m-1; j>=0; j--){
            if(p[j]=='*'){
                dp[j] = dp[j+1];
            } else{
                dp[j] = false;
            }
        }
        for(int i=n-1; i>=0; i--){
            int curr, pre = dp[m];
            dp[m] = false;
            for(int j=m-1; j>=0; j--){
                curr = dp[j];
                if(p[j]=='*'){
                    dp[j] = dp[j+1] || dp[j];
                } else if(p[j]=='?' || s[i]==p[j]){
                    dp[j] = pre;
                } else{
                    dp[j] = false;
                }
                pre = curr;
            }
        }
        return dp[0];
    }
};







int main(){
    
    
    
    return 0;
}