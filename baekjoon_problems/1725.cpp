#include <cstdio>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int height[100002];

int solve(int start,int end ){
	int ret=0;

	if(start == end)
		return ret = height[start];

	int half = (start + end) / 2;

	int leftsize = solve(start , half);
	// 왼쪽
	int rightsize = solve(half+1 , end);
	// 오른쪽

	ret = max(leftsize, rightsize);

	int left = half;
	int right = half+1;

	int value = min( height[left] , height[right] );

	ret = max(ret,value*2);

	// 두 개 사이
	while(start < left || right < end){

		if( left == start )
		{
			right++;
			value = min(value,height[right]);
		}
		else if( right == end )
		{
			left--;
			value = min(value,height[left]);
		}
		else{
			if( height[left-1] < height[right+1])
			{
				right++;
				value = min(value,height[right]);
			}
			else 
			{
				left--;
				value = min(value,height[left]);
			}
		}

		ret = max(ret, value * (right - left +1));
	}

	return ret;
}

int main(){

	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> height[i];

	// 분할정복을 이용한 풀이. O(n lg n)
	int ans = solve(1,n);



/* 	stack을 이용한 풀이.O(n)

	int ans = 0;
	stack<int> st;
	st.push(0);

	for(int i=1;i<=n+1;i++)
	{
		while(height[st.top()] > height[i])
		{
			int h = height[st.top()];
			st.pop();
			int width = i - st.top()-1;
			ans = max(ans,h * width);
		}
		st.push(i);

	}
*/

	cout << ans << endl;

	return 0;
}

