#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}
long long n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long  t=read();
	while(t--){
		n=read();
		long long  a=-1,b=-1;
		a=n%10;
		n/=10;
		int f=0;
		while(n!=0){
			if(n%10!=a)
			if(b==-1){
				b=n%10;
			}else{
				if(n%10!=b){
					cout<<2<<endl;
				f=1;
				break;
				}
			}
			n=n/10;
		}
		if(f==0){
			cout<<1<<endl;
		}
	}
	return 0;
}


