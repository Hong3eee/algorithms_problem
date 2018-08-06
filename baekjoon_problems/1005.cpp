#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int build_time[1001];
vector<int> v[1001];
int d[1001];

int calc(int num)
{
	if(v[num].size() == 0)
		return  build_time[num];

	int& ret = d[num];

	if(ret != -1) return ret;

	int tmp = 0;

	for(int i=0;i<v[num].size();i++)
		tmp = max(tmp,calc(v[num][i]));

	return ret = build_time[num]+ tmp;
}
int main(){
	int t;
	cin >> t;

	for(int z=0;z<t;z++){
		for(int k=0;k<1001;k++)
			v[k].clear();

		memset(d,-1,sizeof(d));

		int n,k;
		cin >> n >> k;
		for(int i = 1; i<=n;i++)
			cin >> build_time[i];

		for(int i = 0; i<k;i++)
		{
			int x,y;
			cin >> x >> y;
			v[y].push_back(x);
		}
		int w;
		cin >> w;

		cout << calc(w) << endl;
	}

	return 0;
}
