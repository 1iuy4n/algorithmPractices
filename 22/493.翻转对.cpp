class Solution {
private:
    int help[50001];
    int res = 0;
public:
    void Merge(int l, int r, vector<int>& nums){
        int m=l+((r-l)>>1);
        int ans=0;
        for(int i=l,j=m+1; i<=m; i++){
            while(j<=r && (long long)nums[i]>2*(long long)nums[j]){
                j++;
                ans+=1;
            }
            res += ans;
        }
        int i=l, j=m+1, k=l;
        while(i<=m && j<=r){
            if(nums[i]<=nums[j]) help[k++]=nums[i++];
            else help[k++]=nums[j++];
        }
        while(i<=m) help[k++]=nums[i++];
        while(j<=r) help[k++]=nums[j++];
        for(i=l; i<=r; i++){
            nums[i] = help[i];
        }
    }
    void f(int l, int r, vector<int>& nums){
        if(l==r) return;
        int m = l+((r-l)>>1);
        f(l, m, nums);
        f(m+1, r, nums);
        Merge(l, r, nums);
    }

    int reversePairs(vector<int>& nums) {
        f(0, nums.size()-1,  nums);
        for(int i=0; i<nums.size(); i++){
            cout<<nums[i]<<" ";
        }
        return res;
    }
};