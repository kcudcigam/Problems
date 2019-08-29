#include<bits/stdc++.h>
using namespace std;
const long long MOD=1e9+7;
int g[22][22];
int now[22];
bool usd[22];
long long sum=0;
long long n;
void tryit(int depth){
	if (depth>n){
		bool flag=false;
		for (int i=1;i<=n;i++){
			if (flag){
				break;
			}
			for (int j=1;j<i;j++){
				if (g[i][j]!=g[now[i]][now[j]]){
					if (g[i][j]>0){
						flag=true;
						break;
					}
				}
			}
		}
		if (flag){
			++sum;
		}
		return;
	}
	for (int kk=1;kk<=n;kk++){
		if (usd[kk]){
			usd[kk]=false;
			now[depth]=kk;
			tryit(depth+1);
			usd[kk]=true;	
		}
	}
	return;
}
long long reads(void){
	long long f=1;
	long long x=0;
	char ch=getchar();
	for (;!isdigit(ch);ch=getchar()){
		if (ch=='-'){
		   f=-1;
		}
	}
	for (;isdigit(ch);ch=getchar()){
		x*=10;
		x+=ch-'0';
	}
	x*=f;
	return x;
}
int main(){
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	long long N=reads();
	n=reads();
	long long m1=reads();
	long long m2=reads();
	memset(g,0,sizeof(g));
	for (int i=1;i<=m1;i++){
		long long x=reads();
		long long y=reads();
		if (N<=6){
			g[x][y]=1;
			g[y][x]=1;
		}
	}
	for (int i=1;i<=m2;i++){
		long long x=reads();
		long long y=reads();
		if (N<=6){
			g[x][y]=2;
			g[y][x]=2;
		}
	}
	if (N>=7){
		long long tot=n*(n-1)/2;
		long long nu=tot-m1-m2;
		long long ans=1;
		ans*=m1*(tot-m1);
		ans%=MOD;
		ans*=m2*(tot-m2);
		ans%=MOD;
		ans*=nu;
		ans%=MOD;
		cout<<ans<<endl;
	}
	else {
		memset(usd,true,sizeof(usd));
		tryit(1);
		cout<<sum%MOD<<endl;
	}
	return 0;
}


