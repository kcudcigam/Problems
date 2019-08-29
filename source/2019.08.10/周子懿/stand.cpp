#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=10000010;
const int P=251;
ll n,m,a,b,c,d,e,ans[N],l[P],r[P],lt[N],rt[N],sum;
//priority_queue<greater<int>,vector<int> >q;
template <typename T> inline void read(T &x)
{
	T f=1;x=0;
	char c=getchar();
	for(;!isdigit(c);c=getchar())if(f!='-')f=-f;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	x*=f;
}
void init()
{
	read(n);read(m);read(a);read(b);read(c);read(d);read(e);
	for(int i=1;i<=n;i++)
	{
		read(l[i]);read(r[i]);
		lt[l[i]]++;rt[r[i]]++;
	}
}
bool pd()
{
	for(int i=1;i<=n;i++)
	{
		if(l[i]!=1||r[i]!=m)
		return false;
	}
	return true;
}
void work()
{
	if(pd())
	{
		cout<<a*n+b*n*n+c*n*n*n+d*n*n*n*n+e*n*n*n*n*n<<endl;
	}
	ll tot=n;
	while(true)
	{
		memset(ans,0,sizeof(ans));
		ll maxn=0,maxi;
		for(int i=1;i<=m;i++)
		{
			if(lt[i]>0)ans[i]=ans[i-1]+lt[i];
			else if(rt[i]>0)ans[i]=ans[i-1]-rt[i];
			else ans[i]=ans[i-1];
			if(maxn<ans[i])
			{
				maxn=ans[i];
				maxi=i;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(maxi>=l[i]&&maxi<=r[i])
			{
				lt[l[i]]--;
				rt[r[i]]--;
				tot--;	
			}
		}
		sum+=a*maxn+b*maxn*maxn+c*maxn*maxn*maxn+d*maxn*maxn*maxn*maxn+e*maxn*maxn*maxn*maxn*maxn;
		if(tot<=0)break;
	}
	cout<<sum<<endl;
}
int main()
{
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	init();
	work();
	return 0;
}


