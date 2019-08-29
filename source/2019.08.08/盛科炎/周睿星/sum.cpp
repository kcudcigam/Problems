#include<bits/stdc++.h>
using namespace std;
long long a[100010],sum=0,f[100010],pd[100010],s[100010];
int read(){
	int p=1,q=0;
	char ch;
	ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
		p=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		q=q*10+ch-'0';
		ch=getchar();
	}
	return p*q;
}
int main(){
	freopen("sum","r",stdin);
	freopen("sum","w",stdout);
	memset(pd,0,sizeof(pd));
	int n;
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		s[i]=s[i-1]+a[i];
	}
	int	start=0,end=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=i;++j){
			for(int x=1;x<i;++x){
				for(int y=1;y<=x;++y){
				if(s[i]-s[j-1]+s[x]-s[y-1]>sum){
				sum=s[i]-s[j-1]+s[x]-s[y-1];
					}
				}                                                                                             	
			}	
			for(int x=j+1;x<=n;++x){
				for(int y=j+1;y<=x;++y){
				if(s[i]-s[j-1]+s[x]-s[y-1]>sum){
				sum=s[i]-s[j-1]+s[x]-s[y-1];
					}
				}                                                                                             	
			}	
		}                                                                                             	
	}
		
	cout<<sum<<endl;
	return 0;
}
