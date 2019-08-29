#include<bits/stdc++.h>
using namespace std;
template<typename T> void read(T &x){
	x=0;
	T f=1;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	x*=f;
}
int n;
int len;
struct side{
	int v,last;
};
side c[600010];
int head[600010];
void put(int x,int y){
	c[++len].v=y;
	c[len].last=head[x];
	head[x]=len;
} 
int main(){
	read(n);
	for(int i=1;i<n;i++){
		int x,y;
		read(x);
		read(y);
		put(x,y);
		put(y,x);
	}
	
	return 0;
}


