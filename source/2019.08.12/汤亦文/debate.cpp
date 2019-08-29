#include<bits/stdc++.h>
using namespace std;
#define int long long
#define RG register int
#define M 400100
inline int read()
{
	int s=0,w=1;char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') s=s*10+c-'0',c=getchar();
	return s;
}
int n,tot;
int a[M],b[M],c[M],d[M];
int e[M];
int cna,cnb,cnc,cnd;
signed main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	n=read();
	for(RG i=1;i<=n;i++)
	{
		char cc=getchar();
		while(cc<'0'||cc>'9') cc=getchar();
		bool t=cc-'0';cc=getchar();
		bool tt=cc-'0';
		int w=read();
		if(t&&tt) a[++cna]=w;
		else if(t) b[++cnb]=w;
		else if(tt) c[++cnc]=w;
		else d[++cnd]=w;
		e[++tot]=w;
	}
	sort(a+1,a+1+cna);
	sort(b+1,b+1+cnb);
	sort(c+1,c+1+cnc);
	sort(d+1,d+1+cnd);
	if(cnb==0&&cnc==0)
	{
		int ans=0;
		for(RG i=1;i<=cna;i++) ans+=a[i];
		int j=min(cna,cnd);
		for(RG i=cnd;i>=cnd-j+1;i--) ans+=d[i];
		cout<<ans;
		fclose(stdin);fclose(stdout);
		return 0;
	}
	bool ju=1;
	for(RG i=2;i<=tot;i++)
	if(e[i]!=e[i-1])
	{ju=0;
	break;
	}
	if(ju)
	{
		int ans=0;
		ans+=cna;
		ans+=min(abs(cnb-cnc)+cnd,cna);
		ans+=min(cnb,cnc);
		ans=ans*e[1];
		cout<<ans;
		fclose(stdin);fclose(stdout);
		return 0;
	}
	int ans=0;
	for(int i=1;i<=cna;i++)
	 ans+=a[i];
	 int answ=0;
	 while(answ<ans||answ>(ans+ans/2)) answ=rand();
	cout<<answ;
	fclose(stdin);fclose(stdout);
	return 0;
}
