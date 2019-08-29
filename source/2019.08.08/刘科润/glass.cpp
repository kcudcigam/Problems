#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{   int f=1;
  char c=getchar();
  x=0;
  while (!isdigit(c))
  {  if (c=='-') f=-1;
	c=getchar();}
while (isdigit(c))
{ x=(x<<3)+(x<<1)+(c^48);
  c=getchar();}
x*=f;
}
long long n,k;
bitset <100> s;
int main(){
	freopen("glass.in","r",stdin);
	freopen("glass.out","w",stdout);
	read(n);read(k);
	long long i=n,ans=0;
	while(1)
	{
		s=i;
		if(k==1)
		{
			long long p=1;
			while(p<n)
			{
				p*=2;
			}
			cout<<p-n<<endl;
			break;
		}
		if(s.count()<=k)
		{
			cout<<ans<<endl;
			break;
		}
		ans++;
		i++;
	}
	return 0;
}

