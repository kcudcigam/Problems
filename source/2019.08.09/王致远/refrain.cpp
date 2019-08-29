#include<bits/stdc++.h>
using namespace std;
int v,a,b,c,n[21][21],nn[21][21],t[21],s,x[21],y[21],xx[21],yy[21];
bool f[21];
template <typename T> void read(T &x)
{
	x=0;char c=getchar();bool flg=0;
	for (;!isdigit(c);c=getchar()) if (c=='-') flg=1;
	for (;isdigit(c);c=getchar()) x=x*10+c-'0';
	if (flg) x=-x;
}
void chck()
{
	for (int i=1;i<=b;i++)
	if (n[t[x[i]]][t[y[i]]]==0) 
	{
		s=(s+1)%1000000007;
		return;
	}
	for (int i=1;i<=c;i++)
	if (nn[t[xx[i]]][t[yy[i]]]==0)	
	{
		s=(s+1)%1000000007;
		return;
	}
}
void wrk(int u)
{
	if (u>a) chck();
	else
	for (int i=1;i<=a;i++)
	if (f[i])
	{
		f[i]=0;
		t[u]=i;
		wrk(u+1);
		f[i]=1;
	}
}
int main(){
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	//ios::sync_with_stdio(false);
	read(v);
	read(a);read(b);read(c);
	memset(n,0,sizeof(n));memset(nn,0,sizeof(nn));
	for (int i=1;i<=b;i++) 
	{
		read(x[i]);read(y[i]);
		n[x[i]][y[i]]=1;n[y[i]][x[i]]=1;
	}
	for (int i=1;i<=c;i++) 
	{
		read(xx[i]);read(yy[i]);
		nn[xx[i]][yy[i]]=1;nn[yy[i]][xx[i]]=1;
	}
	s=0;memset(f,1,sizeof(f));
	wrk(1);	
	cout<<s<<endl;		
	return 0;
}


