#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x){
	x=0;T f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	x*=f;
}
int main(){
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	int x,y;
	read(x);read(y);
	if(x>y){
		swap(x,y);
	}
	if(x==0){
		cout<<"infinity"<<endl;
	}else{
		cout<<x+y<<endl;
	}
	return 0;
}


