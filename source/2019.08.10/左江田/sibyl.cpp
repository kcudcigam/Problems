#include<iostream> 
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int read(){
	char ch;
	int num=0;
	ch=getchar();
	while(!(ch>='0'&&ch<='9')){
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		num=num*10+(ch-'0');
		ch=getchar();
	}
	return num;
}
int n,m,Q;
int u[333333],v[333333],type;
int x[333333],y[333333],st1,st2;
long long f[333333],ans;
int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	n=read();
	m=read();
	Q=read();
	for(int i=1;i<=m;++i){
		u[i]=read();
		v[i]=read();
	}
	for(int i=1;i<=Q;++i){
		type=read();
		if(type==1){
			x[i]=read();
			y[i]=read();
			st1++;
		}
		else{
			x[i]=read();
			y[i]=-1;
			st2++;
		}
	}
	if(st1>=st2){
		for(int i=1;i<=Q;++i){
			if(y[i]!=-1){
				f[x[i]]+=(1ll*y[i]);
			}
			else{
				ans=f[x[i]];
				for(int j=1;j<=m;++j){
					if(u[j]==x[i]){
						ans+=f[v[j]];
					}
					if(v[j]==x[i]){
						ans+=f[u[j]];
					}
				}
				printf("%lld\n",ans);
			}
		}
		return 0;
	}
	else{
		for(int i=1;i<=Q;++i){
			if(y[i]!=-1){
				f[x[i]]+=(1ll*y[i]);
				for(int j=1;j<=m;++j){
					if(u[j]==x[i]){
						f[v[j]]+=(1ll*y[i]);
					}
					if(v[j]==x[i]){
						f[u[j]]+=(1ll*y[i]);
					}
				}
			}
			else{
				printf("%lld\n",f[x[i]]);
			}
		}
		return 0;
	}
	return 0;
}
