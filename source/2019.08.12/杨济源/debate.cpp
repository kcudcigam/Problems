#include<bits/stdc++.h>
#define LL long long
using namespace std;
template <typename T> inline void read(T &x)
{
	int f = 1; x = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	x *= f;
}
const int N = 4e5 + 5;
struct info
{
	int op;
	LL act;
}p[N];
inline bool comp(info x, info y)
{
	if (x.op != y.op) return x.op < y.op;
	return x.act > y.act;
}
int n, tot;
priority_queue <pair <LL, int> > q1, q2;
priority_queue <LL, vector <LL>, greater <LL> > q3;
LL ans;
int now[15];
int main(){
	freopen ("debate.in", "r", stdin);
	freopen ("debate.out", "w", stdout);
	read(n);
	
	int op, act;
	int now1 = 0, now2 = 0, sum = 0;
	
	for (int i = 1; i <= n; i++)
	{
		read(op); read(act);
		
		if (op == 11)
		{
			ans += act;
			now[1]++; now[10]++; sum++;
		}
		
		else if (op == 10) q1.push(make_pair(act, op));
		else if (op == 1) q2.push(make_pair(act, op));
		
		else p[++tot] = (info) { op, act };
	}
	
	while (!q1.empty() && !q2.empty())
	{
		ans += q1.top().first + q2.top().first;
		now[1]++; now[10]++; sum += 2;
		q1.pop(); q2.pop();
	}
	int sp;
	
	while (!q1.empty()) p[++tot] = (info) { q1.top().second, q1.top().first }, q1.pop(), sp = 1;
	while (!q2.empty()) p[++tot] = (info) { q2.top().second, q2.top().first }, q2.pop(), sp = 10;
	
	sort(p + 1, p + tot + 1, comp);
	
	int i = 1;
	while (i <= tot)
	{
		if (p[i].op == 0)
		{
			if (2 * now[sp] >= (sum + 1))
			{
				q3.push(p[i].act);
				ans += p[i].act;
				sum++;
			}
		}
		else
		{
			LL nowp = 0; int pp;
			for (int j = i; j <= tot; j++)
			{
				pp = j - 1;
				int sz = j - i + 1;
				if (2 * now[sp] < (sum - (!q3.empty()) + sz)) break;
				else nowp += p[j].act;
			}
			if (q3.empty())
			{
				ans += nowp;
				sum = sum + (pp - i + 1);
				now[11 - sp] += (pp - i + 1);
				i = pp + 1;
			}
			else
			if (nowp > q3.top())
			{
				ans = ans - q3.top() + nowp;
				q3.pop();
				sum = sum - 1 + (pp - i + 1);
				now[11 - sp] +=  (pp - i + 1);
				i = pp + 1;
			}
		}
		i++;
	}
	
	printf("%lld\n", ans);
  return 0;
}
