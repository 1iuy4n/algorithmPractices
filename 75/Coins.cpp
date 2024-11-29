#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;


static const int MAX_N = 101, MAX_M = 100001;
int A[MAX_N], C[MAX_N];
int dp[MAX_M];
// vector<bool> dp(MAX_M, false); 傻逼vector超时

int main(){

    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, m;
    cin>>n>>m;
    while(n!=0 || m!=0){
        for(int i=1; i<=n; i++){
            cin>>A[i];
        }
        for(int i=1; i<=n; i++){
            cin>>C[i];
        }
        dp[0] = true;
        for(int i=1; i<=n; i++){
            if(C[i]==1){
                for(int j=m; j>=A[i]; j--){
                    dp[j] = dp[j] || dp[j-A[i]];
                }
            } else if(C[i]*A[i]<=m){
                for(int mod=0; mod < min(A[i], m); mod++){
                    int cnt=0;
                    for(int j=m-mod, len=0; len<=C[i] && j>=0; len++, j-=A[i]){
                        if(dp[j]){
                            cnt++;
                        }
                    }

                    for(int j=m-mod, enter=j-A[i]*(C[i]+1); j>=1; j-=A[i], enter-=A[i]){
                        if(!dp[j]){
                            if(cnt!=0){
                                dp[j] = true;
                            }
                        } else{
                            cnt--;
                        }
                        if(enter>=0){
                            if(dp[enter]){
                                cnt++;
                            }
                        }
                    }
                }
            } else if(C[i]*A[i]>m){
                for(int j=A[i]; j<=m; j++){
                    dp[j] = dp[j] || dp[j-A[i]];
                }
            }
        }
        int ans = 0;
        for(int j=1; j<=m; j++){
            // cout<<dp[j]<<" ";
            if(dp[j]){
                ans++;
            }
            dp[j] = false; //clear array
        }
        cout<<ans<<"\n";
        cin>>n>>m;

    }
    
    return 0;
}