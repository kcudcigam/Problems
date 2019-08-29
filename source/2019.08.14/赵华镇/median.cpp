#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[500005],b[500005],tot;
int l1,r1,l2,r2,p[500005],t,t1;
int main()
{
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	int n,m,i,j,k,x,y,z;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	for(i=1;i<=m;i++){
		tot=0;
		scanf("%d",&k);
		if(k==1){
			scanf("%d%d%d",&x,&y,&z);
			if(x==0) a[y]=z;
			else b[y]=z;
		}
		else{
			scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
			for(j=l1;j<=r1;j++) tot++,p[tot]=a[j];
			for(j=l2;j<=r2;j++) tot++,p[tot]=b[j];
			sort(p+1,p+tot+1);
			printf("%d\n",p[tot/2+1]);
			for(j=1;j<=t;j++) p[j]=0;
		}
	}
	return 0;
}
