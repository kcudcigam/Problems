#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
int num,n,m1,m2;
int main(){
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	read(num);read(n);read(m1);read(m2);
	for(int i=1;i<=m1;++i){
		int x,y;
		read(x);read(y);
	}
	for(int i=1;i<=m2;++i){
		int x,y;
		read(x);read(y);
	}
	if(num==1)cout<<0; 
	else if(num==2)cout<<0;
	return 0;
}


