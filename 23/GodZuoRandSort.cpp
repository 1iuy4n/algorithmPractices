#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int N, a[100000], small[100000], big[100000], equalindex[100000];


/*
6
6 2 2 3 1 2
*/

void randSort(int l, int r){
    if(l>=r) return;

    // cout<<l<<" "<<r<<"\n";
    srand(time(NULL));
    int index = l+(rand()%(r-l+1));
    int base = a[index];
    // cout<<index<<"\n";
    // int index = l;
    int arraya=l, i=l, arrayb=r;
    while(i<=arrayb){
        if(a[i]<base){
            swap(a[i], a[arraya]);
            arraya++;
            i++;
        }
        else if(a[i]==base){
            i++;
        }
        else if(a[i]>base){
            swap(a[i], a[arrayb]);
            arrayb--;
        }
    }
    // for(int i=0; i<N; ++i){
    //     cout<<a[i]<<" ";
    // }
    // cout<<"\n";
    // cout<<arraya-1<<"\n";
    // cout<<l<<" "<<arraya-1<<" "<<arrayb+1<<" "<<r<<"\n";
    randSort(l, arraya-1);
    // return;
    randSort(arrayb+1, r);
}


/*
6 2 2 3 1 2
2 2 2 3 1 6
1 2 2 3 2 6
1 2 3 2 2 6

*/


int main(){

    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    // freopen("test.in", "r", stdin);

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
6 2 2 3 1 2

13
55350 4048105 4695482 9240070 9356701 9688173 9766431 11427455 11714081 12036223 13948398 13236856 13571641
*/