#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

vector<int> in;
vector<int> post;
int pos[100001];
int n;

void traversal(int is,int ie,int ps,int pe)
{
	int ogsize = ie-is+1;

	if(ogsize < 1) return;

	int root = post[pe];
	int cnt = pos[root];

	cout << root << ' ';

	traversal(is, cnt -1 , ps,ps + cnt -is -1);
	traversal(cnt + 1,ie , ps + cnt - is, pe -1);

	return ;
}
vector<int> slice(const vector<int>& v,int a,int b){
	return vector<int>(v.begin()+a,v.begin()+b);}

void traversal(const vector<int>& inorder,const vector<int>& postorder)
{
	int ogsize = postorder.size();

	if(ogsize < 1) return;

	int root = postorder[ogsize-1];

	int firstsize = 0;
	int secondsize = 0;

	for(int i=0;i<ogsize;i++)
		if(inorder[i] == root)
			break;
		else
			firstsize++;

	secondsize = ogsize - firstsize - 1;

	cout << root << ' ';
	traversal(slice(inorder,0,firstsize),slice(postorder,0,firstsize));
	traversal(slice(inorder,firstsize+1,ogsize),slice(postorder,firstsize,ogsize-1));
	return ;
}

int main(){
	int x;
	cin >> n;

	for(int i = 0; i < n; i ++)
	{
		cin >> x;
	    in.push_back(x);
		pos[x] = i;
	}

	for(int i = 0; i < n; i ++)
	{
		cin >> x;
	    post.push_back(x);
	}
	
//	traversal(in,post);
	traversal(0,n-1,0,n-1);
	return 0;

}
