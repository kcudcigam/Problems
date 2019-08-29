#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
template<typename T> void read(T &num){
	char c=getchar();T f=1;num=0;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){num=(num<<3)+(num<<1)+(c^48);c=getchar();}
	num*=f;
}
template<typename T> void qwq(T x){
	if(x>9)qwq(x/10);
	putchar(x%10+'0');
}
template<typename T> void write(T x){
	if(x<0){x=-x;putchar('-');}
	qwq(x);putchar('\n');
}
template<typename T> void chkmax(T &x,T y){x=x>y?x:y;}
int n,m;
int w[10];int f[20];
struct wzy{
	int li,ri;
}co[260];
inline long long G(int x){
	long long ret=0;
	rep(i,1,5){ret+=w[5-i+1];ret*=x;}
	return ret;
}
int t1=0;int t2=0;
inline void xj(int xl,int xr,int yl,int yr){
	if(xl>yl){swap(xl,yl);swap(xr,yr);}
	if(yl<=xr){t1=yl,t2=min(yr,xr);}
	else{t1=t2=0;}
	return;
}
int tim=0;
inline long long sol(int a[]){
	tim+=n;
	long long ret=0;int now=0;int nl=0;int nr=0;
	rep(i,1,n){
		xj(nl,nr,co[a[i]].li,co[a[i]].ri);
		if(!t1&&!t2){
			ret+=G(now);now=1;nl=co[a[i]].li;nr=co[a[i]].ri;
		}else{
			nl=t1;nr=t2;now++;
		}
	}
	if(now)ret+=G(now);
	return ret;
}

int f1[260];int f2[260];
inline bool Okay(double x,double y){
	if(x<0)return true;
	return rand()<=exp((-x)/y)*RAND_MAX;
}
inline long long SA(){
	double T=10000;
	rep(i,1,n)f1[i]=i;
	random_shuffle(f1+1,f1+n+1);
	rep(i,1,n)f2[i]=f1[i];
	int nop1=sol(f1);int nop2=nop1;int ret=nop1;
	
	while(T>0.01){
		int x=(1ll*rand()*23)%n+1;int y=(1ll*rand()*37)%n+1;
		while(x==y){y=(1ll*rand()*37)%n+1;}
		swap(f2[x],f2[y]);nop2=sol(f2);chkmax(ret,nop2);
		if(Okay(nop1-nop2,T)){nop1=nop2;swap(f1[x],f1[y]);} 
		else{swap(f2[x],f2[y]);}
		T*=0.999;
	}
	return ret;
}

int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	srand(time(NULL));

	read(n);read(m);
	rep(i,1,5)read(w[i]);
	int su1=1;
	rep(i,1,n){
		read(co[i].li);read(co[i].ri);
		if(co[i].li>co[i].ri)swap(co[i].li,co[i].ri);
	}
	rep(i,1,n){su1&=(co[i].li==1&&co[i].ri==m);}
	
	if(su1){
		long long ans=G(n);
		write(ans);
	}else if(n<=10){
		rep(i,1,n)f[i]=i;
		long long ans=0;
		do{
			chkmax(ans,sol(f));
		}while(next_permutation(f+1,f+n+1));
		write(ans);
	}else{
		long long ans=0;
		rep(i,1,50){
			chkmax(ans,SA());
			if(tim>100000000)break;
		}
		write(ans);
	}
	return 0;
}
