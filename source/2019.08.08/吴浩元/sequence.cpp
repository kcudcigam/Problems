#include<bits/stdc++.h>
using namespace std;

#define LS p * 2
#define RS p * 2 + 1

struct tnode
{
	long long val, tag;
}t[2000010]; // 4x memory
long long n, m, l, r, s, e, sum, ans;

template <typename T> void read(T &x)
{
	long long f = 1; x = 0; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}

void push_up(long long p)
{
	t[p].val = t[LS].val + t[RS].val;
}

void push_down(long long p, long long l, long long r)
{
	long long mid = (l + r) / 2;
	t[LS].val += (mid - l + 1) * t[p].tag;
	t[LS].tag += t[p].tag;
	t[RS].val += (r - mid) * t[p].tag;
	t[RS].tag += t[p].tag;
	t[p].tag = 0;
}

void update(long long p, long long l, long long r, long long ql, long long qr, long long d)
{
	if (ql <= l && qr >= r)
	{
		t[p].val += (r - l + 1) * d;
		t[p].tag += d;
		return;
	}
	push_down(p, l, r);
	long long mid = (l + r) / 2;
	if (ql <= mid) update(LS, l, mid, ql, qr, d);
	if (qr > mid) update(RS, mid + 1, r, ql, qr, d);
	push_up(p);
}

long long query(long long p, long long l, long long r, long long ql, long long qr)
{
	if (ql <= l && qr >= r)
		return t[p].val;
	push_down(p, l, r);
	long long mid = (l + r) / 2, sum = 0;
	if (ql <= mid) sum += query(LS, l, mid, ql, qr);
	if (qr > mid) sum += query(RS, mid + 1, r, ql, qr);
	return sum;
}

void dupd(long long x, long long d) { update(1, 1, n, x, x, d); }
void rupd(long long l, long long r, long long d) { update(1, 1, n, l, r, d); }
long long dque(long long x) { return query(1, 1, n, x, x); }
long long rque(long long l, long long r) { return query(1, 1, n, l, r); }

int main()
{
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	
	read(n); read(m);
	for (long long i = 1; i <= m; i++)
	{
		read(l); read(r); read(s); read(e);
		dupd(l, s); dupd(r + 1, -e);
		if (l < r)
			rupd(l + 1, r, (e - s) / (r - l));
	}
	for (long long i = 1; i <= n; i++)
	{
		long long now = dque(i);
		sum += now;
		ans ^= sum;
	}
	cout << ans << endl;

	return 0;
}

