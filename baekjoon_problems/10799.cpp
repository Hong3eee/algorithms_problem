#include <stdio.h>
#include <stack>
#include <string.h>

using namespace std;

int main(){

	stack<int> stack;

	char input[100000];

	scanf("%s",input);

	int len = strlen(input);
	int sum = 0;
	int tmp=-1;

	for(int i =0; i<len ; i++){
		if(input[i]=='('){
			stack.push(i);
		}
		else
		{
		 	tmp = stack.top();
			stack.pop();
			if( tmp == i-1)
				sum += stack.size();
			else
				sum += 1;
		}
	}
	printf("%d",sum);

	return 0;
}
