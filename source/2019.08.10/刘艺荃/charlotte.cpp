#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n;
void read(int &x){
	int f=1,r=0;char ch;
	do ch=getchar(); while(!isdigit(ch)&&ch!='-');
	if(ch=='-'){f=-1;ch=getchar();}
	do r=r*10+ch-48,ch=getchar(); while(isdigit(ch));
	x=f*r;
}
signed main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		bool flg=true;
		for(int i=1;i<=n;i++){
			int t,x,y;
			read(t);read(x);read(y);
			int minn=x+y;
			if(t<minn){
				flg=false;
			}
			if(abs(t-minn)%2==1){
				flg=false;
			}
		}
		if(flg)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
/*
3
2
3 1 2
6 1 1
1
2 100 100
2
5 1 1
100 1 1
*/

