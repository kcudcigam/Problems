#include<bits/stdc++.h>
using namespace std;
int s0[400001],s1[400001],s2[400001],s3[400001],v[400001];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	int n,x;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&v[i]);
		if(x==11)s3[++s3[0]]=v[i];
		else if(x==10)s2[++s2[0]]=v[i];
		else if(x==01)s1[++s1[0]]=v[i];
		else s0[++s0[0]]=v[i];
	}
	int ans=0;
	sort(s0+1,s0+s0[0]+1,cmp);
	sort(s1+1,s1+s1[0]+1,cmp);
	sort(s2+1,s2+s2[0]+1,cmp);
	sort(s3+1,s3+s3[0]+1,cmp);
	for(int i=1;i<=s3[0];i++)ans+=s3[i];
	int s=min(s1[0],s2[0]);
	for(int i=1;i<=s;i++)ans+=s1[i]+s2[i];
	for(int i=s+1;i<=s1[0];i++)s0[++s0[0]]=s1[i];
	for(int i=s+1;i<=s2[0];i++)s0[++s0[0]]=s2[i];
	sort(s0+1,s0+s0[0]+1,cmp);
	s=min(s0[0],s3[0]);
	for(int i=1;i<=s;i++)ans+=s0[i];
	printf("%d",ans);
	return 0;
} 
