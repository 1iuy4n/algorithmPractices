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
    static const int MAXN = 10;
    int intDigits[MAXN];
    int dfs(int* intDigits, int len, int n, bool randSelect, bool alreadySelect, int index){
        if(index==0){
            if(alreadySelect){
                return 1;
            }
            return 0;
        }
        int ans = 0;
        if(alreadySelect){
            if(randSelect){
                for(int i=0; i<len; i++){
                    ans += dfs(intDigits, len, n, true, true, index-1);
                }
            } else{
                int currDigit = (n/(int)pow(10, index-1))%10;
                for(int i=0; i<len; i++){
                    if(intDigits[i] < currDigit){
                        ans += dfs(intDigits, len, n, true, true, index-1);
                    } else if(intDigits[i] == currDigit){
                        ans += dfs(intDigits, len, n, false, true, index-1);
                    } else{
                        break;
                    }
                }
            }
        } else{
            ans += dfs(intDigits, len, n, true, false, index-1);
            if(randSelect){
                for(int i=0; i<len; i++){
                    ans += dfs(intDigits, len, n, true, true, index-1);
                }
            } else{
                int currDigit = (n/(int)pow(10, index-1))%10;
                // cout<<index-1<<" "<<(int)pow(10, index-1)<<" "<<currDigit<<"\n";
                for(int i=0; i<len; i++){
                    if(intDigits[i] < currDigit){
                        ans += dfs(intDigits, len, n, true, true, index-1);
                    } else if(intDigits[i] == currDigit){
                        ans += dfs(intDigits, len, n, false, true, index-1);
                    } else{
                        break;
                    }
                }
            }
        }
        return ans;
    }
    int dfs0(int* intDigits, int len, int n, bool randSelect, bool alreadySelect, int index){
        if(index==0){
            if(alreadySelect){
                return 1;
            }
            return 0;
        }
        int ans = 0;
        if(randSelect){
            for(int i=0; i<len; i++){
                ans += dfs0(intDigits, len, n, true, true, index-1);
            }
        } else{
            int currDigit = (n/(int)pow(10, index-1))%10;
            for(int i=0; i<len; i++){
                if(intDigits[i] < currDigit){
                    ans += dfs0(intDigits, len, n, true, true, index-1);
                } else if(intDigits[i] == currDigit){
                    ans += dfs0(intDigits, len, n, false, true, index-1);
                } else{
                    break;
                }
            }
        }
        if(!alreadySelect){
            ans += dfs0(intDigits, len, n, true, false, index-1);
        }
        return ans;
    }
    int prepared[MAXN];
    int dfs1(int* intDigits, int len, int n, bool randSelect, bool alreadySelect, int index){
        if(index==0){
            if(alreadySelect){
                return 1;
            }
            return 0;
        }
        int ans = 0;
        if(randSelect){
            ans += prepared[index-1]*len;
        } else{
            int currDigit = (n/(int)pow(10, index-1))%10;
            for(int i=0; i<len; i++){
                if(intDigits[i] < currDigit){
                    ans += dfs1(intDigits, len, n, true, true, index-1);
                } else if(intDigits[i] == currDigit){
                    ans += dfs1(intDigits, len, n, false, true, index-1);
                } else{
                    break;
                }
            }
        }
        if(!alreadySelect){
            ans += dfs1(intDigits, len, n, true, false, index-1);
        }
        return ans;
    }
    int atMostNGivenDigitSet1(vector<string>& digits, int n) {
        int digitLen = 0, tmp = n;
        while(tmp>0){
            tmp /= 10;
            digitLen++;
        }
        int len = digits.size();
        for(int i=0; i<len; i++){
            intDigits[i] = digits[i][0]-'0';
        }
        prepared[0] = 1;
        for(int i=1; i<digitLen; i++){
            prepared[i] = prepared[i-1]*len;
        }
        return dfs1(intDigits, len, n, false, false, digitLen);
    }


    int dfs2(int* intDigits, int len, int n, int index){
        if(index==0){
            return 1;
        }
        int ans = 0;
        int currDigit = (n/(int)pow(10, index-1))%10;
        for(int i=0; i<len; i++){
            if(intDigits[i] < currDigit){
                ans += prepared[index-1];
            } else if(intDigits[i] == currDigit){
                ans += dfs2(intDigits, len, n, index-1);
            } else{
                break;
            }
        }
        return ans;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        int digitLen = 0, tmp = n;
        while(tmp>0){
            tmp /= 10;
            digitLen++;
        }
        int len = digits.size();
        for(int i=0; i<len; i++){
            intDigits[i] = digits[i][0]-'0';
        }
        prepared[0] = 1;
        int ans = 0;
        for(int i=1; i<digitLen; i++){
            prepared[i] = prepared[i-1]*len;
            ans += prepared[i];
        }
        return ans+dfs2(intDigits, len, n, digitLen);
    }
};



int main(){
    Solution test;
    vector<string> digits = {"1","3","5","7"};
    cout<<test.atMostNGivenDigitSet(digits, 100);
    
    
    return 0;
}