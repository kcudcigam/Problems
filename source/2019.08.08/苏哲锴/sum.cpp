#include<bits/stdc++.h> 
#define N 100001
using namespace std;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
int a[N];
int s[N];
int smax1,smax2;
int l,r;
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) read(a[i]);
	s[0]=0;
	s[1]=a[1];
	for(int i=2;i<=n;i++) s[i]+=s[i-1]+a[i];
	for(int i=0;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(s[j]-s[i]>smax1) smax1=s[j]-s[i],l=i,r=j;
			}
	}
	if(r+1<=n)
	for(int k=r+1;k<=n;k++){
	for(int z=k+1;z<=n;z++) {
				if(s[z]-s[k]>smax2) smax2=s[z]-s[k];
		}
	}
	cout<<smax1+smax2;
	return 0;
}
