#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x){
	x=0;T f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	x*=f;
}
int a[100010];
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	int n;
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i]);
	}
	
	long long ans=INT_MIN;
	for(int i=1;i<n;i++){
		int mx=a[1];
		for(int j=2;j<=i;j++){
			mx=max(mx,a[j]);
		}
		long long s1=0;
		if(mx<=0){
			s1=mx;
		}else{
			long long s=0;
			for(int j=1;j<=i;j++){
				if(s+a[j]>0){
					s+=a[j];
					s1=max(s1,s);
				}else{
					s1=max(s1,s);
					s=0;
				}
			}
		}
		mx=a[i+1];
		for(int j=i+2;j<=n;j++){
			mx=max(mx,a[j]);
		}
		long long s2=0;
		if(mx<=0){
			s2=mx;
		}else{
			long long s=0;
			for(int j=i+1;j<=n;j++){
				if(s+a[j]>0){
					s+=a[j];
					s2=max(s2,s);
				}else{
					s2=max(s2,s);
					s=0;
				}
				
			}
		}
		ans=max(ans,s1+s2);
	}
	
	cout<<ans<<endl;
	return 0;
}

