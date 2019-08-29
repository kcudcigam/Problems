#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 200200
int n,a,b,c,d;
int s[N];
#define ll long long
inline void read(int &x){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	x=s*w;
	return ;
}
ll F(int x){
	return 1ll*a*x*x*x+1ll*b*x*x+1ll*c*x+1ll*d;
}
ll f[N];//f[i]表示前i个数的最大贡献 
int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout); 
	read(n),read(a),read(b),read(c),read(d);
	for(int i=1;i<=n;i++) read(s[i]),f[i]=-1e14;
	if(n<=1000){
		f[0]=0;
		for(int i=1;i<=n;i++){
			int minn=s[i],now;
			for(int j=i-1;j>-1;j--){
				if(f[i]<f[j]+F(minn)) now=j;
				f[i]=max(f[i],f[j]+F(minn));
				minn=min(minn,s[j]);
			}
		}
		cout<<f[n];
	}
	else if(a==0&&b==0){
		int minn,now;
		f[0]=0,f[1]=F(s[1]),now=0,minn=s[1];
		for(int i=2;i<=n;i++){
			minn=min(minn,s[i]);
			if(f[now]+F(minn)<=f[i-1]+F(s[i])){
				f[i]=f[i-1]+F(s[i]),minn=s[i],now=i-1;
			}
			else f[i]=f[now]+F(minn);
		}
		cout<<f[n];
	}
	return 0;
}
