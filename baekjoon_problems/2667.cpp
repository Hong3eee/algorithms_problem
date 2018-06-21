#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int group[25][25];
int arr[25][25];
int group_num;
int group_cnt;
int n;

void dfs(int i,int j){
	group[i][j] = group_num; //방문

	group_cnt++; //각 단지마다 값

	for(int k=0;k<4;k++)	//상하좌우 방문할지 반복문 사용해서 검증
	{
		int x,y;
		x = i+dx[k];
		y = j+dy[k];
		if( (x>=0 && x<n) && (y>=0 && y<n) )
		{
			if(arr[x][y] == 1 && group[x][y] ==0)
				dfs(x,y);
		}
	}
}

int main(){
	scanf("%d",&n);
	vector<int> cnt_arr;

	for(int i = 0; i<n;i++){
		for(int j = 0;j<n;j++){
			int x;
			scanf("%1d",&x);
			arr[i][j] = x;
		}
	}

	for(int i = 0; i<n;i++){
		for(int j = 0;j<n;j++){
			if(arr[i][j] != 0 && group[i][j] == 0){
				group_num++;
				dfs(i,j);
				cnt_arr.push_back(group_cnt);
				group_cnt = 0;
			}
		}
	}

	sort(cnt_arr.begin(),cnt_arr.end());

	printf("%d\n",group_num);
	for(int i = 0; i<cnt_arr.size();i++)
		printf("%d\n",cnt_arr[i]);

	return 0;
}
