#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int arr[3*3*3*3*3*3*3 + 1][3*3*3*3*3*3*3 + 1];
int ans[3];

void divide(int n,int y,int x){
	int value = arr[y][x];

	if(n==1)
	{
		ans[ value + 1 ]++;
		return;
	}

	bool check = true;

	for(int i = 0;i<n;i++)
		for(int j = 0;j<n;j++)
		{
			if(value != arr[y+i][x+j])
				check = false;

		}

	if(check)
	{
		ans[ value + 1] ++;
		return ;
	}

	int next = n/3;

	for(int i = 0;i<3;i++)
		for(int j = 0;j<3;j++)
			divide(next , y + i*next , x + j*next);

	return;
}

int main(){
	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> arr[i][j];

	divide(n,0,0);
	for(int i = 0 ; i<3;i++)
		cout << ans[i] << endl;

	return 0;
}
