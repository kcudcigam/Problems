#include<bits/stdc++.h>
#include<cctype>
using namespace std;
inline int read(){
	int x=0,w=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-'){
			w=-1;
		}
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*w;
}
const int maxn=10000007;
long long f[maxn],ff[maxn],a[maxn],p[maxn],maxa,n,m,i,j,k,l,s,d,r;
int main(){
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	n=read();
	maxa=0;
	for(i=1;i<=n;i++){
		a[i]=read();
		p[i]=read();
		maxa=max(maxa,a[i]);
	}
	for(i=1;i<=maxa;i++){
		if((i&1)){
			ff[i]=(i-1)*i;
		}
		else{
			ff[i]=(i-1)*(i-1)+1;
		}
	}
	ff[0]=0;
	memset(f,0,sizeof(f));
	for(i=1;i<=n;i++){
		f[0]=0;
		for(j=1;j<=a[i];j++){
			f[j]=f[j-1]*(j)+ff[j];
			f[j]=f[j]%p[i];
		}
		cout<<f[a[i]]<<endl;
	}
	return 0;
}


