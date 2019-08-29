#include<bits/stdc++.h>
using namespace std;
#define int long long
#define RG register
#define M 100100
inline int read()
{
	int s=0,w=1;char c=getchar();
	while((c<'0'||c>'9')&&c!='-') c=getchar();
	if(c=='-') w=-1,c=getchar();
	while(c>='0'&&c<='9') s=s*10+c-'0',c=getchar();
	return s*w;
}
int T,n,t[M];
signed main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	T=read();
	while(T--)
	{
		memset(t,0,sizeof(t));
		n=read();int no=0;
		bool ju=0;
		for(RG int i=1;i<=n;i++)
		{
			t[i]=read();int x=read(),y=read();
			if(ju) continue;
			  int d=t[i]-t[i-1]-x-y+no;
			  if(d>=0)
			  {
				if(d&1)
				{
					ju=1;
					continue;
				}
				else
				{
					no=x+y;
				}
			  }
			  else ju=1;
		}
		if(ju)  cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
