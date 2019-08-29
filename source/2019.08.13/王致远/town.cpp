#include<bits/stdc++.h>
using namespace std;
int a,x,y,ll,db[600010],nxt[600010],len[600010],maxii,maxiii;
int maxi[600010],w[600010],l,r,q[600010],t[600010],nw,k;
bool f[600010];
template <typename T> void read(T &x)
{
	x=0;char c=getchar();bool flg=0;
	for (;!isdigit(c);c=getchar()) if (c=='-') flg=1;
	for (;isdigit(c);c=getchar()) x=x*10+c-'0';
	if (flg) x=-x;
}
int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	//ios::sync_with_stdio(false);
	read(a);memset(maxi,0,sizeof(maxi));
	for (int i=1;i<=a;i++) w[i]=i;
	for (int i=1;i<a;i++)
	{
		read(x);read(y);
		l=1;r=1;memset(f,0,sizeof(f));q[1]=x;f[x]=1;t[1]=0;maxii=0;
		while (l<=r)
		{
			nw=q[l];k=len[nw];
			while (k)
			{
				if (f[db[k]]==0)
				{
					f[db[k]]=1;
					r++;
					q[r]=db[k];
					t[r]=t[l]+1;
					if (t[r]>maxii) maxii=t[r];
				}
				k=nxt[k];
			}
			l++;
		}
		l=1;r=1;memset(f,0,sizeof(f));q[1]=y;f[y]=1;t[1]=0;maxiii=0;
		while (l<=r)
		{
			nw=q[l];k=len[nw];
			while (k)
			{
				if (f[db[k]]==0)
				{
					f[db[k]]=1;
					r++;
					q[r]=db[k];
					t[r]=t[l]+1;
					if (t[r]>maxiii) maxiii=t[r];
				}
				k=nxt[k];
			}
			l++;
		}
		maxi[w[y]]=max(maxi[w[y]],maxii+maxiii+1);
		for (int j=1;j<=a;j++)
		if (w[j]==w[x]) w[j]=w[y];
		ll++;
		db[ll]=y;
		nxt[ll]=len[x];
		len[x]=ll;
		ll++;
		db[ll]=x;
		nxt[ll]=len[y];
		len[y]=ll;
		cout<<maxi[w[y]]<<endl;
	}
	return 0;
}


