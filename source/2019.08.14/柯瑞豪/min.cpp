#include<bits/stdc++.h>
using namespace std;
const int N=200010,inf=2147483647;
int n,t,B[5];
int A[N];
long long ans,C[N];
inline int read(){
	register int x=0;register int w=1;
	register char c;
	while(!isdigit(c=getchar()))if(c=='-')w=-1;
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+(c&15);
		c=getchar();
	}
	return x*w;
}
long long cal(int x){
	long long a=(long long)x,aans=(long long)B[4];
	for(int i=3;i;i--){
		aans+=a*(long long)B[i];
		a*=a;
	}
	return aans;
}
long long max(long long a,long long b){
	return a>b?a:b;
}
int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
    n=read();
    for(int i=1;i<5;i++)B[i]=read();
    for(int i=1;i<=n;i++)A[i]=read();
    if(B[1]==0&&B[2]==0){
		if(B[3]==0){
			if(B[4]<=0){cout<<B[4]<<endl;exit(0);}
			if(B[4]>0){cout<<(long long)((long long)B[4]*(long long)n)<<endl;exit(0);}
		}
		if(B[3]<0){
			int d=abs(B[4])/abs(B[3]);
			if(B[4]<0)d=-d-1;
			int Mi=inf;
			for(int i=1;i<=n;i++){
				Mi=min(Mi,A[i]);
				if(A[i]<=d)ans+=cal(A[i]);
			}
			if(Mi>d)cout<<cal(Mi)<<endl;
		    else cout<<ans<<endl;
	    	exit(0);
		}
	}
    long long Mx=-inf;
    for(int i=1;i<=n;i++)C[i]=cal(A[i]),Mx=max(Mx,C[i]);
    if(Mx<=0){cout<<Mx<<endl;exit(0);}
    for(int i=1;i<=n;i++){
    	if(C[i]){
    		int l=i-1,r=i+1;
    		while(l>0&&C[l]>=C[l+1]){C[l]=max(0,C[l]);l--;}
    		while(r<=n&&C[r]<=C[r-1]){C[r]=max(0,C[r]);r++;}
		}
	}
	for(int i=1;i<=n;i++)ans+=C[i];
	cout<<ans<<endl;
	return 0;
}
