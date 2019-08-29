#include<bits/stdc++.h>
#define fir(a, b, c) for(register int a =  b; a <= c; a ++)
#define in inline

using namespace std;
int t, n, p;

template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
long long ans[100];
int main()
{
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	read(t);
	int xx = 0;
	int tx = 0;
	while(xx < t)
	{
		xx ++;
		cin>>n>>p;
		ans[1] = 0;
		ans[2] = 2;
		ans[3] = 12;
		fir(i, 4, n)
		{
			if(i%2 == 0) ans[i] = ans[i-1]*i%p + i + (i-2)*(i-1)%p;
			else ans[i] = ans[i-1]*i%p + (i-1)*i%p;
			ans[i] %= p;
		}
		cout<<ans[n]<<endl;
	}

	return 0;
}


