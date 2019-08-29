#include<bits/stdc++.h>
using namespace std;
int a[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int i,j,t,a1,cnt;
	long long n;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		cnt=0;
		scanf("%lld",&n);
		while(n){
			if(a[n%10]==0)cnt++;
			a[n%10]++;
			n/=10;
		}
		for(j=0;j<=9;j++)a[j]=0;
		if(cnt==2)printf("1\n");
		else if(cnt==3)printf("2\n");
		else printf("3\n");
	}
	return 0;
}
