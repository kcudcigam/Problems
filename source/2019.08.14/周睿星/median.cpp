#include<bits/stdc++.h>
using namespace std;
int a[1010],b[1010],c[2020];
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
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	int n=read(),m=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=n;++i)b[i]=read();
	
	while(m--){
		int pd=read();
		if(pd==1){
			int x=read(),y=read(),z=read();
			if(x==0)
			a[y]=z;
			else b[y]=z;
		}
		else {
			int l1=read(),r1=read(),l2=read(),r2=read(),tot=0;
			for(int i=l1;i<=r1;++i)c[++tot]=a[i];
			for(int i=l2;i<=r2;++i)c[++tot]=b[i];
			sort(c+1,c+tot+1);
			cout<<c[(tot+1)/2]<<endl;
		}
	}
	return 0;
}


