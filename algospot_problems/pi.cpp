#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

string s;
int d[10000];

int check(int start, int end){

	for(int i =start ; i <end;)	//  난이도 1
	{
		if(s[i] == s[i+1])
			i++;
		else
			break;

		if(i == end)
			return 1;
	}

	int diff = s[start+1] - s[start];
	bool issamediff = true;

	for(int i =start ; i <end;i++)	//  난이도 2,5구분
	{
		if(s[i+1] - s[i] == diff) continue;
		else issamediff = false;
	}

	if(issamediff && (diff == 1 || diff == -1))
		return 2;

	bool isrepeat = true;
	for(int i =start ; i <= end;i++)	//  난이도 4
	{
		if(i%2 == start % 2)
		{
			if(s[start] == s[i]) continue;
			isrepeat = false;
			break;
		}
		else
		{
			if(s[start+1] == s[i]) continue;
			isrepeat = false;
			break;
		}
	}

	if(isrepeat) return 4;

	if(issamediff) return 5;

	return 10;	// 나머지 10
}

int memo(int start)
{
	if(start == s.size()) return 0;
	int& ret = d[start];
	if(ret != -1) return ret;
	
	ret = 10000000;

	for(int i = 3 ; i<=5;i++)
		if(start + i <= s.size())
			ret = min(ret , memo(start + i ) + check( start , start + i - 1));

	return ret;


}

int d2[10000];

int main(){
	int c;
	scanf("%d",&c);

	for(int i = 0; i<c;i++)
	{
		memset(d,-1,sizeof(d));
		memset(d2,-1,sizeof(d2));

		cin >> s;

		d2[2] = check(0,2);
		d2[3] = check(0,3);
		d2[4] = check(0,4);

		for(int end=5; end < s.size(); end++)
		{
			int tmp = 1000000;
			for(int j = 3;j<=5;j++)
			{
				if(d2[end-j] != -1)
					tmp = min(tmp,d2[end-j]+ check(end-j+1,end));
			}
			d2[end] = tmp;
		}
		cout << d2[s.size()-1] << endl;
		
//		cout << memo(0) <<endl;
	}

	return 0;
}
