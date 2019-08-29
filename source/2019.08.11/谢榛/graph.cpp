#include<bits/stdc++.h>
using namespace std;
int a,b,c,maxi,ll,rr,l,r,mid,nw,k,q[300010],qz[600010],nxt[600010],len[600010],db[600010];
int x,y,z,s,t,tt,fa[600010];
struct qq
{
	int x,y,z;
};
qq n[600010];
bool f[300010];
template <typename T> void read(T &x)
{
	x=0;char c=getchar();bool flg=0;
	for (;!isdigit(c);c=getchar()) if (c=='-') flg=1;
	for (;isdigit(c);c=getchar()) x=x*10+c-'0';
	if (flg) x=-x;
}
bool chck(int u)
{
	memset(f,0,sizeof(f));ll=1;rr=1;q[1]=x;f[x]=1;
	while (ll<=rr)
	{
		nw=q[ll];k=len[nw];
		while (k)
		{
			if ((f[db[k]]==0)&&(qz[k]<=u))
			{
				if (db[k]==y) return 1;
				f[db[k]]=1;
				rr++;
				q[rr]=db[k];
			}
			k=nxt[k];
		}
		ll++;
	}
	return 0;
}
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	//ios::sync_with_stdio(false);
	read(a);read(b);read(c);
	for (int i=1;i<=b;i++)
	{
		read(x);read(y);read(z);
		n[i*2-1].x=x;n[i*2-1].y=y;n[i*2-1].z=z;
		n[i*2].x=y;n[i*2].y=x;n[i*2].z=z;
		db[i*2-1]=y;
		qz[i*2-1]=z;
		nxt[i*2-1]=len[x];
		len[x]=i*2-1;
		db[i*2]=x;
		qz[i*2]=z;
		nxt[i*2]=len[y];
		len[y]=i*2;
		if (z>maxi) maxi=z;
	}
	for (int i=1;i<=c;i++)
	{
		read(x);read(y);
		l=1;r=maxi;
		while (l<r-1)
		{
			mid=(l+r)/2;
			if (chck(mid)) 
			r=mid;
			else l=mid+1;
		}
		if (chck(r-1)) r--;
		if (chck(r))
		printf("%d\n",r);
		else printf("-1\n");
	}		
	return 0;
}


