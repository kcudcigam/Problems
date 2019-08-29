#include<bits/stdc++.h>
using namespace std;
template<typename T>void fr(T &x){
	x=0;char c=getchar();
	int f=1;
	for(;!isdigit(c);c=getchar()) if (c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-48;
	x=x*f;
}
int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	int t;
	fr(t);
	while(t--){
		int n;
		fr(n);
		int lastti=0,lastx=0,lasty=0;
		int ti,x,y,step;
		bool flg=1;
		for(int i=1;i<=n;i++){
			fr(ti),fr(x),fr(y);
			step=ti-lastti-(abs(y-lasty)+abs(x-lastx));
			if(step&1||step<0)flg=0;
			lastti=ti;
			lastx=x;
			lasty=y;
		}
		if(flg)puts("YES");
		else puts("NO");
	}
	return 0;
}


