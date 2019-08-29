#include<bits/stdc++.h>
using namespace std;
#define ll long long
template <typename T> void fr(T &x){
	T f=1;char c=getchar();x=0;
	for(;!isdigit(c);c=getchar()) if(c=='-')f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
const int N=500010;
int a[N],b[N],n,m;
int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	fr(n),fr(m);
	
	for(int i=1;i<=n;i++)fr(a[i]);
	for(int i=1;i<=n;i++)fr(b[i]);
	
	int opt,x,y,z,l1,r1,l2,r2;
	while(m--){
		fr(opt);
		if(opt==1){
			fr(x);
			fr(y);fr(z);
			if(x){
				b[y]=z;
			}else a[y]=z;
		}else{
			fr(l1),fr(r1),fr(l2),fr(r2);
			int t=r1-l1+1+r2-l2+1;
			t=t/2+1;
			int ans;
			for(int i=1;i<=t;i++){
				if(l1>r1){
					ans=b[l2];
					l2++;
				}else if(l2>r2){
					ans=a[l1];
					l1++;
				}else{
					if(a[l1]<=b[l2]){
						ans=a[l1];
						l1++;
					}else{
						ans=b[l2];
						l2++;
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}


