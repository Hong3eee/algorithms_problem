#include <queue>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int cnt;
vector<int> v[101];
bool check[101] = {false,};

void bfs(int start){

	queue<int> q;
	q.push(start);
	check[start] = true;

	while(!q.empty()){

		int cur = q.front();
		q.pop();

		for(int i = 0; i<v[cur].size();i++)
		{
			int next = v[cur][i];
			if(check[next]==false)
			{
				cnt++;
				check[next] = true;
				q.push(next);
			}
		}
	}

	return ;
}
int main(){

	int com,p;
	cin >> com >> p;
	
	for(int i =0;i<p;i++)
	{
		int x,y;
		cin >> x >>y ;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	bfs(1);

	cout << cnt << endl;

	return 0;
}
