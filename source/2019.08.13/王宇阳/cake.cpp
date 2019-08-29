#include<bits/stdc++.h>
using namespace std;
inline int read(){
	   int x=0,f=1;char c=getchar();
	   while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
	   while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	   return x*f;
}
int n,m;
long long ans[350][350];
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	n=read();m=read();
	if(n>m){
		swap(n,m);
	}
	ans[1][1]=1;
	for(int i=2;i<=m;i++){
		for(int j=1;j<i;j++){
			ans[1][i]+=ans[1][j]*ans[1][i-j];
		}	
	}
	cout<<ans[n][m]<<endl;
	return 0;
}


