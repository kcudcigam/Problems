#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,w=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-'){
			w=-1;
		}
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*w;
}
long long ci[5],n,m,i,j,k,l,s,mina,d,f[200005],r,a[200005];
long long getf(int x){
	long long ss=0,s=0;
	for(int i=0;i<=3;i++){
		ss=ci[i];
		for(int j=1;j<=i;j++){
			ss=ss*x;
		}
		s+=ss;
	}
	return s;
}
int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	n=read();
	for(i=3;i>=0;i--){
		ci[i]=read();
	}
	for(i=1;i<=n;i++){
		a[i]=read();
	}
//	cout<<endl;
	memset(f,0,sizeof(f));
	f[0]=0;
	f[1]=getf(a[1]);
	for(i=2;i<=n;i++){
		f[i]=f[i-1]+getf(a[i]);
		mina=a[i];
		/*if(i==5){
			cout<<f[i]<<" ";
		}*/
		for(j=i-1;j>=1;j--){
			mina=min(mina,a[j]);
			f[i]=max(f[i],f[j-1]+getf(mina));
			/*if(i==5){
				cout<<f[i]<<" ";
			}*/
		}
		//cout<<endl;
	}
	/*for(i=1;i<n;i++){
		cout<<f[i]<<" ";
	}*/
	cout<<f[n]<<endl;
	return 0;
}


