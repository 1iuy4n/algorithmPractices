#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int arr[100005];
int help[100005];

void Merge(int l, int m, int r){
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
    Merge(l, m, r);
}

void d(int l, int r){
    int i=0;
    int step = 1;
    while(step<r){
        for(i=0; i<r; i+=step<<1){
            int m = i+step;
            int j = min(m+step, r);
            cout<<i<<" "<<m<<" "<<j<<"\n";
            Merge(i, m, j);
        }
        step <<= 1;
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("./P1177_2.in","r",stdin);
	freopen(".out","w",stdout);
    int N;
    int i;
    cin>>N;
    for(i=0; i<N; i++) cin>>arr[i];
    // f(0, N);
    d(0, N);
    cout<<"hello";
    for(i=0; i<N; i++) cout<<arr[i]<<" ";

    return 0;
}


/*
4
4 3 5 8
*/