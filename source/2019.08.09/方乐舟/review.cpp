#include<bits/stdc++.h>
using namespace std;
long long y,n,m,s=1,ss=0,c,cn;
long long a[64];
long long b[10000];
int main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	cin>>y;
	if (y==1){
		cout<<"2"<<endl;
		return 0;
	} 
	while(s<y){
		s*=2;
		ss++;
	}
	n=ss+2;
	c=s-y;
	if (c==0){
		cout<<n<<" "<<(n*(n-1)/2)<<endl;
	int xx=1;int yy=2;
	for (int i=1;i<=n*(n-1)/2;i++){
		cout<<xx<<" "<<yy<<endl;
		yy++;
		if (yy==n+1){
			xx++;
			yy=xx+1;
		}
	}
	}
	a[0]=1;
	int step;
	for (int i=1;i<=64;i++){
		a[i]=a[i-1]*2;
		if (c<a[i]){
			step=i-1;
			break;
		}
	}
	while(c!=0){
		c-=a[step];
		step--;
		cn++;b[cn]=step+3;
		if (c==0){
		cout<<n<<" "<<(n*(n-1)/2)-cn<<endl;
	int tt=cn;
	int xx=1;int yy=2;
	for (int i=1;i<=n*(n-1)/2;i++){
		if ((yy!=n)) cout<<xx<<" "<<yy<<endl;
		if ((yy==n)&&b[tt]!=xx) cout<<xx<<" "<<yy<<endl;
		if ((yy==n)&&b[tt]==xx) tt--;
		yy++;
		if (yy==n+1){
			xx++;
			yy=xx+1;
		}
	}
	}
	}
	return 0;
}


