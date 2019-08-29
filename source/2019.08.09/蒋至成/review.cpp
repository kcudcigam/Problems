#include<bits/stdc++.h>
using namespace std;
long long y;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
int main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout); 
	read(y);
	if((log(y)/log(2))==((int)(log(y)/log(2)))&&y!=1){
		int t=log(y)/log(2);
		cout<<2*t+1<<' '<<3*t<<'\n';
		for(int i=1;i<=2*t-1;i+=2){
			cout<<i<<' '<<i+1<<'\n';
			cout<<i+1<<' '<<i+2 <<'\n';
			cout<<i<<' '<<i+2<<'\n';
		}
	}
	else{
	cout<<y+1<<' '<<2*y-1<<'\n';
	for(int i=2;i<=y+1;++i)cout<<1<<' '<<i<<'\n';
	for(int i=2;i<=y;++i)cout<<i<<' '<<i+1<<'\n';
	}
	return 0;
}


