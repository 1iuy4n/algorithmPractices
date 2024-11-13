#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>


using namespace std;


int RandSelect(int l, int r, vector<int>& nums, int k){
    if(l>=r) return nums[l];
    srand(time(NULL));
    int index = l+(rand()%(r-l+1));
    int a = l, i = l, b = r, base = nums[index], ans;
    while(i<=b){
        if(nums[i]>base) swap(nums[i++], nums[a++]);
        else if(nums[i]==base) i++;
        else if(nums[i]<base) swap(nums[b--], nums[i]);
    }
    if(k-1<a) ans = RandSelect(l, a-1, nums, k);
    else if(k-1>b) ans = RandSelect(b+1, r, nums, k);
    else ans = base;
    return ans;
}

int findKthLargest(vector<int>& nums, int k) {
    return RandSelect(0, nums.size()-1, nums, k);
}


int main(){

    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    vector<int> res = {3,2,3,1,2,4,5,5,6};
    cout<<res[2]<<"\n";
    for(int i=0; i<res.size(); ++i){
        cout<<res[i]<<" ";
    }
    cout<<"\n";
    int test = findKthLargest(res, 4);
    cout<<"\n"<<test<<"\n";
    for(int i=0; i<res.size(); ++i){
        cout<<res[i]<<" ";
    }

    return 0;
}