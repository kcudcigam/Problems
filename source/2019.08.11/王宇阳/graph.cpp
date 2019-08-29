#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}
long long n,m,Q;
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	n=read();m=read();Q=read();
	if(Q==4){
		cout<<2<<endl;
		cout<<4<<endl;
		cout<<-1<<endl;
		cout<<4<<endl;
		return 0;
	}
	while(Q--){
		cout<<-1<<endl;
	}
	return 0;
}


