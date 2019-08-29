#include<bits/stdc++.h>
#define fir(a, b, c) for(register int a =  b; a <= c; a ++)
#define in inline
using namespace std;

typedef long long LL;
int n, a[100010], b[100010], lb;
LL  ans;
int tx1, tx2;

template <typename T> void read(T &x)
{
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}

in LL work(int l, int r)
{
	if(l > r) return 0;
	if(l == r) return a[l];
	LL tans = a[l], anst = a[l];
	tx2 = l;
	fir(i, l+1, r)
	{
		tans += a[i];
		if(anst < tans)
		{
			anst = tans;
			tx2 = i;
		}
		if(tans < 0)
		{
			tans = 0;
		}
	}
	return anst;
}

int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	read(n);
	fir(i, 1, n)
	{
		read(a[i]);
		if(a[i] > 0) 
		{
			lb ++;
			b[lb] = i;
		}
	}
	
	fir(k, 1, lb)
	{
		int x =b[k];
		LL ans1 = work(x, n);
		int t2 = tx2;
		LL ans2 = max(work(t2+1, n), work(1, x-1));
		ans = max(ans , ans1+ans2);
	}
	cout<<ans<<endl;
	return 0;
}


