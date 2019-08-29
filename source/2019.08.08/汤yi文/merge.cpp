#include<bits/stdc++.h>
using namespace std;
#define RG register
inline int read()
{
	int s=0,w=1;char c=getchar();
	while((c<'0'||c>'9')&&c!='-') c=getchar();
	if(c=='-') w=-1,c=getchar();
	while(c>='0'&&c<='9') s=s*10+c-'0',c=getchar();
	return s*w;
}
int n,q;
int f[500100];
int an[500100];
inline int get(int x)
{
	if(x==f[x]) return x;
	return f[x]=get(f[x]);
}
int main()
{
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	n=read();q=read();
	for(RG int i=1;i<=n;i++) f[i]=i;
	for(RG int i=1;i<=q;i++)
	{
		int a,b,k;
		k=read();a=read();b=read();
		if(k==1)
		{
			int x=get(a),y=get(b);
			if(x==y) continue;
			f[y]=x;
		}
		if(k==2)
		{
			int x=get(a);
			for(RG int j=1;j<=n;j++)
			{
				if(get(j)==x)
				an[j]+=b;
				
			}
		}
	}
	for(RG int i=1;i<=n;i++)
	cout<<an[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
