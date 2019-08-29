#include<bits/stdc++.h>
using namespace std;
int l,r,ll,db[500010],qz[500010],len[500010],nw,k,nxt[500010];
int v,a,b,x,y,z,q[500010],duanbian;
long long dst[500010],zdl[500010];
bool f[500010];
template <typename T> void read(T &x)
{
	x=0;char c=getchar();bool flg=0;
	for (;!isdigit(c);c=getchar()) if (c=='-') flg=1;
	for (;isdigit(c);c=getchar()) x=x*10+c-'0';
	if (flg) x=-x;
}
void spfa()
{
	memset(dst,0x3f,sizeof(dst));memset(f,0,sizeof(f));
	dst[1]=0;l=1;r=1;f[1]=1;q[1]=1;
	while (l<=r)
	{
		nw=q[l];k=len[nw];
		while (k)
		{
			if ((k==duanbian*2)||(k==duanbian*2-1))
			{
				k=nxt[k];
				continue;
			}
			if (qz[k]+dst[nw]<dst[db[k]])
			{
				dst[db[k]]=qz[k]+dst[nw];
				if (f[db[k]]==0)
				{
					f[db[k]]=1;
					r++;
					q[r]=db[k];
				}
			}
			k=nxt[k];
		}
		f[nw]=0;l++;
	}
}
int main(){
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	//ios::sync_with_stdio(false);
	read(v);
	read(a);read(b);
	for (int i=1;i<=b;i++)
	{
		read(x);read(y);read(z);
		ll++;
		db[ll]=y;
		qz[ll]=z;
		nxt[ll]=len[x];
		len[x]=ll;
		ll++;
		db[ll]=x;
		qz[ll]=z;
		nxt[ll]=len[y];
		len[y]=ll;
	} 
	for (int i=1;i<=b;i++)
	{
		duanbian=i;
		spfa();
		for (int j=1;j<=a;j++) 
		if ((db[i*2]==j)||(db[i*2-1]==j)) zdl[j]=max(zdl[j],dst[j]);
	}
	cout<<0;
	for (int i=2;i<=a;i++) 
	if (zdl[i]>1000000000000000) 
	cout<<' '<<-1;
	else cout<<' '<<zdl[i];
	return 0;
}


