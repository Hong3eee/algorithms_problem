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
	
	for(int i = 0; i<a.size() ; i++)
	{
		if(a[i] == b[0])
			d[i][0] = 1;
		else
		{
			if(i==0)
				continue;
			d[i][0] = d[i-1][0];
		}
	}

	for(int i = 0; i<b.size() ; i++)
	{
		if(a[0] == b[i])
			d[0][i] = 1;
		else
		{
			if(i==0)
				continue;
			d[0][i] = d[0][i-1];
		}
	}

	for(int i = 1; i<a.size() ; i++)
		for(int j = 1; j<b.size() ; j++)
		{
			if(a[i] == b[j])
				d[i][j] = d[i-1][j-1] + 1;
			else
				d[i][j] = max(d[i-1][j] , d[i][j-1]);
		}

	cout << d[a.size()-1][b.size()-1] << endl;
	return 0;
}
