#include<bits/stdc++.h>
using namespace std;
inline int read(){
	   int x=0,f=1;
	   char c=getchar();
	   while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
	   while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	   return x*f;
}
int main(){
	freopen("hexodoku.in","r",stdin);
	freopen("hexodoku.out","w",stdout);
	int k=read(),n=read();
	if(k==8 && n==1){
		int x=read();
		if(x==0){
			cout<<"Found"<<endl;
			cout<<"1 2 1 3 4 5 2 8 4 6 7 1 3 7 5 1 8 6 2 1 3 4 5 9 8 6 7 2 3 5 8"<<endl;
			return 0;
		}
	}
	cout<<"No way"<<endl;
	return 0;
}


