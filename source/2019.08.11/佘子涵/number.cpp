#include<cstdio>
#include<iostream>
using namespace std;
template <typename T> void read(T &x){
	long long f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f= -f;
	for (; isdigit(c);c=getchar()) x=x*10+c -'0';
	x*=f;
}
int n,x;
bool us[11];
bool pd(int x){
	int nu=0;
	for(int i=0;i<=9;i++) us[i]=0;
	while(x){
		if(!us[x%10]) us[x%10]=1,nu++;
		if(nu>2) break;
		x/=10;
	}
	if(nu>2) return 0;
	return 1;
}
int so(int x){
	if(pd(x)) return 1;	
	if(x<100000) return 2;
	int ans=0x7f7f7f7f;
	for(int i=x>>1;i<x;i++){
		if(pd(i)){
			ans=min(ans,1+so(x-i));
			if(ans==2) break;
		}
	}
	return ans;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++){
		read(x);
		printf("%d\n",so(x));
	}
	return 0;
}

