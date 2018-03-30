#include <stdio.h>
#include <stack>
#include <string.h>

using namespace std;

int main(){

	stack<char> Lstack;
	stack<char> Rstack;

	char input[100000];
	int N;
	char inst;

	scanf("%s",input);
	scanf("%d",&N);
	getchar();

	int len = strlen(input);

	for(int i =0; i<len ; i++)
		Lstack.push(input[i]);

	for(int i = 0 ; i<N; i++){
		scanf("%c",&inst);
		getchar();
		//printf("%d %c\n",i,inst);
		if(inst=='P')
		{
			scanf("%c",&inst);
			getchar();
			Lstack.push(inst);
		}
		else if(inst=='L')
		{
			if(Lstack.empty())
				continue;
			Rstack.push(Lstack.top());
			Lstack.pop();
		}
		else if(inst=='D')
		{
			if(Rstack.empty())
				continue;
			Lstack.push(Rstack.top());
			Rstack.pop();
		}
		else if(inst=='B')
		{
			if(Lstack.empty())
				continue;
			Lstack.pop();
		}
	}
	while(!Lstack.empty())
	{	
		Rstack.push(Lstack.top());
		Lstack.pop();
	}
	while(!Rstack.empty())
	{
		printf("%c",Rstack.top());
		Rstack.pop();
	}

	return 0;
}
