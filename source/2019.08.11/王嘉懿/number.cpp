#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x)
{
	int f=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-f;
	for(; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
int t,vis[10];
string a;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char q,w;
	read(t);
	int cnt;
	while(t--)
	{
		cnt=0;
		int fl=0;
		memset(vis,0,sizeof(vis));
		cin>>a;
		for(register int i=0;i<a.size();i++)
		{
			if(vis[a[i]-'0']==0)
			{
				vis[a[i]-'0']=1;
				cnt++;
		    }
		    if(cnt>2)
		    {
		    	fl=1;
		    	cout<<'0'<<endl;
				break;
			}
		}
		if(fl==0)
		cout<<'1'<<endl;
	}
	return 0;
}
