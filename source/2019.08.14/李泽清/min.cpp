#include<bits/stdc++.h>
#define LL long long
#define F(x,y,z) for (int x=y;x<=z;++x)
#define D(x,y,z) for (int x=y;x>=z;--x)
#define ls (id<<1)
#define rs ((id<<1)|1)
using namespace std;
const int N=200010;
const LL Inf=4000000000000000000ll;
inline LL R(){
	LL x=0,f=1;char c=getchar();
	for (;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for (; isdigit(c);c=getchar())x=x*10+c-'0';
	return x*f;
}
LL n,p,ll,rr;
LL A,B,C,D,zf,zt,an;
LL a[N];
LL stk[N],q[N],tp;
LL ff(LL x){return A*x*x*x+B*x*x+C*x+D;}
struct Tree{
	LL t[N*4],tag[N*4],f[N*4];
	void Build(int id,int tl,int tr){
		t[id]=f[id]=tag[id]=-Inf;
		if(tl==tr)return;
		int mid=(tl+tr)>>1;
		Build(ls,tl,mid);
		Build(rs,mid+1,tr);
	}
	void Down(int id){
		if(tag[id]==-Inf)return;
		tag[ls]=tag[rs]=tag[id];
		t[ls]=f[ls]+tag[id];
		t[rs]=f[rs]+tag[id];
		tag[id]=-Inf;
	}
	void Insf(int id,int tl,int tr){
		if(tl==tr){f[id]=zf;t[id]=zt;return;}
		Down(id);
		int mid=(tl+tr)>>1;
		if(p<=mid)Insf(ls,tl,mid);
		else Insf(rs,mid+1,tr);
		f[id]=max(f[ls],f[rs]);
		t[id]=max(t[ls],t[rs]);
	}
	void Inst(int id,int tl,int tr){
		if(ll<=tl&&tr<=rr){t[id]=f[id]+zt;tag[id]=t[id];return;}
		Down(id);
		int mid=(tl+tr)>>1;
		if(ll<=mid)Inst(ls,tl,mid);
		if(rr> mid)Inst(rs,mid+1,tr);
		t[id]=max(t[ls],t[rs]);
	}
	void pr(){
		F(i,1,13)printf("%d: t:%lld f:%lld tag%lld\n",i,t[i],f[i],tag[i]);
	}
}T;

int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	n=R();A=R();B=R();C=R();D=R();
	F(i,1,n)a[i]=R();
	T.Build(1,0,n);
	T.Insf(1,0,n);
	tp=1;stk[1]=-Inf;q[1]=0;
	F(i,1,n){
		while(a[i]<stk[tp])--tp;
		zt=ff(a[i]);ll=q[tp];rr=i-1;
		//cerr<<ll<<' '<<rr<<'\n';
		T.Inst(1,0,n);
		//T.pr();
		an=T.t[1];
		zf=an;p=i;
		//cout<<T.t[1]<<'\n';
		T.Insf(1,0,n);
		++tp;stk[tp]=a[i];q[tp]=i;
	}
	cout<<an<<'\n';
	return 0;
}
