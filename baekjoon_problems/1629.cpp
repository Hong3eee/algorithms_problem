#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;
int a,c;

long long int solve(int b){ 
	long long int ret = 0;
	if(b==1)
		return a;

	long long int x = solve(b/2) % c;

	if(b%2==1)
		ret =( solve(b/2 + 1) * x) % c;
	else
		ret = (x * x) % c;
	return ret;
}
int main(){
	int b;
	cin >> a >> b >> c;
	cout << solve(b) % c << endl;

	return 0;
}
