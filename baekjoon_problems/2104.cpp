#include <cstdio>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

long long int arr[100002];
long long int psum[100002];

long long int solve(int s,int e){

	long long int ret = 0;
	if(s == e)
		return arr[s] * arr[s];

	int half = (s + e) /2;

	ret = max( solve(s,half), solve(half+1,e) );

	int lo = half;
	int hi = half + 1;

	long long int minval = min( arr[lo] , arr[hi]);
	ret = max ( ret , minval * (psum[hi] - psum[lo-1]));

	while( s < lo || hi < e){

		if( lo == s )
		{
			hi++;
			minval = min(minval,arr[hi]);
		}
		else if( hi == e )
		{
			lo--;
			minval = min(minval,arr[lo]);
		}
		else
		{
			if( arr[lo - 1] < arr[hi + 1])
			{
				hi++;
				minval = min(minval,arr[hi]);
			}
			else
			{
				lo--;
				minval = min(minval,arr[lo]);
			}
		}
		ret = max ( ret , minval * (psum[hi] - psum[lo-1]));

	}

	return ret;

}

int main(){
	int n;
	cin >> n;

	for(int i = 1; i<= n; i++)
	{
		cin >> arr[i];
		psum[i] = psum[i-1] + arr[i];
	}

	cout << solve(1,n) << endl;

	return 0;
}
