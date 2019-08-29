#include<bits/stdc++.h>
#define fir(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int a[200000],s[200000]={0};
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
    freopen("sum.in","r",stdin);
    freopen("sum.out","w",stdout);
    int n=read();
    fir(i,1,n)a[i]=read(),s[i]=s[i-1]+a[i];
    int ans=-INT_MAX;
    fir(i,1,n-1)fir(j,i,n-1)fir(k,j+1,n)fir(l,k,n)
        ans=max(ans,s[j]-s[i-1]+s[l]-s[k-1]);
    cout<<ans<<endl;
	return 0;
}
