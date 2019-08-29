#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x){
	x=0;T f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	x*=f;
}
int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	long long n,a,b,c,d;
	read(n);read(a);read(b);read(c);read(d);
	
	if(a==0&&b==0&&c<=0){
		if(c==0){
			if(d>=0){
				cout<<n*d<<endl;
			}else{
				cout<<d<<endl;
			}
		}else{
			long long ans=0;
			int mn=INT_MAX;
			bool flg=false;
			for(int i=1;i<=n;i++){
				int x;
				read(x);
				mn=min(x,mn);
				if(x*c+d>=0){
					ans+=x*c+d;
					flg=true;
				}
			}
			if(!flg){
				ans=mn*c+d;
			}
			cout<<ans<<endl;
		}
	}else{
		long long ans=0;
		int mn=INT_MAX;
		bool flg=false;
		for(int i=1;i<=n;i++){
			int x;
			read(x);
			mn=min(x,mn);
			if(((a*x+b)*x+c)*x+d>=0){
				ans+=((a*x+b)*x+c)*x+d;
				flg=true;
			}
		}
		if(!flg){
			ans=((a*mn+b)*mn+c)*mn+d;
		}
		cout<<ans<<endl;
	}
	return 0;
}


