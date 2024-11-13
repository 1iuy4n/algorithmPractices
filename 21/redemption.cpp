#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int arr[100005];
int help[100005];
int N;

void Merge(int l, int m, int r){
    int i=l, j=m+1;
    int k=l;
    while(i<=m && j<=r){
        if(arr[i]<=arr[j]) help[k++] = arr[i++];
        else help[k++] = arr[j++];
    }
    // cout<<k;
    while(i<=m) help[k++] = arr[i++];
    while(j<=r) help[k++] = arr[j++];
    for(int i=l; i<=r; i++) arr[i] = help[i];
}

void dMerge(int l, int m, int r){
    int i=l, j=m;
    int k=l;
    while(i<m && j<r){
        if(arr[i]<=arr[j]) help[k++] = arr[i++];
        else help[k++] = arr[j++];
    }
    // cout<<k;
    while(i<m) help[k++] = arr[i++];
    while(j<r) help[k++] = arr[j++];
    for(int i=l; i<r; i++) arr[i] = help[i];
}

void f(int l, int r){
    if(l==r-1) return;
    int m = l+((r-l)>>1);
    // cout<<l<<" "<<m<<" "<<r<<"\n";
    f(l, m);
    f(m, r);
    dMerge(l, m, r);
}


void d(){
    // for(int l, r, m, step=1; step<N; step<<=1){
    //     l=0;
    //     while(l<N){
    //         m=l+step;
    //         if(m>=N) break;
    //         r = min(l+(step<<1), N);
    //         dMerge(l, m, r);
    //         l = r;

    //     }
    // }


    int i=0;
    int l, m, j, step=1;
    while(step<=N){
        for(i=0; i<N; i=j){
            m = i+step;
            if(m>=N) break;
            j = min(m+step, N);
            // cout<<i<<" "<<m<<" "<<j<<"\n";
            dMerge(i, m, j);
        }
        step <<= 1;
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    // freopen("./P1177_2.in","r",stdin);
	// freopen(".out","w",stdout);
    int i=0;
    cin>>N;
    for(i=0; i<N; i++) cin>>arr[i];
    // f(0, N);
    d();
    for(i=0; i<N; i++) cout<<arr[i]<<" ";

    return 0;
}


/*
6
4 3 5 8 1 9
*/