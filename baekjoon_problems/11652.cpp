#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

	vector<long long int > v;

	int n;
	long long int x;

	scanf("%d",&n);

	for(int i = 0 ; i<n;i++)
	{
		scanf("%lld",&x);
		v.push_back(x);
	}
	sort(v.begin(),v.end());

	long long int ans=v[0];
	int cnt_max=1,cnt=1;

	for(int i = 1 ; i<n;i++)
	{
		if(v[i] == v[i-1])
			cnt++;
		else
			cnt = 1;

		if(cnt_max < cnt)
		{
			cnt_max = cnt;
			ans = v[i];
		}
	}
	printf("%lld\n",ans);
	return 0;
}
