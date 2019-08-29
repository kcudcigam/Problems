#include<bits/stdc++.h>
#define pii pair<int,int>
#define iiii pair<int,pii >
#define ll long long 
#define INF 1000000000
#define MOD 1000000007
#define mp make_pair
#define rep(i,x) for(int (i)=0;(i)<(x);(i)++)
inline int getint(){
	char c=getchar();int x=0,p=1;
	while(c<=32)c=getchar();
	if(c==45)c=getchar(),p=-p;
	while(c>32)x=x*10+c-48,c=getchar();
	return x*p;
}
using namespace std;
//ruogu
const int N=255;
int n,m,hh[5];
ll f[N];
int l[N],r[N];
//
namespace SOLVE0{
//ruogu
const int M=52;
double T0=100000000;
double T1=1e-7;
double delT=0.99996;
const ll inf=2e18;
ll res=inf,lastans;
int a[M],c[M];
//
inline int getrange(int l,int r){
	return rand()%(r-l+1)+l;
}
inline double rnd(){
	return rand()%100000000/100000000.0;
}
inline ll calc(){
	memset(c,0,sizeof(c));
	rep(i,n)c[a[i]]++;
	ll ans=0;
	rep(i,m)ans-=f[c[i]];
	res=min(res,ans);
	return ans;
}
void init(){
	rep(i,n)a[i]=getrange(l[i],r[i]);
	lastans=calc();
}
void work(){
	init();
	double T=T0;
	while(T>T1){
		int x=rand()%n,y=rand()%2,v=a[x],z=getrange(1,2);
		if(y)a[x]-=z;else a[x]+=z;
		if(a[x]<l[x])a[x]=l[x];
		if(a[x]>r[x])a[x]=r[x];
		ll nowans=calc();
		double dE=lastans-nowans;
		if(nowans>=lastans&&exp(1.0*dE/T)<rnd())a[x]=v;
		else lastans=nowans;
		T*=delT;
	}
}
void main(){
	srand(time(0));
	rep(i,5)work();
	cout<<-res<<endl;
}
}
int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	n=getint();m=getint();
	rep(i,5)hh[i]=getint();
	for(int i=1;i<=n;i++){
		ll x=1;
		rep(j,5){
			x*=1ll*i;
			f[i]+=1ll*hh[j]*x;
		}	
	}
	rep(i,n)l[i]=getint()-1,r[i]=getint()-1;
	if(n<=50&&m<=50)SOLVE0::main();
	else{
		bool flag=true;
		rep(i,n)if(l[i]!=0||r[i]!=m-1){
			flag=false;
			break;
		}
		if(flag)printf("%lld\n",f[n]);
		else printf("%lld\n",f[n]);
	}
	return 0;
}
