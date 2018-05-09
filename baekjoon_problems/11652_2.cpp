#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<int,int> &u, const pair<int,int> &v){
	return (u.first>v.first);
}
int main(){
	
	vector< pair<int,int> > v;

	int n,x ;

	scanf("%d",&n);

	for(int i = 0 ; i<=n;i++)
		v.push_back(make_pair(0,i));

	for(int i = 1 ; i<=n;i++)
	{
		scanf("%d",&x);
		v[x].first++;
	//	printf("x= %d v[x] = %d\n",x,v[x].first);
	}
	sort(v.begin(),v.end(),cmp);

	//	printf("x= %d v[x] = %d v second %d\n",v.size()-1,v[v.size()-1].first,v[v.size()-1].second);
	printf("%u\n" ,v[0].second);

	
	/*for(int i = 0 ; i<v.size();i++)
	{
		printf("i = %d v.first = %u v.second = %d\n" ,i,v[i].first,v[i].second);

	}*/


	return 0;
}
