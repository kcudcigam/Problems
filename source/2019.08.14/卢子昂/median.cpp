#include<bits/stdc++.h>
using namespace std;
const int Maxn=500000;
int read(){
	int x=0;char c=getchar();
	for(;c<'0'||c>'9';c=getchar());
	for(;c>='0'&&c<='9';c=getchar())x=x*10-'0'+c;
	return x;
}
int a[Maxn],b[Maxn];
multiset<int>c;
int n,m;
int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	int i,j,op,x,y,z,l1,l2,r1,r2,mid;
	n=read();m=read();
	for(i=1;i<=n;i++)a[i]=read();
	for(i=1;i<=n;i++)b[i]=read();
	for(i=1;i<=m;i++){
		op=read();
		if(op==1){
			x=read();y=read();z=read();
			if(x==0)a[y]=z;
			else b[y]=z;
		}
		else{
			l1=read();r1=read();l2=read();r2=read();
			mid=((r1-l1+r2-l2+2)>>1);
			for(j=l1;j<=r1;j++)c.insert(a[j]);
			for(j=l2;j<=r2;j++)c.insert(b[j]);
			j=0;
			for(multiset<int>::iterator it = c.begin();j<=mid;j++,it++)if(j==mid)printf("%d\n",*it);
			c.clear();
		}
	}	
	return 0;
}

