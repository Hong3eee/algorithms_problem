#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
#include <deque>
#include <math.h>
#include <algorithm>
using namespace std;
//vector <vector <int> > adj;
//vector <string> word;
//vector <int> visit(26, 0);
vector <int>order;
int n;

string s[1000];
int adj[26][26];
bool check[26];

void dfs(int);

void makegroup(int n){ // 단어들의 순서로 그래프 모델 구현
	for(int i=1;i<n;i++)
	{
		int len = min(s[i].size(),s[i-1].size());
		for(int k=0;k<len;k++)
			if(s[i-1][k] != s[i][k]){
				char a = s[i-1][k];
				char b = s[i][k];
				int x = a - 'a';
				int y = b - 'a';
				adj[x][y] = 1;
				break;
			}
	}
}

void dfs(int s) // dfs 수행 후, 재귀의 마지막 호출부터 벡터(스택)에 넣음
{
	check[s] = true;
	for(int i=0;i<26;i++)
		if(adj[s][i] && check[i] == false)
			dfs(i);

	order.push_back(s);
}

vector<int> toposort(){
	// 벡터에넣은 순서를 뒤집어(=스택 역할) 순서에 역행하는 간선이 있는지 체크(위상 정렬이 제대로 됐는지 체크)

	for(int i=0;i<26;i++)
		if(check[i]==false)
			dfs(i);

	reverse(order.begin(),order.end());

	for (int i = 0; i < 26; i++)
		for (int j = i + 1; j < 26; j++)
			if (adj[order[j]][order[i]])
				return vector<int>();

	return order;
}

int main(){
	int c;
	scanf("%d",&c);
	for(int z=0;z<c;z++)
	{
		memset(adj,0,sizeof(adj));
		memset(check,false,sizeof(check));
		order.clear();

		n = 0;
		scanf("%d",&n);

		for(int i =0;i<n;i++)
			cin >> s[i];

		makegroup(n);
		vector<int> out = toposort();

		if(out.empty())
			printf("INVALID HYPOTHESIS");
		else
			for (int i = 0; i < out.size(); i++)
				printf("%c", out[i] + 'a');
				printf("\n");
		/*
		   for(int i =0;i<26;i++)
		   {
		   for(int j =0;j<26;j++)
		   printf("%d ",adj[i][j]);
		   puts("");
		   }
		 */



	}

	return 0;
}
