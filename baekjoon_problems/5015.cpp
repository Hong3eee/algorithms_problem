#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

string s,p;
int d[101][101];

bool match(int pi,int si){

	int& ret = d[pi][si];
	if(ret != -1) return ret;

	while( si < s.size() && pi < p.size())
	{
		if(s[si] == p[pi])
		{
			si++;
			pi++;
		}
		else
			break;
	}

	if(pi == p.size())
		return ret = ( si == s.size());

	if(p[pi] == '*')	//recursive
	{
		for(int jump = 0 ; (si + jump) <= s.size() ; jump++)
		{
			if(match(pi + 1,si+jump))
				 return ret = 1;
		}
	}

	return ret = 0 ;
}

int main(){

	cin >> p;
	int n;
	scanf("%d",&n);
	for(int i =0;i<n;i++)
	{
		cin >> s;
		memset(d,-1,sizeof(d));

		if(match(0,0))
			cout << s << endl;
	}
	return 0;
}
