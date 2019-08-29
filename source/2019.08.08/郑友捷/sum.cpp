#include<cstdio> 
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;
long long a[100010],f[100010][3],f1[100010][3],ans[100010],ans1[100010];
int n,last,flag;
long long sum[100010][2];
long long maxx;
long long cnt[100010];
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	maxx=-999999999999;
	read(n);
	for(register int i=1;i<=n;i++){
		read(a[i]);
		ans[i]=ans1[i]=-999999999999;
		sum[i][1]=sum[i][2]=-999999999999;
		if(a[i]>=0){
			flag++;
		}
	}
	sum[0][1]=sum[0][2]=sum[n+1][1]=sum[n+1][2]=-999999999999;
	ans[0]=ans[n+1]=ans1[0]=ans1[n+1]=-999999999999;
	if(n<=3000){
		for(register int i=1;i<=n;i++){
			cnt[i]=cnt[i-1]+a[i];
		}
		for(register int i=1;i<=n;i++){
			for(register int j=1;j<=i;j++){
				sum[i][1]=max(sum[i][1],cnt[i]-cnt[j-1]);
			}
		}
		for(register int i=n;i>=1;i--){
			for(register int j=n;j>=i;j--){
				sum[i][2]=max(sum[i][2],cnt[j]-cnt[i-1]);
			}
		}
		for(register int i=1;i<=n;i++){
			for(register int j=i+1;j<=n;j++){
				maxx=max(maxx,sum[i][1]+sum[j][2]);
			}
		}
		printf("%lld\n",maxx);
		return 0;
	}
	if(!flag){
		int pos;
		long long now=0;
		for(register int i=1;i<=n;i++){
			if(a[i]>maxx){
				maxx=a[i];
				pos=i;
			}
		}
		now+=maxx;
		maxx=-999999999999;
		for(register int i=1;i<=n;i++){
			if(a[i]>maxx&&i!=pos){
				maxx=a[i];
			}
		}
		now+=maxx;
		printf("%lld\n",now);
		return 0;
	}
	if(flag==1){
		int now;
		for(register int i=1;i<=n;i++){
			if(a[i]<0){
				maxx=max(maxx,a[i]);
			}
			if(a[i]>=0) now=a[i];
		}
		printf("%lld\n",now+maxx);
		return 0;
	}
	if(flag==2){
		long long now=0;
		for(register int i=1;i<=n;i++){
			if(a[i]>=0){
				now+=a[i];
			}
		}
		printf("%lld\n",now);
		return 0;
	}
	for(register int i=1;i<=n;i++){
		if(a[i]>=0){
			f[i][1]=f[i-1][1]+a[i];
			f[i][2]=f[i-1][2];
		}
		else if(a[i]<0){
			f[i][1]=f[i-1][1];
			f[i][2]=f[i-1][2]+a[i];
		}
		f[i][3]=last;
		if(a[i]>=0&&a[i+1]<0||a[i]<0&&a[i+1]>=0){
			last=i;
		}
	}
	last=n+1;
	for(register int i=n;i>=1;i--){
		if(a[i]>=0){
			f1[i][1]=f1[i+1][1]+a[i];
			f1[i][2]=f1[i+1][2]; 
		}
		else if(a[i]<0){
			f1[i][1]=f1[i+1][1];
			f1[i][2]=f1[i+1][2]+a[i];
		}
		f1[i][3]=last;
		if(a[i]>=0&&a[i-1]<0||a[i]<0&&a[i-1]>=0){
			last=i;
		}
//		printf("%lld %lld %lld\n",f1[i][1],f1[i][2],f1[i][3]);
	}
	for(register int i=1;i<=n;i++){
		if(a[i]>=0){
			long long now=f[i][1]-f[f[f[i][3]][3]][1];
			long long now1=f[i][2]-f[f[f[i][3]][3]][2];
			long long now2=abs(now)-abs(now1);
			if(now2+ans[f[f[i][3]][3]]>f[i][1]-f[f[i][3]][1]){
				ans[i]=ans[f[f[i][3]][3]]+now2;
			}
			else {	
				ans[i]=f[i][1]-f[f[i][3]][1];
			}
		}
		else if(ans[f[i][3]]>abs(f[i][2]-f[f[i][3]][2])){
				ans[i]=ans[f[i][3]]+(f[i][2]-f[f[i][3]][2]);
			}
			else {
				ans[i]=a[i];
			}
	}
	for(register int i=n;i>=1;i--){
		if(a[i]>=0){
			long long now=f1[i][1]-f1[f1[f1[i][3]][3]][1];
			long long now1=f1[i][2]-f1[f1[f1[i][3]][3]][2];
			long long now2=abs(now)-abs(now1);
//			printf("%lld %lld %lld\n",now,now1,now2);
			if(now2+ans1[f1[f1[i][3]][3]]>f1[i][1]-f1[f1[i][3]][1]){
				ans1[i]=ans1[f1[f1[i][3]][3]]+now2;
			}
			else {
				ans1[i]=f1[i][1]-f1[f1[i][3]][1];
			}	
		}
		else if(ans1[f1[i][3]]>abs(f1[i][2]-f1[f1[i][3]][2])){
				ans1[i]=ans1[f1[i][3]]+(f1[i][2]+f1[f1[i][3]][2]);
			}
			else ans1[i]=a[i];
		}
	maxx=-999999999999;
	for(register int i=1;i<=n;i++){
		sum[i][1]=max(sum[i-1][1],ans[i]);
		
	}
	for(register int i=n;i>=1;i--){
		sum[i][2]=max(sum[i+1][2],ans1[i]);
	}
	for(register int i=1;i<n;i++){
		maxx=max(maxx,sum[i][1]+sum[i+1][2]);
	}
	printf("%lld\n",maxx);
}


