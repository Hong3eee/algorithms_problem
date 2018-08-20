#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[100];
int op[100];
int sol[100];

int cnt;
int maxval = -1000000;
int minval = 987654321;

void calc(){
	int sum = arr[0];
	for(int i =0;i<n-1;i++)
	{
		switch(sol[i])
		{
			case 1:
				sum = sum + arr[i+1];
				break;

			case 2:
				sum = sum - arr[i+1];
				break;

			case 3:
				sum = sum * arr[i+1];
				break;

			case 4:
				sum = sum / arr[i+1];
				break;
			default:
				break;
		}

	}

	maxval = max(maxval,sum);
	minval = min(minval,sum);
	return;
}

void solve(int idx){

	if(idx == n-1)
	{
		calc();
		return;
	}
	for(int i=1;i<=4;i++)
	{
		if(op[i])
		{
			op[i]--;
			sol[idx] = i;
			
			solve(idx+1);

			sol[idx] = 0;
			op[i]++;

		}
	}
	return ;
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);

	for(int i=1;i<=4;i++)
		scanf("%d",&op[i]);


	solve(0);

	printf("%d\n%d\n",maxval,minval);

	return 0;
}
