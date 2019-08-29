#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,len; char s[20];
int chk1()
{
	int tot=0,cnt[15]={0};
	for(int i=0;i<len;i++) cnt[s[i]-'0']++;
	for(int i=0;i<=9;i++) tot+=(cnt[i]>0);
	return tot<=2;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%s",s); len=strlen(s);
		if(chk1()) puts("1");
		else puts("2");
	}
	return 0;
}
