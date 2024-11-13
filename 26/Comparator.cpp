
/*
java
	public static class EmployeeComparator implements Comparator<Employee> {

		@Override
		public int compare(Employee o1, Employee o2) {
			// 任何比较器都默认
			// 如果返回负数认为o1的优先级更高
			// 如果返回正数认为o2的优先级更高
			// 任何比较器都是这样，所以利用这个设定，可以定制优先级怎么确定，也就是怎么比较
			// 不再有大小的概念，就是优先级的概念
			return o1.age - o2.age;
		}

	}
*/

#include<iostream>
#include<algorithm>
using namespace std;


bool mycmp(int a, int b){
    // return a>b;
    return a<b;
}

int main(){ 
   
	int num[10] = { 
   6,5,9,1,2,8,7,3,4,0};
	sort(num, num+10, mycmp);
	for(int i=0;i<10;i++){ 
   
		cout<<num[i]<<" ";
	}//输出结果:9 8 7 6 5 4 3 2 1 0
	
	return 0;
	
}

/*
第二种bool使用方法
二进制函数，接受范围内的两个元素作为参数，并返回可转换为bool值的值。返回的值指示作为第一个参数传递的元素是否按照其定义的特定严格弱顺序排在第二个参数之前。
函数不能修改它的任何参数。
它可以是函数指针，也可以是函数对象


当返回为真的时候，第一个数字放前面
bool mycmp(int a, int b){
    if(a>b) return 1;
    return 0;
}
*/