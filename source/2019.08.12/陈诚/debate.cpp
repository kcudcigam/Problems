#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template <typename T> inline void rd(T &x)
{
	x=0; int f=1; char ch=0;
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-f;
	for(; isdigit(ch);ch=getchar()) x=(x<<1)+(x<<3)+ch-48;
	x*=f;
}
template <typename T> inline void wrote(T x)
{
	if(x<0) {putchar('-'); wrote(-x); return;}
	if(x<10) {putchar(x+48); return;}
	wrote(x/10);
	putchar(x%10+48);
}
priority_queue <int> aq;
priority_queue <int> bq;
priority_queue <int> cq;
int n,x,v,sum,snd,fst;
int main()
{
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	rd(n);
	for(int i=1; i<=n; ++i)
	{
		rd(x); rd(v);
		sum+=v;
		if(x==0) cq.push(-v);
		if(x==1)
		{
			bq.push(-v);
			++snd;
		}
		if(x==10)
		{
			aq.push(-v);
			++fst;
		}
		if(x==11)
		{
			++snd;++fst;
		}
	}
	int tot=n;
	while(1)
	{
		if(snd*2>=tot && fst*2>=tot) break;
		if(snd*2<tot && fst*2<tot || snd*2==tot || fst*2==tot)
		{
			 --tot; sum+=cq.top(); cq.pop(); continue;
		}
		if(snd*2<tot && fst*2-tot>0)
		{
			if(aq.top()>cq.top())
			{
				--tot; --fst; sum+=aq.top(); aq.pop(); continue;
			}
			else
			{
				--tot; sum+=cq.top(); cq.pop(); continue;
			}
		}
		if(fst*2<tot && snd*2-tot>0)
		{
			if(bq.top()>cq.top())
			{
				--tot; --snd; sum+=bq.top(); bq.pop(); continue; 
			}
			else
			{
				--tot; sum+=cq.top(); cq.pop(); continue;
			}
		}
	}
	wrote(sum);
	puts("");
 	return 0;
}

