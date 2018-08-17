#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
int n;
int direction[4] = {1,2,3,4};

void merge(int arr[20][20],int dx){

	queue<int> q[20];
	int idx = 0;

	switch(dx){
		case 1:// right
			for(int j=0;j<n;j++)
				for(int k=n-1;k>=0;k--)
				{
					if(arr[j][k] !=0)
						q[j].push(arr[j][k]);
					arr[j][k] = 0;
				}

			for(int j=0;j<n;j++)
			{
				idx = n-1;
				while(!q[j].empty()){
					int tmp = q[j].front();
					q[j].pop();

					if(arr[j][idx] == 0) arr[j][idx] = tmp;
					else if(arr[j][idx] == tmp){
						arr[j][idx] = tmp *2;
						idx--;
					}
					else arr[j][--idx] = tmp;
				}
			}
			break;
		case 2: // down
			for(int k=0;k<n;k++)
				for(int j=n-1;j>=0;j--)
				{
					if(arr[j][k] !=0)
						q[k].push(arr[j][k]);
					arr[j][k] = 0;
				}

			for(int j=0;j<n;j++)
			{
				idx = n-1;
				while(!q[j].empty()){
					int tmp = q[j].front();
					q[j].pop();

					if(arr[idx][j] == 0) arr[idx][j] = tmp;
					else if(arr[idx][j] == tmp){
						arr[idx][j] = tmp *2;
						idx--;
					}
					else arr[--idx][j] = tmp;
				}
			}

			break;
		case 3: // left	
			for(int j=0;j<n;j++)
				for(int k=0;k<n;k++)
				{
					if(arr[j][k] !=0)
						q[j].push(arr[j][k]);
					arr[j][k] = 0;
				}

			for(int j=0;j<n;j++)
			{
				idx = 0;
				while(!q[j].empty()){
					int tmp = q[j].front();
					q[j].pop();

					if(arr[j][idx] == 0) arr[j][idx] = tmp;
					else if(arr[j][idx] == tmp){
						arr[j][idx] = tmp *2;
						idx++;
					}
					else arr[j][++idx] = tmp;
				}
			}

			break;
		case 4: // top
			for(int k=0;k<n;k++)
				for(int j=0;j<n;j++)
				{
					if(arr[j][k] !=0)
						q[k].push(arr[j][k]);
					arr[j][k] = 0;
				}

			for(int j=0;j<n;j++)
			{
				idx = 0;
				while(!q[j].empty()){
					int tmp = q[j].front();
					q[j].pop();

					if(arr[idx][j] == 0) arr[idx][j] = tmp;
					else if(arr[idx][j] == tmp){
						arr[idx][j] = tmp *2;
						idx++;
					}
					else arr[++idx][j] = tmp;
					/*
					   if(tmp == q[j].front())
					   {
					   arr[idx][j] = tmp * 2;
					   idx++;
					   q[j].pop();
					   }
					   else
					   {
					   arr[idx][j] = tmp;
					   idx++;
					   }
					 */
				}
			}
			break;
	}
}

int solve(int cnt,int arr[][20]){
	int ret=0;
	if(cnt==5)
	{
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
				ret = max(ret,arr[j][k]);

		return ret;
	}

	for(int i=0;i<4;i++)
	{
		int tmp[20][20];

		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
				tmp[j][k] = arr[j][k];

		merge(tmp,direction[i]);
		ret = max(ret,solve(cnt+1,tmp));
	}

	return ret;
}

int main(){
	int arr[20][20];

	cin >> n;
	for(int i =0;i<n;i++)
		for(int j =0;j<n;j++)
			cin >> arr[i][j];

	cout << solve(0,arr) << endl;
	return 0;
}
