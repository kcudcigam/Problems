#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x){
	x=0;T f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	x*=f;
}
int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	int n;
	read(n);
	for(int i=1;i<=n;i++){
		cout<<i<<endl;
	}
	return 0;
}


