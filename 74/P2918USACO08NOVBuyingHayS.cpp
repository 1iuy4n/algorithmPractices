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


static const int MAX_M = 5e5+5000;
// static const int MAX_M = 1000;
int dp[MAX_M];
int prices[101], values[101];

void build(){
    for(int j=0; j<MAX_M; j++){
        dp[j] = INT_MAX;
    }
}

int main(){
    
    build();
    int n, m;
    cin>>n>>m;
    int maxH = 0;
    for(int i=0; i<n; i++){
        cin>>values[i]>>prices[i];
        maxH = max(maxH, values[i]);
    }
    int ans = INT_MAX;
    for(int i=1; i<=n; i++){
        dp[0] = 0;
        for(int j=1; j<=m+maxH; j++){
            if(j>=values[i-1] && dp[j-values[i-1]]!=INT_MAX){
                dp[j] = min(dp[j], dp[j-values[i-1]]+prices[i-1]);
                if(j>=m){
                    ans = min(ans, dp[j]);
                }
            }
        }
    }
    cout<<ans;
    
    
    
    return 0;
}