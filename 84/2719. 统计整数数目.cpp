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

class Solution {
public:
    int mod = 1e9+7;
    static const int MAXN = 24, MAXM = 401;
    int dp[MAXN][2][2][MAXM];
    void build(){
        for(int i=0; i<MAXN; i++){
            for(int j=0; j<MAXM; j++){
                dp[i][0][0][j] = -1;
                dp[i][0][1][j] = -1;
                dp[i][1][0][j] = -1;
                dp[i][1][1][j] = -1;
            }
        }
    }
    int getSum(vector<int>& num, int min_sum, int max_sum, int alreadySelect, int freeSelect, int index, int currSum){
        if((currSum>max_sum) || (currSum+(num.size()-index)*9<min_sum)){
            return 0;
        }
        if(index == num.size()){
            return alreadySelect;
        }
        if(dp[index][alreadySelect][freeSelect][currSum] == -1){
            int ans = 0;
            if(alreadySelect==0){
                if(freeSelect==1){
                    for(int i=0; i<=9; i++){
                        ans = (ans + getSum(num, min_sum, max_sum, 1, 1, index+1, currSum+i))%mod;
                    }
                } else{
                    ans = (ans + getSum(num, min_sum, max_sum, 0, 1, index+1, currSum))%mod;
                    for(int i=1; i<num[index]; i++){
                        ans = (ans + getSum(num, min_sum, max_sum, 1, 1, index+1, currSum+i))%mod;
                    }
                    ans = (ans + getSum(num, min_sum, max_sum, 1, 0, index+1, currSum+num[index]))%mod;
                }
            } else{
                if(freeSelect==1){
                    for(int i=0; i<=9; i++){
                        ans = (ans + getSum(num, min_sum, max_sum, 1, 1, index+1, currSum+i))%mod;
                    }
                } else{
                    for(int i=0; i<num[index]; i++){
                        ans = (ans + getSum(num, min_sum, max_sum, 1, 1, index+1, currSum+i))%mod;
                    }
                    ans = (ans + getSum(num, min_sum, max_sum, 1, 0, index+1, currSum+num[index]))%mod;
                }
            }
            dp[index][alreadySelect][freeSelect][currSum] = ans;
        }
        return dp[index][alreadySelect][freeSelect][currSum];
    }
    int dp1[MAXN][2][MAXM];
    void build1(){
        for(int i=0; i<MAXN; i++){
            for(int j=0; j<MAXM; j++){
                dp1[i][0][j] = -1;
                dp1[i][1][j] = -1;
            }
        }
    }
    int getSum1(vector<int>& num, int min_sum, int max_sum, int freeSelect, int index, int currSum){
        if((currSum>max_sum) || (currSum+(num.size()-index)*9<min_sum)){
            return 0;
        }
        if(index == num.size()){
            return 1;
        }
        if(dp1[index][freeSelect][currSum] == -1){
            int ans = 0;
            if(freeSelect==1){
                for(int i=0; i<=9; i++){
                    ans = (ans + getSum1(num, min_sum, max_sum, 1, index+1, currSum+i))%mod;
                }
            } else{
                for(int i=0; i<num[index]; i++){
                    ans = (ans + getSum1(num, min_sum, max_sum, 1, index+1, currSum+i))%mod;
                }
                ans = (ans + getSum1(num, min_sum, max_sum, 0, index+1, currSum+num[index]))%mod;
            }
            dp1[index][freeSelect][currSum] = ans;
        }
        return dp1[index][freeSelect][currSum];
    }
    bool check(vector<int>& num1, int min_sum, int max_sum){
        int num1Sum = 0;
        for(int i=0; i<num1.size(); i++){
            num1Sum += num1[i];
        }
        return num1Sum>=min_sum && num1Sum<=max_sum;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        // preprocess[0] = 10;
        // for(int i=1; i<MAXN; i++){
        //     preprocess[i] = (10*preprocess[i-1])%mod;
        // }
        vector<int> int1(num1.size(), 0);
        vector<int> int2(num2.size(), 0);
        for(int i=0; i<num1.size(); i++){
            int1[i] = num1[i]-'0';
        }
        for(int i=0; i<num2.size(); i++){
            int2[i] = num2[i]-'0';
        }
        // build();
        build1();
        // int result2 = getSum(int2, min_sum, max_sum, 0, 0, 0, 0);
        int result2 = getSum1(int2, min_sum, max_sum, 0, 0, 0);
        // cout<<result2<<endl;
        // build();
        build1();
        // int result1 = getSum(int1, min_sum, max_sum, 0, 0, 0, 0);
        int result1 = getSum1(int1, min_sum, max_sum, 0, 0, 0);
        // cout<<result1<<endl;
        int ans = (result2-result1+mod)%mod;
        if(check(int1, min_sum, max_sum)){
            ans = (ans+1)%mod;
        }
        return ans;
    }
};

int main(){

    Solution test;
    string num1 = "7748704426";//4179205230
    string num2 = "7748704426";
    int min_sum = 8;
    int max_sum = 46;
    cout<<test.count(num1, num2, min_sum, max_sum);
    
    
    return 0;
}