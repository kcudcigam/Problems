#include<bits/stdc++.h>
using namespace std;
int t[100001],x[100001],y[100001];
int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	int T,b,xn,yn,tn,jl,sj,n;
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n;
		b=0;
		xn=0;
		yn=0;
		tn=0;
		for(int i=1;i<=n;i++){
			cin>>t[i]>>x[i]>>y[i];
			jl=abs(xn-x[i])+abs(yn-y[i]);
			sj=t[i]-tn;
			if(sj<jl){
				b=1;
				cout<<"No"<<endl;
				break;
			}else{
				if(sj==jl){
					xn=x[i];
					yn=y[i];
					tn=t[i];
				}else{
					if((sj-jl)%2==0){
						xn=x[i];
						yn=y[i];
						tn=t[i];
					}else{
						b=1;
						cout<<"No"<<endl;
						break;
					}
				}
			}
		}
		if(b!=1){
			cout<<"Yes"<<endl;
		}
	}
	return 0;
}

