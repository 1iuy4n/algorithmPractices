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
            } else{
                return j+1<m && p[j+1]=='*' && f(s, p, i, j+2);
            }
        } else if(j==m){
            return false;
        } else{
            if(j+1<m && p[j+1]=='*'){
                if(p[j]==s[i] || p[j]=='.'){
                    return f(s, p, i+1, j) || f(s, p, i, j+2);
                } else{
                    return f(s, p, i, j+2);
                }
            } else{
                if(p[j]==s[i] || p[j]=='.'){
                    return f(s, p, i+1, j+1);
                } else{
                    return false;
                }
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
    int n, m;
    vector<vector<int> > dp = vector<vector<int> > (21, vector<int>(21, 0));
    bool f(string &s, string &p, int i, int j){
        if(i==n){
            if(j==m){
                return true;
            } else{
                return j+1<m && p[j+1]=='*' && f(s, p, i, j+2);
            }
        } else if(j==m){
            return false;
        } else{
            if(dp[i][j]==0){
                bool ans= false;
                if(j+1<m && p[j+1]=='*'){
                    if(p[j]==s[i] || p[j]=='.'){
                        ans = f(s, p, i+1, j) || f(s, p, i, j+2);
                    } else{
                        ans = f(s, p, i, j+2);
                    }
                } else{
                    if(p[j]==s[i] || p[j]=='.'){
                        ans = f(s, p, i+1, j+1);
                    }
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
    vector<vector<bool> > dp = vector<vector<bool> > (21, vector<bool>(21, false));
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        dp[n][m] = true;
        for(int j=m-1; j>=0; j--){
            dp[n][j] = j+1<m && p[j+1]=='*' && dp[n][j+2];
        }
        for(int i=n-1; i>=0; i--){
            for(int j=m; j>=0; j--){
                if(j+1<m && p[j+1]=='*'){
                    if(p[j]==s[i] || p[j]=='.'){
                        dp[i][j] = dp[i+1][j] || dp[i][j+2];
                    } else{
                        dp[i][j] = dp[i][j+2];
                    }
                } else{
                    if(p[j]==s[i] || p[j]=='.'){
                        dp[i][j] = dp[i+1][j+1];
                    } else{
                        dp[i][j] = false;
                    }
                }
            }
        }
        return dp[0][0];
    }
};





class Solution {
public:
    vector<bool> dp = vector<bool>(21, false);
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        dp[m] = true;
        for(int j=m-1; j>=0; j--){
            dp[j] = j+1<m && p[j+1]=='*' && dp[j+2];
        }
        for(int i=n-1; i>=0; i--){
            int pre=dp[m], curr;
            for(int j=m; j>=0; j--){
                curr = dp[j];
                if(j+1<m && p[j+1]=='*'){
                    if(p[j]==s[i] || p[j]=='.'){
                        dp[j] = dp[j] || dp[j+2];
                    } else{
                        dp[j] = dp[j+2];
                    }
                } else{
                    if(p[j]==s[i] || p[j]=='.'){
                        dp[j] = pre;
                    } else{
                        dp[j] = false;
                    }
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