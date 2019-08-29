#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,A,B,C,D,a[200010];
long long f[200010];

inline int read(){
	int f=1,num=0; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))num=(num<<1)+(num<<3)+ch-'0',ch=getchar();
	return f*num;
}

long long g(int l,int r){
	int x=1<<30;
	for(int i=l;i<=r;i++)x=min(x,a[i]);
	return (ll)A*x*x*x+(ll)B*x*x+(ll)C*x+(ll)D;
}

int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
    n=read(),A=read(),B=read(),C=read(),D=read();
    for(int i=1;i<=n;i++)a[i]=read();
    
    for(int i=1;i<=n;i++)
	 for(int k=0;k<i;k++)
      for(int j=k;j>=0;j--)
       f[i]=max(f[i],f[k]+g(k+1,i));
    
//    long long ans=0;
//    for(int i=1;i<=n;i++)ans=max(ans,f[n][i]);
//    printf("%lld\n",ans);
    printf("%lld\n",f[n]);
	return 0;
}

