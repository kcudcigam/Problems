#include<bits/stdc++.h>
using namespace std;
int n,m,q,a,b,qq;
long long ans[300001],an;
vector <int > f[300001];
template <typename T> void read(T & x)
{
	int f=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-f;
	for(;isdigit(c);c=getchar())  x=x*10+c-'0';
	x*=f;
}
int main()
{
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
    read(n);read(m);read(q);
    for(register int i=1;i<=m;i++)
    {
    	read(a);read(b);
    	f[a].push_back(b);
    	f[b].push_back(a);
	}
	while(q--)
	{
		read(qq);
		if(qq==1)
		{
			read(a);read(b);
			ans[a]+=b;
		}
		else
		{
			read(a);
			an=ans[a];
			for(register int i=0;i<f[a].size();i++)
			{
				an+=ans[f[a][i]];
			}
			cout<<an<<endl;
		}
	}
    return 0;
}
