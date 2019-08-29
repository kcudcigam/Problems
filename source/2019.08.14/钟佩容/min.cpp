#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,k,minn,n,x;
int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	
	scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
	if (a>=0&&b>=0&&c>=0&&d>=0){
		long long f=0;
		for (int i=1;i<=n;i++){
			scanf("%d",&x);
			f=f+a*x*x*x+b*x*x+c*x+d;
		}
		cout<<f<<endl;
	}
	else if (a==0&&b==0&&d<=0){
		minn=100000000;
		for (int i=1;i<=n;i++){
			scanf("%d",&x);
			if (x<minn) minn=x;
		}
		long long f=c*minn+d;
		cout<<f<<endl;
	}
	else if (a==0&&b==0&&d>0){
		int  t=d/abs(c);
		long long f=0;
		for (int i=1;i<=t;i++){
			
		}
		   f=f+c*k+d;
		for (int i=t+1;i<=n;i++){
			scanf("%d",&x);
			if (x<minn) minn=x;
		}
		f=f+c*minn+d;
		cout<<f<<endl;  
	}

	return 0;
}

