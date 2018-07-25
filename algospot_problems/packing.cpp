#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <stack>
using namespace std;

int d[101][1001];
string name[101];
int weight[101];
int value[101];

int main()
{
	int c;
	scanf("%d",&c);

	for(int z = 0; z<c;z++)
	{
		int n,w;
		scanf("%d %d",&n,&w);
		for(int i =1;i<=n;i++)
		{
			cin >> name[i];
			scanf("%d %d",&weight[i],&value[i]);
		}

		for(int i =1;i<=n;i++)			//전형적인 냅색 문제
			for(int j =1;j<=w;j++)
			{
				if( j - weight[i] < 0)
					d[i][j] = d[i-1][j];
				else
				{
					int select = d[i-1][j-weight[i]] + value[i];
					int notselect = d[i-1][j];

					d[i][j] = max(select,notselect);
				}
			}

		int cnt = 0;
		stack<int> item;

		int we= w;
		for(int i = n; i>0;i--)		// 가방에 들어가는 내용물 도출
		{
			if(d[i][we] != d[i-1][we])
			{
				cnt++;
				item.push(i);
				we -= weight[i];
			}

		}

		cout << d[n][w] << " " << cnt << endl;
		while(!item.empty()){
			cout << name[item.top()] << endl;
			item.pop();
		}
	}

	return 0;
}
