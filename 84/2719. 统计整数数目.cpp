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
    int getSum(string& num, int min_sum, int max_sum, int alreadySelect, int freeSelect, int index, int currSum){
        if(index==0){
            return alreadySelect;
        }
        int ans = 0;
        if(freeSelect){

        }
        return 0;
    }
    bool check(string& num1, int min_sum, int max_sum){
        return true;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        int ans = getSum(num2, min_sum, max_sum, 0, 0, 0, 0)-getSum(num1, min_sum, max_sum, 0, 0, 0, 0);
        if(check(num1, min_sum, max_sum)){
            ans += 1;
        }
        return ans;
    }
};


int main(){
    
    
    
    return 0;
}