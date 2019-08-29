#include<bits/stdc++.h>
using namespace std;
struct q
{
	int s,fq,cs,zz;
};
q t[400010];
int a,b,c,db[400010],len[400010],nxt[400010],h,maxi,w[400010],x,y,l,ll;
bool f,ff[400010];
template <typename T> void read(T &x)
{
	x=0;char c=getchar();bool flg=0;
	for (;!isdigit(c);c=getchar()) if (c=='-') x=-x;
	for (;isdigit(c);c=getchar()) x=x*10+c-'0';
	if (flg) x=-x;
}
void wrk(int u)
{
	int k=len[u];
	while (k)
	{
		if (t[db[k]].fq==0)
		{
			t[db[k]].fq=u;
			t[db[k]].s=t[u].s+1;
			wrk(db[k]);
		}
		k=nxt[k];
	}
}
bool cmp(q p,q pp)
{
	return p.s>pp.s;
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	read(a);
	for (int i=1;i<=a;i++)
	{
		read(b);read(c);
		memset(t,0,sizeof(t));
		memset(db,0,sizeof(db));
		memset(len,0,sizeof(len));
		memset(nxt,0,sizeof(nxt));
		for (int j=1;j<b;j++)
		{
			read(x);read(y);
			db[j*2-1]=y;
			nxt[j*2-1]=len[x];
			len[x]=j*2-1;
			db[j*2]=x;
			nxt[j*2]=len[y];
			len[y]=j*2;
		}
		for (int j=1;j<=b;j++)
		read(t[j].cs);
		for (int j=1;j<=b;j++)
		read(t[j].zz);
		t[1].s=1;
		wrk(1);
		memset(ff,1,sizeof(ff));
		for (int j=1;j<=b;j++)
		{
			maxi=0;h=0;
			for (int k=1;k<=b;k++)
			if ((ff[k])&&(t[k].s>maxi))
			{
				maxi=t[k].s;
				h=k;
			}
			w[j]=h;ff[h]=0;
		}
		h=0;
		for (int j=1;j<=b;j++)
		{
			if (t[w[j]].s<c) 
			{
				h=j;
				break;
			}	
			if (t[w[j]].cs!=t[w[j]].zz)
			{
				l=0;ll=w[j];
				while (l<c)
				{
					if (t[ll].cs==0)
					t[ll].cs=1;
					else t[ll].cs=0;
					l++;
					ll=t[ll].fq;
				}
			}		
		}
		f=1;
		for (int j=h;j<=b;j++)
		if (t[w[j]].cs!=t[w[j]].zz)
		{
			f=0;
			break;
		}
		if (f) 
		cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}

