#include <stdio.h>
#include <queue>

using namespace std;

int main(){

	queue<int> q;
	int N,M;

	scanf("%d %d",&N,&M);

	for(int i=0;i<N;i++)
		q.push(i+1);

	printf("<");

	for(int i=0;i<N;i++){
		for(int j =0;j<M-1;j++){
			q.push(q.front());
			q.pop();
		}
		if(q.size()==1){
			printf("%d",q.front());
			q.pop();
		}
		else{
			printf("%d, ",q.front());
			q.pop();
		}
	}
	
	printf(">");


	return 0;
}
