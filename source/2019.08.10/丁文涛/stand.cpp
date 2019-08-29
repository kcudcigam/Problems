#include<bits/stdc++.h>
#define up(l,r,i) for(register int i=l;i<=r;++i)
#define dn(r,l,i) for(register int i=r;i>=l;--i)
using namespace std;
typedef long long LL;
const int INF =2147483647;
const int SIZ =1e5;
char bef[SIZ+3],*p1=bef,*p2=bef;
char readc(){
	if(p1==p2) p1=bef,p2=bef+fread(bef,1,SIZ,stdin);
	return p1==p2?EOF:*p1++;
}
int qread(){
	int ret,w=1,c;
	while((c=readc())> '9'||c< '0')
	w=(c=='-'?-1:1); ret=c-'0';
	while((c=readc())>='0'&&c<='9')
	ret=ret*10+c-'0';
	return ret*w;
}
const int MAXN =250+3,MAXM=1e7+3;
LL a,b,c,d,e,t1,t2,ans,cnt,n,m;
#define g(x) (a*x*x*x*x*x+b*x*x*x*x+c*x*x*x+d*x*x+e*x)
struct Node{
	LL l,r;
	Node(LL _l=0,LL _r=0):l(_l),r(_r){}
	bool operator <(Node x){return l<x.l;}
}P[MAXN];
int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	n=qread(),m=qread();
	e=qread(),d=qread(),c=qread(),b=qread(),a=qread();
	up(1,n,i) t1=qread(),t2=qread(),P[i]=Node(t1,t2);
	LL l=P[1].l,r=P[1].r; cnt=1;
	up(2,n,i){
		LL nl=max(l,P[i].l),nr=min(r,P[i].r);
		if(nl>nr) ans+=g(cnt),l=P[i].l,r=P[i].r,cnt=1;
		else cnt++,l=nl,r=nr;
	}
	ans+=g(cnt);
	printf("%lld\n",ans);
	return 0;
} 
