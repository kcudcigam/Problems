#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &FF)
{
	FF=0;int RR=1;char CH=getchar();
	while(!isdigit(CH)&&CH!='-') CH=getchar();
	if(CH=='-') RR=-1;else FF=(CH^48);CH=getchar();
	while(isdigit(CH)) FF=(FF<<1)+(FF<<3)+(CH^48),CH=getchar();FF*=RR;
}
int flag[110],now=1;
int main()
{
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	long long y;
	read(y);
	int len=0;
	long long ki=1;
	int li=0;
	while(ki<=y) len++,ki*=2;
	int L=(ki==(y<<1))?len+1:len+2;
	printf("%d ",L);
	long long ti=y-1;
	while(ti){li+=ti%2,flag[++now]=ti%2;ti/=2;}
	printf("%d\n",(L-1)*(L-2)/2+li+1);
	//system("pause");
	for(int i=1;i<=L-2;i++)
		for(int j=i+1;j<=L-1;j++)
			printf("%d %d\n",i,j);
	flag[1]=1;
	for(int i=1;i<=L-1;i++)
		if(flag[i])
			printf("%d %d\n",i,L);
	return 0;
} 
