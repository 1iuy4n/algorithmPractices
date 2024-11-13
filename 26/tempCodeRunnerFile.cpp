#include<iostream>
#include<map>
using namespace std;
int main()
{
	map<int,string> m1;
	m1[1]="ctx";
	m1[2]="cxt";
	m1[3]="txc";
	m1[10]="txt";
	m1[5]="666";
    m1[5]="404";
	map<int,string>::iterator it;
	for(it=m1.begin();it!=m1.end();it++)
	{
		cout<<it->first<<" "<<it->second<<"\n";
	}

    map<int, string>::iterator test;
    test = m1.find(51);

    if(test != m1.end()){
        cout<<test->first<<" "<<test->second<<endl;
    }
	//it->为Key，it->second为Value 
}
