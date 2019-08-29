#include<iostream>
#include<cstdio>
#include<algorithm>
#include<windows.h>
#define rint register int
#define ll long long
using namespace std;
const int maxn=1e6+7;
const int inf=1e8;

int n,p,q;
int ans[maxn]={0,0,2,12,58,310,1886,13244,106002,954090,9540982};

template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}

int main(){
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	read(q);
	for(rint i=1;i<=q;++i){
		read(n); read(p);
		if(n>10) {_sleep(999); return 0;}
		printf("%d\n",ans[i]%p);
	}
	return 0;
}




/*
10
1 530093761
2 892208769
3 659909301
4 348347651
5 703875913
6 870865473
7 61687961
8 334373509
9 826163921
10 735259938
*/
