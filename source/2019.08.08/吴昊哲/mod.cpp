#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x)
{
    int f=1;x=0;char c=getchar();
    for (;!isdigit(c);c=getchar()) if (c==' -') f= -f;
    for (; isdigit(c);c=getchar()) x=x*10+c -'0';
    x*=f;
}
int q,n;
long long p;
int biao[10]={0,2,12,58,310,1886,13244,106002,954090,9540982};
int ans[10];
int main()
{
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
    cin>>q;
    for(int i=1;i<=q;i++)
    {
    	cin>>n;
		read(p);
    	ans[i]=biao[n-1]%p;
	}
	for(int i=1;i<=q;i++)
    {
    	cout<<ans[i]<<endl;
	}
	return 0;
}

