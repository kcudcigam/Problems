#include<bits/stdc++.h>
using namespace std;
int a[111];
long long reads(void){
	long long f=1;
	long long x=0;
	char ch=getchar();
	for (;!isdigit(ch);ch=getchar()){
		if (ch=='-'){
		   f=-1;
		}
	}
	for (;isdigit(ch);ch=getchar()){
		x*=10;
		x+=ch-'0';
	}
	x*=f;
	return x;
}
int main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	long long y=reads();
	int x=0;
	--y;
	int cnt=0;
	while(y>0){
		if (y&1){
			++cnt;
		}
		a[++x]=y%2;
		y/=2;
	}
	int m=x*(x+1)/2+cnt+1;
	cout<<x+2<<" "<<m<<endl;
	for (int i=1;i<=x+1;i++){
		for (int j=i+1;j<=x+1;j++){
			cout<<i<<" "<<j<<endl;
		}
	}
	cout<<1<<" "<<x+2<<endl;
	for (int i=1;i<=x+1;i++){
		if (a[i]){
			cout<<i+1<<" "<<x+2<<endl;
		}
	}
	return 0;
}


