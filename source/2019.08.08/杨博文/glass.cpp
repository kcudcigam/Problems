#include<bits/stdc++.h>
using namespace std;
#define max(a,b) ((a)>(b))?(a):(b)
#define min(a,b) ((a)<(b))?(a):(b)
#define lowbit(x) (x&-x)
long long tot=0,n1,n,k;
int ch(long long n)
{
    int ans=0;
    while(n)
    {
        ans++;
        n-=lowbit(n);
    }
    return ans>k;
}
int main()
{
	freopen("glass.in","r",stdin);
	freopen("glass.out","w",stdout);
    cin>>n>>k;
    n1=1;
    while(ch(n))
    {
        while(!(n&1))n>>=1,n1<<=1;
        tot+=n1;
        ++n;
    }
    cout<<tot<<endl;
    return 0;
}
