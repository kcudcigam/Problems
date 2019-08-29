#include<bits/stdc++.h>
using namespace std;
bool h[10];
int t;
long long n;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	read(t);
	for(int i=1;i<=t;++i){
		memset(h,0,sizeof(h));
		read(n);
		int c=0;
		while(n>0){
			int w=n%10;
			if(!h[w]){
				h[w]=1;
				c++;
			}
			n/=10;
		}
		if(c>2)cout<<2<<'\n';
		else cout<<1<<'\n';
	}
	return 0;
}


