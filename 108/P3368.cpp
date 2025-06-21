#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <utility>
#include <set>
#include <stack>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;
using ll = long long;

const int MAXN = 5e5+5;
int n;
int nums[MAXN];
ll tree[MAXN];

int getLowOne(int i){
    return i & (-i);
}
void add(int i, int num){
    while(i <= n){
        tree[i] += num;
        i = i + getLowOne(i);
    }
}
ll getSum(int i){
    ll ans = 0;
    while(i>0){
        ans += tree[i];
        i = i - getLowOne(i);
    }
    return ans;
}
ll getSingle(int i){
    return getSum(i);
}
void build(){
    for(int i=0; i<MAXN; i++){
        tree[i] = 0;
        nums[i] = 0;
    }
}
int main(){
    build();
    int M;
    cin>>n>>M;
    for(int i=1; i<=n; i++){
        cin>>nums[i];
        add(i, nums[i]-nums[i-1]);
    }
    for(int i=0, op, x, y, k; i<M; i++){
        cin>>op;
        if(op==1){
            cin>>x>>y>>k;
            add(x, k);
            add(y+1, -k);
        } else{ 
            cin>>x;
            cout<<getSingle(x)<<"\n";
        }
    }
    
    return 0;
}
/*
5 5
1 5 4 2 3
1 2 4 2
2 3
1 1 5 -1
1 3 5 7
2 4
*/