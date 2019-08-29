#include<bits/stdc++.h>
#define F(i,a,b) for (register int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define ms(a,b) memset(a,b,sizeof a);
#define LL long long
#define pb push_back
#define SZ(x) (int)x.size()-1
#pragma GCC optimize("Ofast")
using namespace std;
inline int read(){
	register char ch=getchar(); register int w=1,c=0;
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=5e5+10;
int rt[M],tot,tg[M*22],L[M*22],R[M*22];
int n,q;
#define mid (l+r>>1)
int Find(int x){
	if (rt[x]==x) return x;
	return rt[x]=Find(rt[x]);
}
inline void pushdown(int x,int l,int r){
	if (!tg[x] || l==r) return ;
	tg[L[x]]+=tg[x]; tg[R[x]]+=tg[x];
	tg[x]=0;
}
inline void lay(int x,int d){
	int u=Find(x);
	tg[rt[u]]+=d;
}
int Merge(int x,int y,int l,int r){
	if (!x || !y) return x|y;	
	pushdown(x,l,r); pushdown(y,l,r);
	L[x]=Merge(L[x],L[y],l,mid);
	R[x]=Merge(R[x],R[y],mid+1,r);
	return x;
}
int query(int x,int l,int r,int p){
	if (l==r) return tg[x];	
	pushdown(x,l,r);
	if (p<=mid) return query(L[x],l,mid,p);
	return query(R[x],mid+1,r,p);
}
void ins(int &x,int l,int r,int p){
	if (!x) x=++tot;
	if (l==r) return ;	
	if (p<=mid) ins(L[x],l,mid,p);
	else ins(R[x],mid+1,r,p);
}
void out(){
	F(i,1,n){
		int u=Find(i);
		cout<<query(rt[u],1,n,i)<<" ";
	}
	cout<<"-------\n"<<tg[14]<<"\n";
}
short stk[20],len=0;
inline void out(int x){
	len=0;
	if (!x) return putchar('0'),void();
	while (x){
		stk[len++]=x%10;
		x/=10;
	}
	while (len--) putchar(stk[len]+'0');
}
int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	n=read(); q=read(); tot=n;
	F(i,1,n) rt[i]=i,ins(rt[i],1,n,i);
	while (q--){
		int tp=read(),x=read(),y=read();
		if (tp==1){
			register int u=Find(x),v=Find(y);
			if (u==v) continue;
			rt[u]=Merge(rt[u],rt[v],1,n);
			rt[v]=rt[u];
		}
		else lay(x,y);
	}
	F(i,1,n){
		int u=Find(i);
		out(query(rt[u],1,n,i));	 putchar(' ');
	}
	return 0;
}


