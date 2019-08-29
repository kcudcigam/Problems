#include<bits/stdc++.h>
#define fir(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
long long P=1e9+7,ans=0;
int m[1010][1010]/*邻接矩阵*/,a[1010][3],t=0/*边*/,f[1010],c[1010]/*变化后*/;
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
void dfs(int dep,int n){
	if(dep==n){
		int flg=1;
		fir(i,1,t)
		    if(m[a[i][1]][a[i][2]]!=m[c[a[i][1]]][c[a[i][2]]]){
		    	flg=0;
		    	break;
			}
		if(!flg)ans++;
		if(ans>P)ans%=P;
		return;
	}
	fir(i,1,n)
	    if(!f[i]){
	    	c[dep+1]=i;
	    	f[i]=1;
	    	dfs(dep+1,n);
	    	f[i]=0;
		}
}
int main(){
	freopen("refrain","r",stdin);
	freopen("refrain","w",stdout);
	int num=read();
	int n=read(),m1=read(),m2=read();
	memset(a,0,sizeof(a));
	fir(i,1,m1)a[++t][1]=read(),a[t][2]=read(),m[a[t][1]][a[t][2]]=1,m[a[t][2]][a[t][1]]=1;
	fir(i,1,m2)a[++t][1]=read(),a[t][2]=read(),m[a[t][1]][a[t][2]]=-1,m[a[t][2]][a[t][1]]=-1;
	if(num<7||num>10){
		memset(f,0,sizeof(f));
		dfs(0,n);
		cout<<ans<<endl;
	}
	if(num>=7&&num<=10){
		long long s=1;
		fir(i,1,m1+m2)s=s*2%P;
		fir(i,1,m1)s=s*i%P;
		fir(i,1,m2)s=s*i%P;
		fir(i,1,n-(m1+m2)*2)s=s*i%P;
		ans=1;
		fir(i,1,n)ans=ans*i%P;
		cout<<(ans+P-s)%P<<endl;
	}
	return 0;
}
