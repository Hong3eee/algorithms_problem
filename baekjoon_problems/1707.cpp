#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int check[20001];
vector<int> a[20001];

int dfs(int x,int color){ 
	check[x] = color;
	for(int i =0;i<a[x].size();i++){
		int y = a[x][i];
		if(check[y] == 0 )
		{
			if(dfs(y,3-color)==-1)
				return -1;
		}
		else if(check[x] == check[y])
			return -1;
	}   
	return 0;
}

int main(){
	int t,v,e;

	scanf("%d",&t);

	for(int z = 0 ; z<t;z++)
	{
		scanf("%d %d",&v,&e);
		for(int i =0; i<v; i++){
			a[i].clear();
			check[i] = 0;
		}

		for(int i =0; i<e ; i++){
			int x,y;
			scanf("%d %d",&x,&y);
			a[x].push_back(y);
			a[y].push_back(x);
		}
		int tmp = 0;

		for(int i =1; i<=v; i++){
			if(check[i]==0)
				if(dfs(i,1) == -1)
					tmp = -1;
		}

		if(tmp == 0)
			printf("YES\n");
		else if(tmp == -1)
			printf("NO\n");
	}
}
