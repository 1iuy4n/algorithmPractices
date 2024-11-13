#include <iostream>
#include <vector>
#include <utility>
#include <stack>

std::vector<std::vector<int>> mat(100, std::vector<int> (666, -1));

int main(){
    std::stack<std::pair<int, int>> s;
    std::vector<int> res;
    int i = 4;
    if(i>3){
        std::cout<<"i>3"<<std::endl;
    }
    else if(i>2){
        std::cout<<"i>2"<<std::endl;
    }
    else{
        std::cout<<"i>1"<<std::endl;
    }
    std::cout<<LLONG_MIN<<std::endl;
    return 0;
}