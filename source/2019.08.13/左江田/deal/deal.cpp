#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,x;
int a[1111],b[1111],c[1111];
int fy[22222],fp[22222],fly[22222],flp[22222];
long long ans;
int main(){
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	scanf("%d %d",&n,&x);
	for(int i=1;i<=n;++i){
		scanf("%d %d %d",&a[i],&b[i],&c[i]);
	}
	fy[0]=1;
	fp[0]=1;
	for(int i=n;i>=1;--i){
		for(int j=0;j<=2*x;++j){
			fly[j]=fy[j];
			flp[j]=fp[j];
		}
		for(int j=0;j<=x;++j){
			if(fy[j]!=0){
				for(int k=1;k<=b[i];++k){
					if((j+k*a[i]-x)<a[i]){
						fly[j+k*a[i]]+=fy[j];
					}
					else{
						break;
					}
				}
			}
		}
		for(int j=0;j<=x;++j){
			if(fp[j]!=0){
				for(int k=1;k<=c[i];++k){
					if((j+k*a[i]-x)<=(2*x)){
						flp[j+k*a[i]]+=fp[j];
					}
					else{
						break;
					}
				}
			}
		}
		for(int j=0;j<=2*x;++j){
			fy[j]=fly[j];
			fp[j]=flp[j];
		}
	}
	ans=0;
	for(int i=x;i<=2*x;++i){
		ans+=(1ll*fy[i]*fy[i-x]);
		ans%=1000000007;
	}
	printf("%lld",ans);
} 
