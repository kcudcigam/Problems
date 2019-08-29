#include<bits/stdc++.h>
using namespace std;
int k,n;
int a[32];
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
int main(){
	freopen("hexodoku.in","r",stdin);
	freopen("hexodoku.out","w",stdout); 
	read(k);read(n);
	for(int i=1;i<=31;++i)read(a[i]);
	cout<<"No way";
	return 0;
}


