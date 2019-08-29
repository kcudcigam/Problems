#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
void main2();
int main(){
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	int q;
	read(q);
	for(int Q=1;Q<=q;++Q)main2();
	return 0;
}
//int a[3010];
int gs(int t,int n,int p){
	long long ans=1;
	for(int i=t;i<=n;++i){
		ans=ans*i%p;
	}
	return ans;
}
void main2(){
	int n,p;
	read(n);read(p);
	int k=gs(1,n,p);
	long long ans=0;
	for(int i=2;i<=n;++i){
		if(i==2){
			ans+=k;
		}else{
			if(i%2==1){
				ans+=gs(i+1,n,p)*(i-1)*i%p;
				ans%=p;
			}
			if(i%2==0){
				ans+=gs(i+1,n,p)*(i-1)*(i-1)%p+gs(i+1,n,p)%p;
				ans%=p;
			}
		}
		ans%=p;
	}
	
	printf("%lld\n",ans);
	return;
}
/*
1234
1243
1324
1342
1423
1432
2134
2143
2314
2341
2413
2431
3124
3142
3214
3241
3412
3421
4123 
4132 3
4213 2
4231 3
4312 2
4321 0
*/
