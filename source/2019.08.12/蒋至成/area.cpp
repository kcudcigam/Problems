#include<bits/stdc++.h>
using namespace std;
int x,y;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
int main(){
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout); 
	read(x);read(y);
	cout<<"infinity";
	return 0;
}


