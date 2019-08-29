#include<bits/stdc++.h>
using namespace std;
#define RG register
#define int long long
inline int read()
{
	int s=0,w=1;char c=getchar();
	while((c<'0'||c>'9')&&c!='-') c=getchar();
	if(c=='-') w=-1,c=getchar();
	while(c>='0'&&c<='9') s=s*10+c-'0',c=getchar();
	return s*w;
}
int n,m;long long g[10];
bool v[100],vv[100];
struct rec
{
	int l,r;
}a[100];
bool cmp(rec x,rec y){return x.l<y.l;}
long long f[100],tot;
inline long long gf(long long x)
{
	long long sss[10];
	sss[0]=1;
	long long s=0;
	for(RG int i=1;i<=5;i++)
	sss[i]=sss[i-1]*x;
	for(RG int i=1;i<=5;i++)
	s=s+sss[i]*g[i];
	return s;
}
signed main()
{
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=5;i++) g[i]=read();
	for(RG int i=1;i<=n;i++)
	a[i].l=read(),a[i].r=read();
	sort(a+1,a+n+1,cmp);
	int nu=n;
	while(nu)
	{
		int k=0,p=1,cnt=0,pos=0,po=0,ans=0;
        memset(v,0,sizeof(v));
        for(RG int i=p;i<=n;++i)
        {
        	if(vv[i])
			{
				if(i==p) p++;
				continue;
			}
    	   k=a[i].l;++cnt;
    	   for(RG int j=p;j<i;++j)
    	   {
    		   if(v[j]||vv[j]) continue;
    		   if(a[j].r<k) --cnt,v[j]=1;
		   }
		  if(ans<cnt)
		  {
			ans=cnt;
			pos=k;
			po=i;
		  }
	    }
	    f[++tot]=ans;
	    for(RG int i=po;ans;i--)
	    {
	    	if(a[i].l<=pos&&a[i].r>=pos)
	    	{
	    		--ans;
	    		--nu;
	    		vv[i]=1;
			}
		}	
	}
	long long answ=0;
	for(RG int i=1;i<=tot;i++)
	{
		answ+=gf(f[i]);
	}  
	cout<<answ;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
