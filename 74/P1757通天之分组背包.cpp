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

static const int MAX_N = 1001;
vector<vector<int> > values(MAX_N);
vector<vector<int> > weights(MAX_N);

vector<vector<int> > dp(MAX_N, vector<int>(MAX_N, 0));

int main(){
    
    int m, n, a, b, c;
    cin>>m>>n;
    for(int i=0; i<n; i++){
        cin>>a>>b>>c;
        weights[c].push_back(a);
        values[c].push_back(b);
    }

    int pre = 0;
    for(int i=1; i<=n; i++){
        bool flag = false;
        for(int j=1; j<=m; j++){
            dp[i][j] = dp[pre][j];
            for(int k=0; k<values[i].size(); k++){
                // cout<<values[i].size()<<",";
                if(j>=weights[i][k]){
                    dp[i][j] = max(dp[i][j], dp[pre][j-weights[i][k]]+values[i][k]);
                }
                flag = true;
            }
        }
        if(flag){
            pre = i;
        }
    }
    cout<<dp[pre][m];

    
    return 0;
}