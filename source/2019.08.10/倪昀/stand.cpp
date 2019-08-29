#include<bits/stdc++.h>
#define fir(i,a,b) for(int i=a;i<=b;i++)
#define N 1000
#define M 20000000
using namespace std;
int n,m,k[10],s[M],f[N],b[N],ans=0;
struct info{
	int l,r;
}a[N];
inline int Func(int x){
	int sum=0;
	int tmp=x;
	fir(i,1,5)sum+=k[i]*tmp,tmp*=x;
	return sum;
}
void dfs(int dep){
	if(dep==n+1){
		int sum=0;
		fir(i,1,m)sum+=f[s[i]];
		if(sum>ans)ans=sum;
		return;
	}
	fir(i,a[dep].l,a[dep].r){
		s[i]++;
		dfs(dep+1);
		s[i]--;
	}
}
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+c-48;
		c=getchar();
	}
	return x*f;
}
int main(){
    freopen("stand.in","r",stdin);
    freopen("stand.out","w",stdout);
    n=read(),m=read();
    fir(i,1,5)k[i]=read();
    int flg=1;
    fir(i,1,n){
    	a[i].l=read(),a[i].r=read();
    	if(a[i].l>1||a[i].r<m)flg=0;
	}
	fir(i,1,n)f[i]=Func(i);
	memset(s,0,sizeof(s));
    if(flg&&n<=m){
    	memset(b,0,sizeof(b));
    	fir(i,1,n)
    	    fir(j,i,n)
    	        b[j]=max(b[j],b[j-i]+f[i]);
    	ans=b[n];
	}else dfs(1);
    cout<<ans<<endl;
	return 0;
}
