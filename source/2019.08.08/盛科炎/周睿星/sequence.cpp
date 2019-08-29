#include<bits/stdc++.h>
using namespace std;
long long a[500010],b[500010];
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
	freopen("sequence","r",stdin);
	freopen("sequence","w",stdout);
	int m,n;
	n=read();
	m=read();
	memset(a,0,sizeof(0));
	int l,r,s,e,ave;
	m-=1;
	l=read();
	r=read();
	s=read();
	e=read();
	if(s!=e){
		ave=(e-s)/(r-l-1);
		for(int i=l;i<=r;++i)a[i]=a[i]+(i-l)*ave+s;	
		while(m--){
		l=read();
		r=read();
		s=read();
		e=read();
		ave=(e-s)/(r-l-1);
		for(int i=l;i<=r;++i)a[i]=a[i]+(i-l)*ave+s;	
		}
	}
	if(s==e){
		b[l-1]+=s;
		b[r]-=s;
		while(m--){
		l=read();
		r=read();
		s=read();
		e=read();
		b[l-1]+=s;
		b[r]-=s;
		}
		for(int i=1;i<=n;++i){
			a[i]=a[i-1]+b[i-1];
		}
	}
	for(int i=2;i<=n;++i)a[1]^=a[i];
	cout<<a[1]<<endl;
	return 0;
}


