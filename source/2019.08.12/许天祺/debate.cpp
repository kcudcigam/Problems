#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int num=0,f=1; char c=getchar();
	while(!isdigit(c)){if (c=='-') f=-1; c=getchar();}
	while(isdigit(c)){num=num*10+c-'0'; c=getchar();}
	return num*f;
}
int n,num[2][2][400005],tot[2][2],ans;
signed main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
	{
		char c1 = getchar();
		while (!isdigit(c1)) c1 = getchar();
		char c2 = getchar();
		while (!isdigit(c2)) c2 = getchar();
		int x1=c1-'0',x2=c2-'0';
		num[x1][x2][++tot[x1][x2]]=read();
	}
	for(int i=1;i<=tot[1][1];i++)
		ans+=num[1][1][i];
	sort(num[1][0]+1,num[1][0]+tot[1][0]+1);
	reverse(num[1][0]+1,num[1][0]+tot[1][0]+1);
	
	sort(num[0][1]+1,num[0][1]+tot[0][1]+1);
	reverse(num[0][1]+1,num[0][1]+tot[0][1]+1);
	for(int i=1;i<=min(tot[1][0],tot[0][1]);i++)
		ans+=num[1][0][i]+num[0][1][i];
		
	for(int i=min(tot[1][0],tot[0][1]);i<=max(tot[1][0],tot[0][1]);i++)
		num[0][0][++tot[0][0]]=max(num[0][1][i],num[1][0][i]);
		
	sort(num[0][0]+1,num[0][0]+tot[0][0]+1);
	reverse(num[0][0]+1,num[0][0]+tot[0][0]+1);
	
	for(int i=1;i<=tot[1][1];i++)
		ans+=num[0][0][i];
	cout<<ans<<endl;
	
	return 0;
}
