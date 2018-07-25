#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int d[101][10001];

int w[101];
int v[101];

int main(){

	int n,k;
	scanf("%d %d",&n,&k);

	for(int i = 1;i<=n;i++)
		scanf("%d %d",&w[i],&v[i]);


	for(int i =1;i<=n;i++)
		for(int j =1;j<=k;j++)
		{
			if(j - w[i] < 0)	//무게를 넘어간다면(선택하지 않을때와 같음)
				d[i][j] = d[i-1][j];
			else
			{
				int select = d[i-1][j-w[i]] + v[i] ; 
				// i 번째 아이템은 무조건 고를거야, 그 후 남는 공간 최대로 쓰는방법 더해줘, DP! 부분문제의 활용
				int notselect = d[i-1][j];

				d[i][j] = select > notselect ? select : notselect; //부분문제의 해결
			}
		}

	printf("%d\n",d[n][k]);

	return 0;
}
