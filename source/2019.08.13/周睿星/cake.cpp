#include<bits/stdc++.h>
using namespace std;
long long f[310][310],Mod=1000000007;
int read(){
	int p=1,q=0;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')p=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		q=q*10+ch-'0';
		ch=getchar();
	}
	return p*q;
}
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	int n=read(),m=read(); 
	f[1][1]=1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			for(int k=1;k<i;k++)
			f[i][j]+=(f[k][j]*f[i-k][j])%Mod;		
			for(int k=1;k<j;k++)
			f[i][j]+=(f[i][k]*f[i][j-k])%Mod;		
		}
	}
	
	cout<<f[n][m]<<endl; 
	return 0;
}


