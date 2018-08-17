#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int l,c;
int consonant,vowel;

vector<char> v;
void solve(vector<char>& vec,int lastidx,int consonant,int vowel){
	int len = vec.size();

	if(vec.size() == l)
	{
		if(vowel>=1 && consonant >=2)
		{
			for(int i = 0;i<len;i++)
				cout << vec[i];//temporary
			puts("");
		}
		return;
	}

	bool check = false;

	for(int i = lastidx + 1 ; i < c ; i++)
	{
		vec.push_back(v[i]);

		if(v[i] == 'a'||v[i] == 'e' ||v[i] == 'i' ||v[i] == 'o' ||v[i] == 'u' ){
			solve(vec,i,consonant,vowel+1);
		}
		else
			solve(vec,i,consonant+1,vowel);

		vec.erase(vec.begin() + len);

	}

	return ;
}

int main(){
	cin >> l >> c;
	char x;

	for(int i =0;i<c;i++)
	{
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(),v.end());

	//	for(int i =0;i<c;i++)
	//		cout << v[i] << endl;

	vector<char> tmp;

	for(int i =0;i<c;i++)
	{
		tmp.push_back(v[i]);

		if(v[i] == 'a'||v[i] == 'e' ||v[i] == 'i' ||v[i] == 'o' ||v[i] == 'u' ){
			solve(tmp,i,0,1);
		}
		else
			solve(tmp,i,1,0);

		tmp.erase(tmp.begin());

	}

	return 0;
}
