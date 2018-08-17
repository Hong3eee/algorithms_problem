#include<queue>
#include<cstdlib>
#include<cassert>
#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct RNG {
	int seed, a, b;
	RNG(int _a, int _b) : a(_a), b(_b), seed(1983) {}
	int next() {
		int ret = seed;
		seed = ((seed * (long long)a) + b) % 20090711;
		return ret;
	}
};

int runningMedian2(int n, RNG rng) {
	priority_queue<int, vector<int>, less<int> > maxHeap;
	priority_queue<int, vector<int>, greater<int> > minHeap;
	int ret = 0;
	// 반복문 불변 조건:
	// 1. maxHeap 의 크기는 minHeap 의 크기와 같거나 1 더 크다
	// 2. maxHeap.top() <= minHeap.top()
	for(int cnt = 1; cnt <= n; ++cnt) {
		// 우선 1번 불변 조건부터 만족시킨다
		if(maxHeap.size() == minHeap.size())
			maxHeap.push(rng.next());
		else
			minHeap.push(rng.next());
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

int main() {
	int cases;
	cin >> cases;
	for(int cc = 0; cc < cases; ++cc) {
		int n;
		unsigned a, b;
		cin >> n >> a >> b;
		RNG rng1(a,b), rng2(a,b);
			int c = runningMedian2(n, rng2);
			printf("%d\n",c);
	}
}

