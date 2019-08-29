#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
long long a[1111],sm[1111],maxans;
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
		sm[i]=sm[i-1]+a[i];
	}
	maxans=-100000000000000;
	for(int rA=1;rA<=n;++rA){
		for(int rB=rA+1;rB<=n;++rB){
			for(int lA=1;lA<=rA;++lA){
				for(int lB=rA+1;lB<=rB;++lB){
					maxans=max(maxans,(sm[rA]-sm[lA]+sm[rB]-sm[lB]));
				}
			}
		}
	}
	printf("%lld",maxans);
	return 0;
} 
