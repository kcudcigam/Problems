#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define mo 1000000007
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
template<typename T> void chkmin(T &x,T y){x=x<y?x:y;}
template<typename T> void chkmax(T &x,T y){x=x>y?x:y;} 
int n,m,q;
struct wzy{
	int xi,yi,pi;
}co[100010];
bool in[100010];int l[100010];int r[100010];int s[100010];
int a[100010];int b[100010];
long long ans=0;int yy=0;
inline int poww(int n,int m){
	int tmp=m;int ret=1;int temp=n;
	while(tmp){
		if(tmp&1)ret=(1ll*ret*temp)%mo;
		temp=(1ll*temp*temp)%mo;
		tmp>>=1;
	}
	return ret;
}
inline void dfs(int dep,int p){
	if(dep>n){
		rep(i,1,m)s[i]=INT_MAX;
		rep(i,1,n){
			if(in[i])chkmin(s[co[i].xi],co[i].yi);
		}
		long long nop=0;
		rep(i,1,q){
			int tmp=0;
			rep(j,l[i],r[i]){
				if(s[j]!=INT_MAX)chkmax(tmp,s[j]);
			}
			nop+=tmp;
		}
		ans+=(1ll*nop*p)%mo;ans%=mo;
	}else{
		in[dep]=1;
		dfs(dep+1,(1ll*p*co[dep].pi)%mo);
		in[dep]=0;
		dfs(dep+1,(1ll*p*(mo+a[dep]-co[dep].pi))%mo);
	}
} 

int main(){
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	
	read(n);read(m);read(q);
	rep(i,1,n){read(co[i].xi);read(co[i].yi);read(co[i].pi);}
	rep(i,1,n){
		int ret=1;int x=co[i].pi;
		for(int j=2;j<=30;j++){
			int tmp=poww(j,mo-2);
			while(x%tmp==0){ret*=j;x/=tmp;}
		}
		a[i]=(ret*co[i].pi)%mo;write(a[i]);
	}
	rep(i,1,q){read(l[i]);read(r[i]);}
	
	if(n==q){
		
	}else{dfs(1,1);write(ans);}
	return 0;
}
