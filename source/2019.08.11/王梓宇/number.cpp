#include<bits/stdc++.h>
using namespace std;
int t;
long long n;
long long build_num(int ad[],int bd[],int cut){
	long long le=0;
	int min1=20,min2=20,min3=20,min4=20;
	for(int i=cut-1;i>=0;--i){
		min1=min(min1,ad[i]);
	}
	for(int i=cut-1;i>=0;--i){
		if(ad[i]>min1){
			min2=min(min2,ad[i]);
		}
	}
	for(int i=cut-1;i>=0;--i){
		if(ad[i]>min2){
			min3=min(min3,ad[i]);
		}
	}
	for(int i=cut-1;i>=0;--i){
		if(ad[i]>min3){
			min4=min(min4,ad[i]);
		}
	}
	for(int i=cut-1;i>=0;--i){
		le*=10;
		if(bd[i]==min1||bd[i]==min3){
			le+=min1;
		}
		else{
			le+=min2;
		}
	}
	return le;
}
long long work(long long x){
	int a[10];memset(a,0,sizeof(a));
	int b[1001],c[1001];
	long long y=x;
	int cut=0,ws=0,tot=0;
	while(y){
		int v=y%10;a[v]++;
		y/=10;
		ws++;
	}
	y=x;
	for(int i=0;i<=9;++i){
		if(a[i]){cut++;}
	}
	if(cut<=2){
		return 1;
	}
	if(cut==3){
		return 2;
	}
	if(cut==4){
		while(y){
			int v=y%10;b[tot]=v;tot++;
			y/=10;
		}
		for(int i=0;i<tot;++i){
			c[i]=b[i];
		}
		sort(c,c+tot);
		x-=build_num(c,b,tot);
		return work(x)+1;
	}
	if(cut>=6){
		return 3;
	}
	else return 2;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%lld",&n);
		printf("%lld\n",work(n));
	}
	return 0;
}


