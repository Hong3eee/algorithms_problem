#include <cstdio>
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

int check[100001][2];
int dx[2] = {-1,1};
stack<int> st;

int n,k;

void bfs(int start)
{
	queue<int> q;
	q.push(start);
	check[start][0] = 1;
	check[start][1] = -1;

	while(!q.empty())
	{
		int x = q.front();
		q.pop();

		for(int i =0;i<2;i++)
		{
			int nx = x + dx[i];

			if(0<= nx && nx <= 100000)
			{
				if(check[nx][0] == 0)
				{
					check[nx][0] = check[x][0] + 1;
					check[nx][1] = x;
					q.push(nx);
				}
			}
		}

		int nx = 2 * x;

		if(0< nx && nx <= 100000 )
		{
			if(check[nx][0] == 0)
			{
				check[nx][0] = check[x][0] + 1;
				check[nx][1] = x;
				q.push(nx);
			}
		}


	}
	return ;
}

void solve(int k)
{
	if(k==-1)
		return;

	st.push(k);
	
	int prev = check[k][1];
	solve(prev);

	return ;
}

int main(){
	scanf("%d %d",&n,&k);

	bfs(n);
	/*
	   int ans = 987654321;
	   for(int i = 0 ; i<20 ; i++)
	   {
	   if(check[i][k] > 0)
	   ans = min(ans,check[i][k]);
	   }

	   printf("%d\n",ans -1);
	 */
	printf("%d\n",check[k][0]-1);

	for(int i=0;i<=k;i++)
		printf("%d ",check[i][0]);

	puts("");

	for(int i=0;i<=k;i++)
		printf("%d ",check[i][1]);

		

	
	solve(k);

	while(!st.empty())
	{
		printf("%d ",st.top());
		st.pop();
	}

	return 0;
}
