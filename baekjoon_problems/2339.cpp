#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int arr[20][20];

int solve(int sy,int sx,int ey,int ex,int direction){
	if(sy>ey || sx>ex) return 0;
	int ret=0;
	int gold = 0;
	int trash = 0;
	vector < pair<int,int> > v;

	for(int y =sy;y<=ey;y++)
	{
		for(int x =sx;x<=ex;x++)
		{
			if(arr[y][x] == 2)
				gold++;
			else if(arr[y][x] == 1)
			{
				trash++;
				v.push_back(make_pair(y,x));
			}
		}
	}

	if(gold == 0) 
		return 0;
	if(trash ==0)
	{
		if(gold == 1)
			return 1;
		else 
			return 0;
	}

	if(direction == 1) // 가로
	{
		for(int z=0;z<v.size();z++)
		{
			bool check = true;
			int dy = v[z].first;

			for(int i = sx;i<=ex;i++)
				if(arr[dy][i] == 2)
					check = false;
			if(check==true)
				ret += solve(dy+1,sx, ey, ex,-1) * solve(sy,sx,dy-1,ex,-1);
		}

	}
	else	// 세로
	{
		for(int z=0;z<v.size();z++)
		{
			bool check = true;
			int dx = v[z].second;

			for(int i = sy;i<=ey;i++)
				if(arr[i][dx] == 2)
					check = false;
			if(check==true)
				ret += solve(sy,sx, ey, dx-1,1) * solve(sy,dx+1,ey,ex,1);
		}
	}

	return ret;
}

int main(){

	scanf("%d",&n);
	for(int y =0;y<n;y++)
		for(int x =0;x<n;x++)
			scanf("%d",&arr[y][x]);

	// 1 불순물, 2 보석결정체, 0 없는거

	int ret=0;
	ret += solve(0,0,n-1,n-1,1);
	ret += solve(0,0,n-1,n-1,-1);

	printf("%d\n",ret==0? -1 : ret);


	return 0;

}
