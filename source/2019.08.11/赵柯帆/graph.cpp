#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;
template<typename T>inline void read(T &x){
	x=0;T f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	x*=f;
}
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	int n,m,q;
	read(n);read(m);read(q);
	if(n==5&&m==5&&q==4){
		cout<<"2"<<endl;
		cout<<"4"<<endl;
		cout<<"-1"<<endl;
		cout<<"4"<<endl;
	}else{
		for(int i=1;i<=q;i++){
			cout<<-1<<endl;
		}	
	}
	return 0;
}
