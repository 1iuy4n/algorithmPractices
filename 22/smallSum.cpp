#include <iostream>
using namespace std;

int N;
int s[100001];
int help[100001];
long long ans=0;

void smallMerge(int l, int m, int r){
    int i=l, k=l, j=m+1;

    int res=0;
    for(j=m+1; j<=r; j++){
        // cout<<res;
        while(s[i]<=s[j] && i<=m){
            res += s[i];
            i++;
        }
        // cout<<res<<"\n";
        ans += res;
    }

    i=l, k=l, j=m+1;

    while(i<=m && j<=r){
        if(s[i]<=s[j]) help[k++]=s[i++];
        else help[k++]=s[j++];
    }
    while(i<=m) help[k++]=s[i++];
    while(j<=r) help[k++]=s[j++];
    for(i=l; i<=r; i++){
        s[i] = help[i];
    }
}

void f(int l, int r){
    if(l==r) return;
    int m = l+((r-l)>>1);
    f(l, m);
    f(m+1, r);
    smallMerge(l, m, r);
}



int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>N;
    for(int i=0; i<N; i++) cin>>s[i];
    f(0, N-1);
    // for(int i=0; i<N; i++) cout<<s[i]<<" ";
    printf("%lld", ans);
    return 0;
}
// 64 位输出请用 printf("%lld")

/*
6
1 3 5 2 4 6


1
1
*/