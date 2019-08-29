#include<bits/stdc++.h>
#define int long long
using namespace std;
void write(int x){
	if(x<0){putchar('-');write(-x);}
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int Y,n,ans=0;
int a[1010][1010];
int m[1010];
int lg(int x){
	int s=1;
	for(int i=1;i<=64;i++){
		s*=2;
		if(x<=s)return i;
	}
}
signed main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	cin>>Y;
	if(Y==1){
		cout<<2<<" "<<1<<endl;
		cout<<1<<" "<<2<<endl;
		return 0;
	}
	int n=lg(Y)+2;
	write(n);putchar(' ');write(n*(n-1)/2);putchar('\n');
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			write(i);putchar(' ');write(j);putchar('\n');
		}
	}
	return 0;
}

