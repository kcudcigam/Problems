#include<bits/stdc++.h>
using namespace std;
int n,sum=0;string S;
int check(string s)
{
	string temp;
	for(int i=0;i<s.size();i++)
	{
		for(int k=i;k<s.size();k++)
		{
			temp=s;
			temp.erase(i,k);
			if(temp==S)  {return 0;}
		}
	}
	return 1;
}
void dfs(string s)
{
	if(s.size()>=n)
	{
		sum+=check(s);
		return ;
	}
	for(char i='a';i<='z';i++)
	{
		dfs(s+i);
	}
}
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);	
	cin>>n>>S;
	dfs("");
	cout<<sum<<endl;
	return 0;
}
