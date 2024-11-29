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

static const int MAX_M = 4e4+1, MAX_N = 1e6;
// static const int MAX_M = 50, MAX_N = 20;
int prices[MAX_N];
int pricesSize = 0;
int values[MAX_N];
int valuesSize = 0;
int dp[MAX_M];

int main(){
    
    int n, W, v, w, m;
    cin>>n>>W;
    for(int i=0; i<n; i++){
        cin>>v>>w>>m;
        for(int k=1; m>=k; k<<=1){
            prices[pricesSize++] = w*k;
            values[valuesSize++] = v*k;
            m -= k;
        }
        if(m>0){
            prices[pricesSize++] = w*m;
            values[valuesSize++] = v*m;
        }
    }

    for(int i=1; i<=valuesSize; i++){
        for(int j=W; j>=prices[i-1]; j--){
            dp[j] = max(dp[j], dp[j-prices[i-1]]+values[i-1]);
        }
    }
    cout<<dp[W]<<endl;

    
    
    return 0;
}