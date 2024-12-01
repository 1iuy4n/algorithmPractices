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

static const int MAX_M = 1e7+1, MAX_N = 10001;
ll dp[MAX_M];
int values[MAX_N], weights[MAX_N];

int main(){
    
    int m, n;
    cin>>m>>n;
    for(int i=0; i<n; i++){
        cin>>weights[i]>>values[i];
    }
    for(int i=1; i<=n; i++){
        for(int j=weights[i-1]; j<=m; j++){
            dp[j] = max(dp[j], dp[j-weights[i-1]]+values[i-1]);
        }
    }
    cout<<dp[m];
    
    return 0;
}