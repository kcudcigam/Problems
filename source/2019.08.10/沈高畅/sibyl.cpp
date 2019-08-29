#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	 char ch=getchar();
	 int f=0;
	 while(!isdigit(ch)) ch=getchar();
	 while(isdigit(ch)) f=f*10+ch-48,ch=getchar();
	 return f;
}
vector<int>vec[100005];
int qz[100005],n,m;
bool flag[100005];
inline bool pd()
{
	bool flag=1;
	for(int i=2;i<=n;i++)
		{
			if(vec[i].size()>13) flag=0;
		}
	return flag;
}
int main()
{
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	int n,m,Q;
	n=read();
	m=read();
	Q=read();
	for(int i=1;i<=m;i++)
		{
			int a,b;
			a=read();
			b=read();
			if(a==1) flag[b]=1;
			if(b==1) flag[a]=1;
			vec[a].push_back(b);
			vec[b].push_back(a);
		}
	if(n<=3000&&m<=3000&&Q<=3000)
		{
			while(Q--)
				{
					int type,a,b;
					type=read();
					a=read();
					if(type==1)
						{
							b=read();
							qz[a]+=b;
							for(int i=0;i<vec[a].size();i++) qz[vec[a][i]]+=b;
						}
					else
						{
							cout<<qz[a]<<endl;
						}
				}
			return 0;
		}
	if(pd())
		{
			while(Q--)
				{
					int type,a,b;
					type=read();
					a=read();
					if(type==1)
						{
							b=read();
							qz[a]+=b;
							if(a!=1) for(int i=0;i<vec[a].size();i++) qz[vec[a][i]]+=b;
						}
					if(type==0)
						{
							if(flag[a]) cout<<qz[1]+qz[a]<<endl;
							else cout<<qz[a]<<endl;
						}
				}
			return 0;
		}
	return 0;
}


