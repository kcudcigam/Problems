#include<bits/stdc++.h>
using namespace std;
inline long long  read(){
	long long x=0,f=1;
	char c=getchar();
	while(c>'9' || c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
	return x*f;
}
long long  n,a[100005],sum[100005],maxx=-0x3f;
long long Minn(int x,int y){
	long long minn=0x3f;
	for(int i=x;i<=y;i++){
		minn=min(sum[i],minn);	
	}
	return minn;
}
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){a[i]=read();sum[i]=sum[i-1]+a[i];}
	for(int wz=2;wz<n-1;wz++){
		long long max1=-0x3f,max2=-0x3f;
		for(int i=1;i<=wz;i++){
			max1=max(max1,sum[i]-Minn(1,i-1));
		}
		for(int i=wz+1;i<=n;i++){
			max2=max(max2,sum[i]-Minn(wz+1,i-1));
		}
		maxx=max(maxx,max1+max2);
	}
	cout<<maxx<<endl;
	return 0;
}


