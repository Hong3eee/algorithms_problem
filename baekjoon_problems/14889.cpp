#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int ans = 987654321;
int arr[21][21];
bool check[21];
int size = 0 ;
int n;
// size == n/2 일때 팀 능력치 계산하는 함수
int calc(){
	int sum1 = 0;
	int sum2 = 0;

	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(check[i] && check[j])
				sum1 += arr[i][j];
			else if(!check[i] && !check[j])
				sum2 += arr[i][j];
/*
   for(int i=1;i<=n;i++)
		printf("i -> %d  t/f : %d\n",i,check[i]);
	printf("dif = %d\n",sum1-sum2);
	puts("");
*/
	return abs(sum1-sum2) ;
}

//그룹을 처음부터 끝까지 구해주는 재귀함수
void makegroup(int lastidx){
	if(size == n/2)
	{
		ans = min(ans,calc());
		return ;
	}

	for(int i = lastidx + 1;i<=n;i++)
	{
		check[i] = true;
		size++;

		makegroup(i);

		check[i] = false ;
		size--;
	}
}

int main(){
	scanf("%d",&n);

	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&arr[i][j]);

	for(int i=1;i<=n;i++) // n 증감식 check
	{		
		check[i] = true;
		size++;

		makegroup(i);

		check[i] = false ;
		size--;
	}
	cout << ans <<endl;

	return 0;
}
