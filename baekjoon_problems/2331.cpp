#include <cstdio>
#include <algorithm>
using namespace std;

int check[10000001];
int a,p;

int pow(int value)
{
	int sum = 0;
	int x;
	while( value > 0 )
	{
		int tmp = 1;
		x = value % 10; 
		value = value/10;
		for(int i = 0; i<p ;i++)
			tmp = tmp * x;
		sum = sum + tmp;
	}
	return sum;
}

int dfs(int x,int cnt)
{
	if(check[x]!=0)
		return check[x] -1;
	check[x] = cnt;
	int next = pow(x);
	return dfs(next,cnt+1);
}
int main(){
	scanf("%d %d",&a,&p);
	printf("%d\n",dfs(a,1));
	return 0;
}
