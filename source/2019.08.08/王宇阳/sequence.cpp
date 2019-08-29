#include<bits/stdc++.h>
using namespace std;
inline long long  read(){
	long long x=0,f=1;
	char c=getchar();
	while(c>'9' || c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
	return x*f;
}
long long n,m;
long long a[500005]={0};
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read();
	m=read();
	while(m--){
		long long l=read(),r=read(),s=read(),e=read();
		int gc=(e-s)/(r-l);
		for(int i=l;i<=r;i++){
			a[i]+=s+gc*(i-l);
		}
	}
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<' ';
//	}
//	cout<<endl;
	int yh=a[1];
	for(int i=1;i<n;i++){
		yh=yh^a[i+1];
	}
	cout<<yh<<endl;
	return 0;
}


