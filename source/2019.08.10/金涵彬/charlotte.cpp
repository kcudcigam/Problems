#include<bits/stdc++.h>
using namespace std;
int T;
int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		int n;
		cin>>n;
		int x=0,y=0,t=0;
		bool ok=true;
		for(int i=1;i<=n;i++){
			int ti,xi,yi;
			cin>>ti>>xi>>yi;
			t+=abs(xi-x)+abs(yi-y);
			if(t<=ti&&(ti-t)%2==0){
				x=xi;
				y=yi;
				t=ti;
			}else{
				ok=false;
				cout<<"No"<<endl;
				break;
			}
		}
		if(ok)cout<<"Yes\n";
	}
	return 0;
}
