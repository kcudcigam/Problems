#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
int main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	long long n,m,y;
	read(y);
	if(y<=100000){
		cout<<y+1<<" "<<2*y-1<<endl;
		for(int i=1;i<y;i++)
		cout<<i<<" "<<i+1<<endl;
		for(int i=1;i<=y;i++)
		cout<<i<<" "<<y+1<<endl;
		return 0;
	}if(y>100000&&y<=1000000000){
		int cf=0;
		while(y!=0){
			cf++;
			y/=2;
		}
		cout<<cf+1<<" "<<cf*(cf+1)/2<<endl;
		for(int i=1;i<=cf;i++)
		for(int j=i+1;j<=cf+1;j++)
		cout<<i<<" "<<j<<endl;
		
	}
	return 0;
}

