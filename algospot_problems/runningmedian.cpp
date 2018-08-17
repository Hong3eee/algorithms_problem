#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

long long int arr[200001];

int runningMedian(int n) {
	priority_queue<int, vector<int>, less<int> > maxHeap;
	priority_queue<int, vector<int>, greater<int> > minHeap;
	int ret = 0;
	// 반복문 불변 조건:
	// 1. maxHeap 의 크기는 minHeap 의 크기와 같거나 1 더 크다
	// 2. maxHeap.top() <= minHeap.top()
	for(int cnt = 0; cnt < n; ++cnt) {
		// 우선 1번 불변 조건부터 만족시킨다
		if(maxHeap.size() == minHeap.size())
			maxHeap.push(arr[cnt]);
		else
			minHeap.push(arr[cnt]);
		// 2번 불변 조건이 깨졌을 경우 복구하자
		if(!minHeap.empty() && !maxHeap.empty() &&
				minHeap.top() < maxHeap.top()) {
			int a = maxHeap.top(), b = minHeap.top();
			maxHeap.pop(); minHeap.pop();
			maxHeap.push(b);
			minHeap.push(a);
		}
		ret = (ret + maxHeap.top()) % 20090711;
	}
	return ret;
}

int main(){

	int c;
	arr[0] = 1983;
	cin >> c;

	for(int z=0;z<c;z++)
	{
		int n,a,b;
		cin >> n >> a >> b;

		for(int i = 1;i < n;i++)
			arr[i] = (arr[i-1] * (long long)a + b) % 20090711;
/*
		vector<long long> v;
		long long int sum = 0;
		for(int i = 0;i<n;i++)
		{
			v.push_back(arr[i]);
			sort(v.begin(),v.end());
			int len = v.size();
			if(len % 2 ) // odd
			{
				sum = (sum + v[len/2]) % 20090711;
			}
			else
			{
				int tmp = min(v[len/2-1],v[len/2]);
				sum = (sum + tmp) % 20090711;
			}

		}
		cout << sum << endl;
*/
		cout << runningMedian(n) << endl;
		puts("test case end");

	}
	return 0;
}
