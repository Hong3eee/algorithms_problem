#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(){

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(5);
	v.push_back(4);

	vector<int>::iterator it;

	it =v.begin();
	cout << it[3];<< endl; // []연산을 통해 임의 접근	

	for (it=v.begin();it!=v.end();++it) {
		printf("%d\n",*it);
	}
/*
	for(vector<Student_info>::const_iterator iter = students.begin(); 
			iter != students.end(); ++iter) 	// 구조체, 멤버 접근
	{     
		cout<< (*iter).name <<endl; 
		cout<< iter->name <<endl; 
	}
*/
	return 0;
}
