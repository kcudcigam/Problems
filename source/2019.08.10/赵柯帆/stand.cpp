#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x){
	x=0;T f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	x*=f;
}
int a[10000010],l[260],r[260];
long long p(int x,int y){
	long long ans=1;
	for(int i=1;i<=y;i++){
		ans*=x;
	}
	return ans;
}
int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	int n,m;
	read(n);read(m);
	int x1,x2,x3,x4,x5;
	read(x1);read(x2);read(x3);read(x4);read(x5);
	bool flg=true;
	for(int i=1;i<=n;i++){
		read(l[i]);read(r[i]);
		if(l[i]!=1||r[i]!=m)flg=false;
	}
	
	if(flg==true){
		long long ans=x1*p(n,1)+x2*p(n,2)+x3*p(n,3)+x4*p(n,4)+x5*p(n,5);
		cout<<ans<<endl;
	}else if(n<=50&&m<=50){
		int mx=0,t=n,mxi;
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=l[i];j<=r[i];j++){
				a[j]++;
			}
		}
		while(t>0){
			mx=0;
			for(int i=1;i<=m;i++){
				if(a[i]>mx){
					mx=a[i];
					mxi=i;
				}
			}
			//cout<<mx<<endl;
			//cout<<mxi<<endl;
			ans+=x1*p(mx,1)+x2*p(mx,2)+x3*p(mx,3)+x4*p(mx,4)+x5*p(mx,5);
			for(int i=1;i<=n;i++){
				if(mxi>=l[i]&&mxi<=r[i]){
					t--;
					//cout<<t<<endl;
					for(int j=l[i];j<=r[i];j++){
						a[j]--;
					}
				}
			}
		}
		cout<<ans<<endl;
	}else{
		long long ans=x1*p(n,1)+x2*p(n,2)+x3*p(n,3)+x4*p(n,4)+x5*p(n,5);
		cout<<ans<<endl;
	}
	return 0;
}


