#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define rint register int
#define ll long long
using namespace std;
const int maxn=1e6+7;
const int inf=1e8;

int T,n;
int t[maxn],x[maxn],y[maxn];

bool work(int t,int x,int y){
	x=abs(x); y=abs(y);
	if(t<x+y) return false;
	if(t==x+y) return true;
	if(((x&1)&&(y&1))||(!(x&1))&&(!(y&1))){
		if(t&1) return false;
		else return true;
	}
	else{
		if(t&1) return true;
		else return false;
	}
}

int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	scanf("%d",&T);
	for(rint woo=1;woo<=T;++woo){
		scanf("%d",&n);
		for(rint i=1;i<=n;++i){
			scanf("%d%d%d",&t[i],&x[i],&y[i]);
			if(!work(t[i]-t[i-1],x[i]-x[i-1],y[i]-y[i-1])){
				printf("No\n");
				break;
			}
			else if(i==n) printf("Yes\n");
		}
		
	}
	return 0;
}

/*
1
3
8 2 4
10 0 4
9 0 0
*/

/*
1
4
8 2 4
15 4 1
22 1 1
36 2 2
*/









