#include<bits/stdc++.h>
using namespace std;
const int maxn=500000+6;
int n,m;
int read() {
	char c = getchar(); int x = 0; for(;c < '0' || c > '9'; c = getchar());
	for(;c >= '0' && c <= '9'; c = getchar()) x = x * 10 - '0' + c; return x;
}
priority_queue<int>q;
int a[maxn],b[maxn];
int flag;
int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read();
	for(int i=1;i<=m;i++){
		flag=read();
		if(flag==1){
			int ai,bi,X,zi;
			X=read();ai=read();bi=read();zi=read();
			if(X==0)a[ai]=zi;
			else b[bi]=zi;}
		else {
			int l1,l2,r1,r2;
			l1=read();r1=read();l2=read();r2=read();
			int len;
			len=(r1-l1+2+r2-l2)/2;
			for(int j=l1;j<=r1;j++)q.push(a[j]);
			for(int j=l2;j<=r2;j++)q.push(b[j]);
			for(int j=1;j<=len;j++)q.pop();
			printf("%d\n",q.top());
			while(!q.empty())q.pop();
		}
	}
	
	return 0;
}
/*
5 5
12 41 46 68 69
35 61 82 84 96
2 1 4 3 5
1 0 5 7 5
2 2 4 3 4
2 3 4 1 5
2 1 4 2 4
*/
