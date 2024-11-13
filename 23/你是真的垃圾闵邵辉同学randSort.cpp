#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int N, a[100000+1], small[100000+1], big[100000+1], equalindex[100000+1];


void randSort(int l, int r){
    if(l>=r) return;
    srand(time(NULL));
    int index = l+(rand()%(r-l+1));

    int k = 0, j = 0, q = 0;
    for(int i=l ; i<=r; ++i){
        if(a[i]<a[index]) small[k++] = a[i];
        else if(a[i]>a[index]) big[j++] = a[i];
        else equalindex[q++] = a[i];
    }
    for(int i=0; i<k; ++i){
        a[i+l] = small[i];
    }
    for(int i=0; i<q; ++i){
        a[i+l+k] = equalindex[i];
    }
    for(int i=0; i<j; ++i){
        a[i+l+k+q] = big[i];
    }
    randSort(l, l+k-1);
    randSort(l+k+q, r);
}


int main(){

    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    // freopen("./P1177_1.in", "r", stdin);
    // freopen("./test.out", "w", stdout);

    cin>>N;
    for(int i=0; i<N; ++i){
        cin>>a[i];
    }

    randSort(0, N-1);

    for(int i=0; i<N; ++i){
        cout<<a[i]<<" ";
    }

    return 0;
}

/*
6
11 1 21 1 1 21

13
55350 4048105 4695482 9240070 9356701 9688173 9766431 11427455 11714081 12036223 13948398 13236856 13571641
*/