#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=400005;
int n,a[4][maxn],b[maxn],cnt,blood;
int main()
{
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		char s[3]; scanf("%s",s);
		if(s[0]=='1')
		{
			if(s[1]=='1') scanf("%d",&a[1][++a[1][0]]);
			else scanf("%d",&a[2][++a[2][0]]);
		}
		else
		{
			if(s[1]=='1') scanf("%d",&a[3][++a[3][0]]);
			else scanf("%d",&a[4][++a[4][0]]);
		}
	}
	for(int i=1;i<=4;i++)
		if(a[i][0]) sort(&a[i][1],&a[i][a[i][0]+1],greater<int>());
	int res=0; blood=a[1][0];
	for(int i=1;i<=a[1][0];i++) res+=a[1][i];
	int p=min(a[2][0],a[3][0]);
	for(int i=1;i<=p;i++) res+=a[2][i]+a[3][i];
	p++;
	for(int i=p;i<=a[2][0];i++) b[++cnt]=a[2][i];
	for(int i=p;i<=a[3][0];i++) b[++cnt]=a[3][i];
	for(int i=1;i<=a[4][0];i++) b[++cnt]=a[4][i];
	sort(b+1,b+1+cnt,greater<int>());
	for(int i=1;i<=cnt&&i<=blood;i++) res+=b[i];
	printf("%d\n",res);
	return 0;
}
