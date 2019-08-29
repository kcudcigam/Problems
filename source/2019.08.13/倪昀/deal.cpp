#include<bits/stdc++.h>
#define fir(i,a,b) for(int i=a;i<=b;i++)
#define N 2000
using namespace std;
const long long P=1000000007;
int n,x,a[N],b[N],c[N],s[N],ans=0;
void dfs(int dep){
	if(dep==n+1){
		int sum=0,y=0;
		fir(i,1,n){
			sum+=a[i]*s[i];
			if(s[i]>0)y+=a[i]*s[i];
		}
		int flg=1;
		if(sum!=x)flg=0;
		else fir(i,1,n)
		         if(s[i]>0&&a[i]<=y-x){
		    	     flg=0;
		    	     break;
			     }
		if(flg)ans=(ans+1)%P;
		return;
	}
	fir(i,-c[dep],b[dep]){
		s[dep]=i;
		dfs(dep+1);
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
    freopen("deal.in","r",stdin);
    freopen("deal.out","w",stdout);
    n=read(),x=read();
    fir(i,1,n)a[i]=read(),b[i]=read(),c[i]=read();
    dfs(1);
    cout<<ans<<endl;
	return 0;
}
