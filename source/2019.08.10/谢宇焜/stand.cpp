#include<bits/stdc++.h>
#define ll long long
#define fir(a, b, c) for(int a = b; a <= c; a ++)
#define in inline
using namespace std;

template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}

const int N = 250;
typedef pair<int, int> pl;
int n, m, x1, x2, x3, x4, x5;
pl a[N+5];

in vector<int> mul(vector<int> x, int y)
{
	fir(j, 0, x.size()-1)
		x[j] *= y;
	int jw = 0;
	fir(j, 0, x.size()-1)
	{
		x[j] += jw;
		jw = x[j]/10;
		x[j] = x[j]%10;
	}
	x.push_back(jw);
	while(x[x.size()-1] >= 10)
	{
		x.push_back(x[x.size()-1]/10);
		x[x.size()-2] %= 10;
	}
	return x;
}

in vector<int> add(vector<int> x, vector<int> y)
{
	if(x.size() < y.size())
	{
		fir(j, x.size(), y.size()-1)
			x.push_back(0);
	}
	else
	{
		fir(j, y.size(), x.size()-1)
			y.push_back(0);
	}
	fir(j, 0, max(x.size(), y.size())-1)
	{
		x[j] = x[j] + y[j];
	}
	int jw = 0;
	fir(j, 0, x.size()-1)
	{
		x[j] += jw;
		jw = x[j]/10;
		x[j] = x[j]%10;
	}
	if(x[x.size()-1] > 10)
	{
		x.push_back(x[x.size()-1]/10);
		x[x.size()-2] %= 10;
	}
	return x;
}

in vector<int> g(int k)
{
	vector<int> t, t1;
	t.clear();
	t1.clear();
	t.push_back(1);
	t = mul(t, k);
	t1 = add(t1, mul(t, x1));
	t = mul(t ,k);
	t1 = add(t1, mul(t, x2));
	t = mul(t ,k);
	t1 = add(t1, mul(t, x3));
	t = mul(t ,k);
	t1 = add(t1, mul(t, x4));
	t = mul(t ,k);
	t1 = add(t1, mul(t, x5));
	return t1;
}

in bool cmp(pl x ,pl y){return x.first < y.first;}

int sum[N+5], l;

int main()
{
    freopen("stand.in","r",stdin);
    freopen("stand.out","w",stdout);
	read(n); read(m);
	read(x1); read(x2); read(x3); read(x4); read(x5);
	fir(i, 1, n) 
		read(a[i].first), read(a[i].second);
	sort(a+1, a+1+n, cmp);
	
	int r = a[1].second;
	l ++;
	sum[l] ++;
	fir(i, 2, n)
		if(a[i].first <= r)
		{
			sum[l] ++;
			r = min(r, a[i].second);
		}
		else
		{
			l ++;
			sum[l]++;
			r = a[i].second;
		}
	
	vector<int> ans;
	ans.clear();
	fir(i, 1, l)
		ans = add(ans, g(sum[i]));
	
	bool fin = 1;
	bool ff = 1;
	for(int i = ans.size()-1; i >= 0; i --)
	{
		if(ans[i] == 0 && fin == 1) continue;
		fin = 0;
		cout<<ans[i];
		ff = 0;
	}
	if(ff == 1) cout<<0;
	cout<<endl;
	return 0;
}


