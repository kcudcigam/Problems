#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int num=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if (c=='-') f=-1;c=getchar();}
	while(isdigit(c)){num=num*10+c-'0';c=getchar();}
	return num*f;
}
int n,m,q,ans[300005];
int head[300005],tot;
struct node{
	int to,nxt;
}edge[300005];
bool h[300005];
void add(int a,int b){
	edge[++tot].to=b;
	edge[tot].nxt=head[a];
	head[a]=tot;
}
signed main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	n=read();
	m=read();
	q=read();
	for(int i=1;i<=m;i++)
	{
		int a=read(),b=read();
		add(a,b);
		add(b,a);
		if (a==1) h[b]=1;
		if (b==1) h[a]=1;
	}
	if (q<=3000)
	{
		for(int i=1;i<=q;i++)
		{
			int opt=read();
			if (opt==1)
			{
				int a=read(),b=read();
				ans[a]+=b;
				for(int j=head[a];j;j=edge[j].nxt)
					ans[edge[j].to]+=b;
			}
			if (opt==0)
			{
				int a=read();
				cout<<ans[a]<<endl;
			}
		}	
		return 0;
	}
	int aaa=0;
	for(int i=1;i<=q;i++)
	{
		int opt=read();
		if (opt==1)
		{
			int a=read(),b=read();
			ans[a]+=b;
			if (a==1) aaa+=b;
			else 
				for(int j=head[a];j;j=edge[j].nxt)
					ans[edge[j].to]+=b;
		}
		if (opt==0)
		{
			int a=read();
			if (h[a]==1) cout<<ans[a]+aaa<<endl;
			else cout<<ans[a]<<endl;
		}
	}	
	return 0;
}
