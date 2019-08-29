#include<iostream>
#include<cstdio>
using namespace std;
long long s[500005],a[500005],sum,sum1,pp,tot,f;
int main()
{
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	long long n,A,b,c,d,i,t;
	scanf("%lld%lld%lld%lld%lld",&n,&A,&b,&c,&d);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
//	if(A==0&&b==0&&c<=0){
		for(i=1;i<=n;i++){
			t=A*a[i]*a[i]*a[i]+b*a[i]*a[i]+c*a[i]+d;
			if(t>0){
				pp+=t;
				if(sum1<0){
					sum+=sum1;
				}
				sum+=t;sum1=100000000;
			}
			else{
				tot++;
				sum1=min(sum1,t);
				s[tot]=sum1;
				if(-s[tot-1]>pp&&-a[tot]>pp){
//					f++;
//					if(f==1){
						sum-=pp;sum-=max(s[tot],s[tot-1]);
//					}
//					else{
//						sum-=pp;
//						if(s[tot]<s[tot-1]){
//							sum+=s[tot]-s[tot-1];
//						}
//					}
				}
				pp=0;
			}
		}
		if(sum1!=100000000) sum+=sum1;
//	}
//	for(i=1;i<=n;i++){
//		t=A*a[i]*a[i]*a[i]+b*a[i]*a[i]+c*a[i]+d;
//		sum1=max(sum1,t);
//		if(t>0){
//			sum+=t;
//		}
//	}
//	if(sum){
//		printf("%lld",sum);
//		return 0;
//	}
//	else{
//		printf("%lld",sum1);
//	}
	printf("%lld",sum);
	return 0;
}
