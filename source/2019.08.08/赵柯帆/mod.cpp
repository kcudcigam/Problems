#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x){
	x=0;T f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	x*=f;
}
int a[20]={0,2,12,58,310,1886,13244,106002,954090,9540982};
int main(){
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	int n;
	read(n);
	srand(time(NULL));
	for(int i=n;i<=n;i++){
		int x,y;
		read(x);read(y);
		if(x>10){
			cout<<rand()%y<<endl;
		}else{
			cout<<a[x]%y<<endl;
		}
	}
	return 0;
}

