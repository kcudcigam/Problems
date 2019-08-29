#include<bits/stdc++.h>
using namespace std;
long long a[100009];
bool flag;
const int INF=0x3f3f3f3f;
long long www(int l,int r){
	long long maxn=a[r];long long  d;d=a[r];
	for(int i=r-1;i>=l;i--){
		
		if(a[i]<0){
			if(d>0)d+=a[i];
			else d=a[i];
		}
		if(a[i]>0){
			if(d>0)d+=a[i];
			else d=a[i];
		}maxn=max(maxn,d);
	}return maxn;
}
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
long long num;int c;int k;k=0;
    int n,g;cin>>n;int x,y;y=x=-1*INF;flag=0;
    for(int i=1;i<=n;i++){
    	cin>>g;if(g>y){
    		if(g>=x){c=x;x=g;y=c;}
    		else y=g;
		};if(g>0)flag=1;
    	if(i>=2&&g<0&&a[i-1]<0){
		a[i-1]+=g;continue;k++;}
		a[i]=g;
	}
	n-=k;
	if(flag==0){cout<<x+y;cout<<"!";return 0;
	}
	x=INF;num=-1;if(a[1]<0)g=2;else g=1;
	for(int i=1;i<=n;i++){
		if(a[i]<=x&&i>g&&i!=n){
			x=a[i];num=i;
			
		}
	}
	if(x>=0){num=0;
		for(int i=1;i<=n;i++){
		if(a[i]>0)num+=a[i];}
		num-=x;
	
		cout<<num;return 0;
	}
//	cout<<num;cout<<endl<<a[num];
    cout<<www(1,num-1)+www(num+1,n);
	return 0;
}


