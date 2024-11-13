#include <iostream>

using namespace std;

int a[100000];
int n;


// i位置的数，向下调整大根堆
void heapify(int i, int size){
    int l = i*2+1;
    while(l < size){
        int best = l+1<size && a[l]<a[l+1] ? l+1 : l;
        best = a[best] > a[i] ? best : i;
        if(best==i) break;
        swap(a[best], a[i]);
        i = best;
        l = i*2+1;
    }
}

// i位置的数，向上调整大根堆
void heapInsert(int i){
    while(a[(i-1)/2]<a[i]){
        swap(a[(i-1)/2], a[i]);
        i = (i-1)/2;
    }
}

// 从顶到底建立大根堆
void heapSort1(){
    for(int i = 0; i < n; ++i){
        heapInsert(i);
    }
    int size = n;
    while(size>1){
        swap(a[0], a[--size]);
        heapify(0, size);
    }
}


// 从底到顶建立大根堆
void heapSort2(){
    int size = n;
    for(int i = n-1; i >= 0; --i){
        heapify(i, size);
    }
    while(size>1){
        swap(a[0], a[--size]);
        heapify(0, size);
    }
}

int main(){
    cin>>n;
    for(int i = 0; i < n; ++i){
        cin>>a[i];
    }
    // heapSort1();
    heapSort2();
    for(int i = 0; i < n; ++i){
        cout<<a[i]<<" ";
    }
    
    return 0;
}