#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <utility>
#include <cstdio>
#include <functional>  

using namespace std;

int main()
{
	string s;
	cin >> s;
	int n = s.size();
	vector<string> v;

	for (int i = 0; i < n; i++)
		v.push_back(s.substr(i));

	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
		cout << v[i] << '\n';
	
	return 0;
}