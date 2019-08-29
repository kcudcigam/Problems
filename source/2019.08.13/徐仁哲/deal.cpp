#include<bits/stdc++.h>
using namespace std;
struct side{
	int v,s1,s2;
};
side a[1001];
int n,x;
template<typename T> void read(T &x){
	x=0;
	T f=1;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	x*=f;
}
int main(){
	read(n);
	read(x);
	for(int i=1;i<=n;i++){
		read(a[i].v);
		read(a[i].s1);
		read(a[i].s2);
	}
	
	return 0;
}
