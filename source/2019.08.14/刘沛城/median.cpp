#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
typedef long long ak;
#define im INT_MAX
#define F(i,j,k) for(int i=j;i<=k;i++)
#define G(i,j,k) for(int i=j;i>=k;i--)
int n,m,op,w,x,y,z,av,a[555555],b[555555];
int read() {
	char c = getchar(); int x = 0; for(;c < '0' || c > '9'; c = getchar());
	for(;c >= '0' && c <= '9'; c = getchar()) x = x * 10 - '0' + c; return x;
}
bool csk(int lpc,int v){if(lpc+y-1>z)return 0;return b[lpc+y-1]>v;}
bool cxk(int cur)
	{if((cur>x)||(av-(cur-w+1)<=0))return 0;return csk(av-(cur-w+1),a[cur]);}
int bz1(int k,int p){return p?(cxk(k+p)?bz1(k+p,p<<1):bz1(k,p>>1)):k;}
int main(){
//	#ifndef lpcak
	freopen("example_median3.in","r",stdin);
	freopen("median3.txt","w",stdout);
//	#endif
	
	ios::sync_with_stdio(0);
	n=read();m=read();F(i,1,n)a[i]=read();F(i,1,n)b[i]=read();
	F(i,1,m){
		op=read();
		if(op==2){
			w=read();x=read();y=read();z=read();av=(x-w+z-y)/2+2;
			if(a[x]<=b[y]){
				if(x-w+1>=av)cout<<a[w+av-1]<<"\n";
				else cout<<b[av-(x-w+1)+y-1]<<"\n";continue;
			}
			if(a[w]>=b[z]){
				if(z-y+1>=av)cout<<b[y+av-1]<<"\n";
				else cout<<a[av-(z-y+1)+w-1]<<"\n";continue;
			}
			int zdx=bz1(w,1);
			if((w<zdx)&&(zdx<x))
				{cout<<min(a[zdx+1],b[av-(zdx-w+1)+y-1])<<"\n";continue;}
			if(zdx==x){cout<<b[av-(zdx-w+1)+y-1]<<"\n";continue;}
			if(zdx==w){
				if(b[av-(zdx-w+1)+y-1]>=a[zdx]){
					if(x==w){cout<<b[av-(zdx-w+1)+y-1]<<"\n";continue;}
					cout<<min(a[zdx+1],b[av-(zdx-w+1)+y-1])<<"\n";continue;
				}
				if(av-(zdx-w+1)+y>z){cout<<a[zdx]<<"\n";continue;}
				cout<<min(a[zdx],b[av-(zdx-w+1)+y])<<"\n";
			}
		}
		if(op==1){w=read();x=read();y=read();if(!w)a[x]=y;else b[x]=y;}
	}
	return 0;
}
/*
5 5
12 41 46 68 69
35 61 82 84 96
2 1 4 3 5
1 0 5 75
2 2 4 3 4
2 3 4 1 5
2 1 4 2 4
*/
