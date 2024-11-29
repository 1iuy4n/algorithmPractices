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
#include <string>

using namespace std;

typedef long long ll;

static const int MAX_M = 1001, MAX_N = 100001;
// static const int MAX_M = 50, MAX_N = 20;
int prices[MAX_N];
int pricesSize = 0;
int values[MAX_N];
int valuesSize = 0;
int dp[MAX_M];

int getTime(string x){
    int ans = 0;
    string tmp;
    for(int i=0; i<x.size(); i++){
        if(x[i]==':'){
            ans += 60*stoi(tmp);
            tmp = "";
        } else{
            tmp += x[i];
        }
    }
    return ans+stoi(tmp);
}
int main(){
    
    string start, end;
    int n, t, c, p;
    cin>>start>>end>>n;
    int W = getTime(end)-getTime(start);
    // cout<<W<<"\n";
    for(int i=0; i<n; i++){
        cin>>t>>c>>p;
        int m;
        if(p==0){
            m = 1001;
        } else{
            m = p;
        }
        for(int k=1; m>=k; k<<=1){
            prices[pricesSize++] = t*k;
            values[valuesSize++] = c*k;
            m -= k;
        }
        if(m>0){
            prices[pricesSize++] = t*m;
            values[valuesSize++] = c*m;
        }
    }

    for(int i=1; i<=valuesSize; i++){
        for(int j=W; j>=prices[i-1]; j--){
            dp[j] = max(dp[j], dp[j-prices[i-1]]+values[i-1]);
        }
    }
    cout<<dp[W];
    
    return 0;
}