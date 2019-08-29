#include<bits/stdc++.h>
using namespace std;

int n,q;
int father[500010],num[500010];
vector < int > son[500010];
int a,b,x,y;

int belone(int n)
{
	if(father[n] != n) return father[n] = belone(father[n]);
	return n;
}

void bianli(int now)
{
	for(int i = 0;i < son[now].size();i++)
	{
		num[son[now][i]] += num[now];
		bianli(son[now][i]);
	}
}

int main()
{
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout); 
	cin>>n>>q;
	
	for(int i = 1;i <= n;i++)
	{
		father[i] = i;
	}
	
	while(q--)
	{
		int in;
		cin>>in;
		if(in == 1)
		{
			cin>>a>>b;
			int a_father = belone(a);
			int b_father = belone(b);
			father[a_father] = b_father;
			num[a_father] -= num[b_father];
			son[b_father].push_back(a_father);
		}
		else
		{
			cin>>x>>y;
			num[belone(x)] += y;
		}
	}
	
	for(int i = 1;i <= n;i++)
	{
		if(father[i] == i)
		{
			bianli(i);
		}
	}
	
	for(int i = 1;i <= n;i++)
	cout<<num[i]<<' '; 
	
	return 0;
}
