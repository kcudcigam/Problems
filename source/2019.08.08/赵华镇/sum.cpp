#include<bits/stdc++.h>
using namespace std;
int maxx=-100000000,sum;
int a[100005],s[100005],b[100005];
int s1[100005],b1[100005];
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	int n,i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	s[1]=a[1];
	for(i=1;i<=n;i++){
		s[i]=max(s[i-1]+a[i],a[i]);
	}
	b[1]=s[1];
	for(i=2;i<=n;i++){
		b[i]=max(b[i-1],s[i]);
	}
	for(i=1;i<=n;i++){
		s1[i+1]=a[i+1];
		for(j=i+1;j<=n;j++){
			s1[j]=max(s1[j-1]+a[j],a[j]);
		}
		b1[i+1]=s1[i+1];
		for(j=i+2;j<=n;j++){
			b1[j]=max(b1[j-1],s1[j]);
		}
		maxx=max(maxx,b[i]+b1[n]);
		for(j=1;j<=n;j++){
			s1[j]=0;b1[j]=0;
		}
	}
	printf("%d",maxx);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
