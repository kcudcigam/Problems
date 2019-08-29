#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=100010;
int a[N];
inline int read(){
	int ret=0,f=1;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())ret=(ret<<3)+(ret<<1)+ch-'0';
	return ret*f;
}
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	ll n=read(),sumnow=0,summax=0;
	int End=0,Start=0;
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++){
		sumnow+=a[i];
		if(sumnow>summax)summax=sumnow,End=i;
		if(sumnow<0)sumnow=0;
	}
	ll tsummax=summax;
	for(int i=End;tsummax;i--){
		tsummax-=a[i];
		Start=i;
	}
	if(Start==1&&End==n){//如果一开始到结尾全部被包含 
		ll T=0,Min=2147483647;
		for(int i=1;i<=n;i++){
			T+=a[i];
			if(T<Min)Min=T;
			if(T>0)T=0;
		}
		printf("%lld\n",summax-Min);
		return 0;
	}
	ll lmax=0,rmax=0,t=0;
	for(int i=1;i<Start-1;i++){
		t+=a[i];
		if(t>lmax)lmax=t;
		if(t<0)t=0;
	}
	t=0;
	for(int i=End+1;i<=n;i++){
		t+=a[i];
		if(t>rmax)rmax=t;
		if(t<0)t=0;
	}
	printf("%lld\n",(ll)max(lmax,rmax)+summax);
	
	return 0;
}


