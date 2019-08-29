#include<bits/stdc++.h>
using namespace std;

long long n;
bool ver[110];

int main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	scanf("%lld",&n);
	long long x=n;
	int k=0;
	while (x){
		ver[++k]=x&1;
		x>>=1;
	}
	bool f=false;
	int num=k+1;
	for (int i=1;i<k;++i)
		if (ver[i])	f=true;
	if (f)	{num=k+2;k++;}
	int tot;
	if (f)	tot=k*(k-1)>>1;
		else tot=k*(k+1)>>1;
	for (int i=1;i<k;++i)
		if (ver[i])	tot++;
	printf("%d %d\n",num,tot);
	if (!f){
		for (int i=1;i<=k;++i)
			for (int j=i+1;j<=k+1;++j)
				printf("%d %d\n",i,j);
		return 0;
	}
	for (int i=1;i<k;++i)
			for (int j=i+1;j<=k;++j)
				printf("%d %d\n",i,j);
	for (int i=1;i<k;++i)
		if (ver[i])	printf("%d %d\n",i+1,num);
	return 0;
}

