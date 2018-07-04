#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int str_index;

string reverse(string array){
	int tmp_index = str_index;
	char c = array.at(str_index);
	str_index++;

	if(c == 'b' || c == 'w')
		return array.substr(tmp_index,1);

	string NW = reverse(array);
	string NE = reverse(array);
	string SW = reverse(array);
	string SE = reverse(array);
 
	return string("x") + SW + SE + NW + NE;
}

int main()
{
	int c;
	scanf("%d",&c);

	for(int i =0;i<c;i++)
	{
		string s;
		cin >> s;
		cout << reverse(s) << endl;
		str_index = 0;
	}

	return 0;
}
