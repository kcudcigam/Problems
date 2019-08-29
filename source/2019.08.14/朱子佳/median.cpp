#include<bits/stdc++.h>
using namespace std;
int read() {
char c = getchar(); int x = 0; for(;c < '0' || c > '9'; c = getchar());
for(;c >= '0' && c <= '9'; c = getchar()) x = x * 10 - '0' + c; return x;
}
priority_queue<int> q;
int a[500001],b[500001];
int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	int n,m,b1,x,y,z,l1,r1,l2,r2,k;
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	for(int i=1;i<=n;i++){
		b[i]=read();
	}
	for(int i=1;i<=m;i++){
		b1=read();
		if(b1==1){
			x=read();
			y=read();
			z=read();
			if(x==0){
				a[y]=z;
			}else{
				b[y]=z;
			}
		}else{
			l1=read();
			r1=read();
			l2=read();
			r2=read();
			k=r1-l1+1+r2-l2+1;
			if(a[r1]<=b[l2]){
				if(k/2<=r1-l1){
					cout<<a[l1+k/2]<<endl;
				}else{
					cout<<b[l2+k/2+l1-r1-1]<<endl;
				}
				continue;
			}
			if(b[r2]<=a[l1]){
				if(k/2<=r2-l2){
					cout<<b[l2+k/2]<<endl;
				}else{
					cout<<a[l1+k/2+l2-r2-1]<<endl;
				}
				continue;
			}
			for(int j=l1;j<=r1;j++){
				q.push(a[j]);
			}
			for(int j=l2;j<=r2;j++){
				q.push(b[j]);
			}
			for(int j=1;j<=k/2;j++){
				q.pop();
			}
			cout<<q.top()<<endl;
			while(!q.empty()){
				q.pop();
			}
		}
	}
	return 0;
}

