#include<bits/stdc++.h>
#define fir(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
long long ans[500100],cf[500100],ccf[500100],cff[500100];
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
int main(){
    freopen("sequence.in","r",stdin);
    freopen("sequence.out","w",stdout);
    int n,m;
    read(n),read(m);
    memset(ans,0,sizeof(ans));
    memset(ans,0,sizeof(cf));
    memset(ans,0,sizeof(ccf));
    memset(ans,0,sizeof(cff));
    fir(i,1,m){
    	long long l,r,s,e;
    	read(l),read(r),read(s),read(e);
    	long long k;
		if(l==r)k=0;
		else k=(e-s)/(r-l);
    	ccf[l]+=k,ccf[r+1]-=k;
		cf[r+1]-=e-s+k,cf[r+2]+=e-s+k;
    	cff[l]+=s-k,cff[r+1]-=s-k;
	}
	fir(i,1,n)cf[i]+=cf[i-1]+ccf[i];
	fir(i,1,n)ans[i]=ans[i-1]+cf[i]+cff[i];
	long long s=ans[1];
	fir(i,2,n)s=s^ans[i];
	cout<<s<<endl;
	return 0;
}

