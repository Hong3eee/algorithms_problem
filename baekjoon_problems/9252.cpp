#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int d[1001][1001];
string a,b;

int main(){

	cin >> a >> b;

	for(int i = 1; i<=a.size() ; i++)
		for(int j = 1; j<=b.size() ; j++)
		{
			if(a[i-1] == b[j-1])
				d[i][j] = d[i-1][j-1] + 1;
			else
				d[i][j] = max(d[i-1][j] , d[i][j-1]);
		}

	cout << d[a.size()][b.size()] << endl;

	int y = a.size();
	int x = b.size();
	vector<char> v;
	while(y>0 && x>0)
	{
		if(d[y][x-1] == d[y-1][x] && d[y-1][x] == d[y-1][x-1] && d[y-1][x-1] == d[y][x] -1)
		{
			v.push_back(a[y-1]);
			y--;
			x--;
		}
		else
		{
			if(d[y-1][x] == d[y][x])
				y--;
			else if(d[y][x-1] == d[y][x])
				x--;
		}
	}

	reverse(v.begin(),v.end());

	for(int i=0;i<v.size();i++)
		cout << v[i];
	puts("");	

	return 0;
}
