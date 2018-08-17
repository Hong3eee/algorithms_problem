#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int ans;
int n , s;
void solve(vector<int> vec, int lastidx)
{
	int sum = 0,len = vec.size();
	for(int i = 0; i<len;i++)
		sum += vec[i];

	if(sum == s) ans++;
	if(lastidx == n-1) return;

	for(int i = lastidx +1;i<n;i++)
	{
		vec.push_back(v[i]);
		solve(vec,i);
		vec.erase(vec.begin() + len);
	}

}
int main(){
	int x;

	cin >> n >> s;
	for(int i = 0; i<n;i++)
	{
		cin >> x;
		v.push_back(x);
	}

	vector<int> choose;

	for(int i = 0; i < n ;i++)
	{
		choose.push_back(v[i]);
		solve(choose,i);
		choose.erase(choose.begin() + 0);
	}

	cout << ans << endl;

	return 0;
}
