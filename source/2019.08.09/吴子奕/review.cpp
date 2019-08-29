#include<bits/stdc++.h>
using namespace std;
int a[10000000];
int t;
int n,m;
long long y;
int main(){
	freope("review.in","r",stdin);
	freopen("review.out","w",stdout);
cin>>y;
int step;step=0; t=0;
while(y!=0){
	if(y%2!=0){t++;
		a[t]=step;
		y--;
	}
	y/=2;
	step++;
}
n=(a[t]*2+2);
m=4*a[t]+t-1;cout<<n<<" "<<m<<endl;
if(a[t]==0){
	cout<<1<<" "<<n;
}int x;x=2;

for(int i=1;i<=a[t];i++){

	if(x-2)cout<<x-2<<" "<<x<<endl;
	if(x-2)cout<<x-2<<" "<<x+1<<endl;
	if(x-1)cout<<x-1<<" "<<x+1<<endl;
	if(x-1)cout<<x-1<<" "<<x<<endl;
x+=2;
}x-=2;if(x)cout<<x<<" "<<n<<endl<<x+1<<" "<<n<<endl;
if(t>=2){
	for(int i=t-1;i>=1;i--){
		int x=a[i];
		if(x==0){
			cout<<1<<" "<<n<<endl;continue;
		}
		cout<<4*x<<" "<<n<<endl;
	}
}

	return 0;
}
