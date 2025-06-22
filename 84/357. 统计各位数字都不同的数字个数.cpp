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
    int get(int n){
        if(n==0){
            return 1;
        }
        int ans = 9;
        for(int i=0; i<n-1; i++){
            ans *= (9-i);
        }
        return ans;
    }
    int countNumbersWithUniqueDigits(int n) {
        int ans = 0;
        for(int i=0; i<=min(8, n); i++){
            ans += get(i);
        }
        return ans;
    }
};


int main(){
    
    
    
    return 0;
}