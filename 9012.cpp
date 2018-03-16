#include <stdio.h>
#include <stack>
#include <string.h>

using namespace std;

int main(){

	int T;

	scanf("%d",&T);

	for (int i = 0 ; i<T ; i++)
	{
		stack<char> stack;
		
		char input[50];

		scanf("%s",input);
		
		int j = strlen(input);
		int cnt = 0;

		for(int k =0; k<j ; k++){
			if(input[k]==')'){
				if(stack.empty()){
					cnt = -1;
					break;
				}
				else
					stack.pop();
			}
			else
				stack.push(input[k]);

		}
		if ( stack.empty() && cnt == 0)
			printf("YES\n");
		else
			printf("NO\n");


	}
	return 0;
}
