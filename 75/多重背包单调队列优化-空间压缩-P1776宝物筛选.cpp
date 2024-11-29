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


static const int MAX_N = 101, MAX_M = 4e4+1;
int nums[MAX_N][3];
int Stack[MAX_M];
int dp[MAX_M];

int main(){
    
    int n, m;
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        // [0]是价值
        // [1]是重量
        // [2]是数量
        cin>>nums[i][0]>>nums[i][1]>>nums[i][2];
    }

    for(int i=1; i<=n; i++){
        for(int j=0; j<=min(m, nums[i][1]-1); j++){
            int l=0, r=0;
            for(int k=m-j, len=0; k>=0 && len<nums[i][2]; k-=nums[i][1], len++){
                while(l<r && dp[Stack[r-1]]-Stack[r-1]/nums[i][1]*nums[i][0]<=dp[k]-k/nums[i][1]*nums[i][0]){
                    r--;
                }
                Stack[r++] = k;
            }
            for(int k=m-j, enter = k-nums[i][1]*nums[i][2]; k>=0; k-=nums[i][1], enter-=nums[i][1]){
                if(enter>=0){
                    while(l<r && dp[Stack[r-1]]-Stack[r-1]/nums[i][1]*nums[i][0]<=dp[enter]-enter/nums[i][1]*nums[i][0]){
                        r--;
                    }
                    Stack[r++] = enter;
                }
                dp[k] = dp[Stack[l]]-Stack[l]/nums[i][1]*nums[i][0]+k/nums[i][1]*nums[i][0];
                if(Stack[l]==k){
                    l++;
                }
            }
        }
    }
    cout<<dp[m];

    
    return 0;
}