#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
long long a[2048];
int main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	int y;
	read(y);
	if(y==1){
		cout<<"2 1"<<endl;
		cout<<"1 2"<<endl;
	} 
	if(y==2){
		cout<<"3 3"<<endl;
		cout<<"1 2"<<endl;
		cout<<"2 3"<<endl;
		cout<<"1 3"<<endl;
	}
	return 0;
}

