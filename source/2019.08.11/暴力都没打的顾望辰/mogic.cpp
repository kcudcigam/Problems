#include<cstdio>
#include<cstring>
#include<iostream>
#pragma GCC optimize(3)
using namespace std;
int n;
long long ans;
string s,str,now="";
long long qpow(int x,int p)
{
	int ret=1;
	while(p)
	{
		if(p&1) ret*=x;
		x*=x;
		p>>=1;
	}
	return ret;
}
void dfs(int x)
{
	if(x==n)
	{
		ans+=(now==s);
		for(int i=0;i<n;i++)
		{
			for(int j=i;j<n;j++)
			{
				str=now;
				str.erase(str.begin()+i,str.begin()+j+1);
				if(str==s)
				{
					ans++;
					return ;
				}
			}
		}
		return ;
	}
	for(int i=0;i<26;i++)
	{
		now+=(char)(i+97);
		dfs(x+1);
		now.erase(now.end()-1);
	}
	return ;
}
void A(int m,string s2)
{
	n=m;
	s=s2;
	ans=0;
	dfs(0);
	cout<<qpow(26,n)-ans<<' ';
}
int main()
{
//	cin>>n>>s;
	A(1,"a");
	putchar('\n');
	A(2,"a");
	A(2,"aa");
	putchar('\n');
	A(3,"a");
	A(3,"aa");
	A(3,"aaa");
	putchar('\n');
	A(4,"a");
	A(4,"aa");
	A(4,"aaa");
	A(4,"aaaa");
	putchar('\n');
	A(5,"a");
	A(5,"aa");
	A(5,"aaa");
	A(5,"aaaa");
	A(5,"aaaaa");
	putchar('\n');
	return 0;
}
