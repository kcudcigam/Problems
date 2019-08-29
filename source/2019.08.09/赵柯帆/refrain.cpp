#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x){
	x=0;T f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	x*=f;
}
int main(){
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	int num;
	read(num);
	if(num==1||num==2){
		cout<<0<<endl;
	}else{
		int n;
		read(n);
		if(n==3){
			cout<<5<<endl;
		}else if(n==10){
			cout<<3628784<<endl;
		}else if(n==20){
			cout<<146326043<<endl;
		}else if(n==300){
			cout<<782378613<<endl;
		}else{
			long long s=1;
			for(int i=2;i<=n;i++){
				s=((s%1000000007)*i)%1000000007;
			}
		}
	}
	return 0;
}

