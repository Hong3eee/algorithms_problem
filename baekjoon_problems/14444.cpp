#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int d[100000] ={1,};
int main()
{

	string s;
	cin >> s;
	int len = s.size();

	for(int  k=1;k<len;k++)
	{
		//팰린드롬의 길이가 홀수일 때
		int l = k-1;
		int h = k+1;
		int ans = 1;
		while(l >= 0 && h <= len-1 ){
			if(s[l] == s[h]){
				ans += 2;
				l--;
				h++;
			}
			else
				break;
		}


		//팰린드롬의 길이가 짝수일 때
		l = k-1;
		h = k;
		int ans2 = 0;
		while(l >= 0 && h <= len-1 ){
			if(s[l] == s[h]){
				ans2 += 2;
				l--;
				h++;
			}
			else
				break;
		}

		d[k] = max(ans,ans2);

	}

//	for(int i =0;i<len;i++)
//		printf("%d %d\n",i,d[i]);

	int val = 0;
	for(int i =0;i<len;i++)
		val = max(val,d[i]);

	printf("%d\n",val);

	return 0;
}
