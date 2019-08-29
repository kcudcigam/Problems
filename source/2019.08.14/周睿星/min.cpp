#include<bits/stdc++.h>
using namespace std;
long long f[1010][1010],A,B,C,D,n;
int a[200010],k[1010][1010];
void ST(){
	for(int i=1;i<=n;++i)k[i][0]=a[i];
	int t=log(n)/log(2)+1;
	for(int j=1;j<t;++j){
		for(int i=1;i<=n-(1<<j)+1;++i){
			k[i][j]=min(k[i][j-1],k[i+(1<<(j-1))][j-1]);
		}
	}
}
int q(int l,int r){
	int s=log(r-l+1)/log(2);
	return min(k[l][s],k[r-(1<<s)+1][s]);
}
long long calc(long long x){
	return x*x*x*A+x*x*B+x*C+D;
}
int read(){
	int p=1.,q=0;
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
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	n=read();
	A=read(),B=read(),C=read(),D=read();
	for(int i=1;i<=n;++i)a[i]=read();
	ST();
	if(A==B==0&&C<=0){
	int ans=0,flg=false;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		if(calc(a[i])<0){
			break;
		}
		else{
			flg=true;
			ans+=calc(a[i]);	
		}
	}
	if(flg==false)
	cout<<calc(a[1])<<endl;
	else
	cout<<ans<<endl;	
	}
	else {
	for(int i=1;i<=n;++i)f[i][i]=calc(a[i]);
	for(int len=2;len<=n;++len)
		for(int l=1;l<=n-len+1;++l){
			long long r=l+len-1,minn=INT_MAX;
			minn=q(l,r);
			f[l][r]=calc(minn);
			for(int k=1;k<r;++k){
				f[l][r]=max(f[l][r],f[l][k]+f[k+1][r]);
			}
		}
	cout<<f[1][n]<<endl;
	}
	return 0;
}
