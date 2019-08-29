#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
int main(){
	int num,n,m;
	read(num);
	read(n);
	read(m);
	for(int i=1;i<=n;i++)
	cout<<"-1 ";
	return 0;
}

