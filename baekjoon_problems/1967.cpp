#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

vector<pair<int,int > > v[10001];

bool check[10001];
int dist[10001];

void bfs(int start)
{
	memset(check,false,sizeof(check));
	memset(dist,0,sizeof(dist));

	queue< int > q;
	check[start] = true;
	dist[start] = 0;
	q.push(start);

	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for(int i = 0;i<v[cur].size();i++)
		{
			int to = v[cur][i].first;
			int w = v[cur][i].second;
			if(check[to] == false){
				q.push(to);
				check[to] = true;
				dist[to] = w + dist[cur];
			}
		}
	}
}

int main(){
	int n;
	int a,b,c;

	cin >> n;

	for(int i = 1 ; i <= n ; i++)
	{
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b,c));
		v[b].push_back(make_pair(a,c));
	}
	int start = 1;

	bfs(start);

	for(int i = 1 ; i <= n ; i++)
		if(dist[i] > dist[start])
			start = i;

	bfs(start);

	int ans=0;

	for(int i = 1 ; i <= n ; i++)
		ans = max(ans,dist[i]);

	cout << ans << endl;

	return 0;
}
