#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010],b[500010],c[1000010];
int Read() {
	char c=getchar();
	int x=0,k=1;
	for(;c<'0'||c>'9';c=getchar())
		if(c=='-') k=-1 ;
	for(;c>='0'&&c<='9';c=getchar())
		x=x*10-'0'+c;
	return x*k;
}
void Merge(int l1,int r1,int l2,int r2){
	int i=l1,j=l2,k=0;
	while(i<=r1&&j<=r2){
		if(a[i]>b[j]){
			k++;
			c[k]=b[j];
			j++;
		}else{
			k++;
			c[k]=a[i];
			i++;
		}
	}
	while(i<=r1)
		c[++k]=a[i++];
	while(j<=r2)
		c[++k]=b[j++];
		
	cout<<c[(1+k)>>1]<<endl;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=Read();
	m=Read();
	for(int i=1;i<=n;++i){
		a[i]=Read();
	}
	for(int i=1;i<=n;++i){
		b[i]=Read();
	}
	
	int p;
	for(int i=1;i<=m;++i){
		p=Read();
		if(p==1){
			int x,y,z;
			x=Read(),y=Read(),z=Read();
			if(x==0) a[y]=z;
			else b[y]=z;
		}
		if(p==2){
			int l1,l2,r1,r2;
			l1=Read(),r1=Read(),l2=Read(),r2=Read();
			Merge(l1,r1,l2,r2);
		}
	}
	
	return 0;
}

