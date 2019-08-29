#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int ri(){
	char c=getchar();int x=0;for(;c<'0'||c>'9';c=getchar());
	for(;c>='0'&&c<='9';c=getchar())x=x*10-'0'+c;return x;
}
int n,m,a[N],b[N],bj[N],x[N],y[N],z[N],w[N],t[N],size,ans[N];
int main()
{
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	n=ri();m=ri();
	for(int i=1;i<=n;i++)a[i]=ri();
	for(int i=1;i<=n;i++)b[i]=ri();
	for(int i=1;i<=m;i++)
	{
		cin>>bj[i];
		if(bj[i]==1)
		{
			cin>>x[i];
			if(x[i]==0)
			{
				cin>>y[i]>>z[i];
			}else if(x[i]==1)
			{
				cin>>y[i]>>z[i];
			}
		}else if(bj[i]==2)
		{
			cin>>x[i]>>y[i]>>z[i]>>w[i];
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(bj[i]==1)
		{
			if(x[i]==0)
			{
				a[y[i]]=z[i];
			}else if(x[i]==1)
			{
				b[y[i]]=z[i];
			}
		}else if(bj[i]==2)
		{
			int j=x[i],k=z[i],tot=0;
			while(j<=y[i]&&k<=w[i])
			{
				if(a[j]<=b[k])
				{
					t[++tot]=a[j];
					j++;
				}else
				{
					t[++tot]=b[k];
					k++;
				}
			}
			while(j<=y[i])
			{
				t[++tot]=a[j];
				j++;
			}
			while(k<=w[i])
			{
				t[++tot]=b[k];
				k++;
			}
			ans[++size]=t[(tot+1)/2];
			memset(t,0,sizeof(t));
		}
	}
	for(int i=1;i<=size;i++)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}

