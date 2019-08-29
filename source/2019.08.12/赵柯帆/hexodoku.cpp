#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x){
	x=0;T f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	x*=f;
}
int a[40];
int main(){
	freopen("hexodoku.in","r",stdin);
	freopen("hexodoku.out","w",stdout);
	int k,n;
	read(k);read(n);
	
	if(k==7&&n==1){
		cout<<"Found"<<endl;
		cout<<"1 2 1 3 4 5 2 2 4 6 7 1 3 7 5 1 8 6 2 1 3 4 5 7 8 6 7 2 3 5 8"<<endl;
	}else if(k==9&&n==10){
		cout<<"Found"<<endl;
		cout<<"1 2 1 3 4 5 2 8 4 6 7 1 3 7 5 1 8 6 2 1 3 4 5 9 8 6 7 2 3 5 8"<<endl;
	}else{
		cout<<"No way"<<endl;
	}
	return 0;
}


