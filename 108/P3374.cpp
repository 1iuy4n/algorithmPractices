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

class treeArray{
public:
    static const int MAXN = 5e5+1;
    int n;
    int nums[MAXN];

    treeArray(int n_) : n(n_){
        for(int i=0; i<MAXN; i++){
            nums[i] = 0;
        }
    }
    int getLowBit(int num){
        return num & (-num);
    }
    void add(int index, int value){
        while(index<=n){
            nums[index] += value;
            index += getLowBit(index);
        }
    }
    int sum(int index){
        int ans = 0;
        while(index>0){
            ans += nums[index];
            index -= getLowBit(index);
        }
        return ans;
    }
    int range(int l, int r){
        return sum(r)-sum(l-1);
    }
};

int main(){
    
    int n, m, num;
    cin>>n>>m;
    treeArray res(n);
    for(int i=1; i<=n; i++){
        cin>>num;
        res.add(i, num);
    }
    int op, index, value, l, r;
    for(int i=0; i<m; i++){
        cin>>op;
        if(op==1){
            cin>>index>>value;
            res.add(index, value);
        } else{
            cin>>l>>r;
            cout<<res.range(l, r)<<"\n";
        }
    }
    
    return 0;
}