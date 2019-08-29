#include<bits/stdc++.h>
using namespace std;

int l1,r1,l2,r2;
int n,m;
int a[500010],b[500010];

int ri() {
char c = getchar(); int x = 0; for(;c < '0' || c > '9'; c = getchar());
for(;c >= '0' && c <= '9'; c = getchar()) x = x * 10 - '0' + c; return x;
}

void efen(int la,int ra,int lb,int rb)
{
//	printf("3# : %d %d %d %d\n",la,ra,lb,rb);
	if(l1 - r1 + l2 - r2 + 2 <= 16)
	{
		int nla = la,nlb = lb;
		for(int i = 1;i <= (r1 + r2 - l1 - l2 + 3) / 2 - 1;i++)
		{
			if(a[nla] < b[nlb])
			nla++;
			else nlb++;
		}
		printf("%d\n",min(a[nla],b[nlb]));
	}
	else
	{
		int mid_a = la + ra + 1 >> 1;
		int mid_b = lb + rb + 1>> 1;
		if(a[mid_a] > b[mid_b])
		{
			efen(la,mid_a,mid_b,rb);
		}
		else if(a[mid_a] < b[mid_b])
		{
			efen(mid_a,ra,lb,mid_b);
		}
		else if(a[mid_a] == b[mid_b])
		{
			if((la - l1 + lb - l2) - (r1 - ra + r2 - rb) == 0 || (la - l1 + lb - l2) - (r1 - ra + r2 - rb) == 1)
			printf("%d\n",a[mid_a]);
			else if((la - l1 + lb - l2) - (r1 - ra + r2 - rb) < 0)
			{
				int nla = la,nlb = lb;
				for(int i = 1;i < (r1 - ra + r2 - rb) - (la - l1 + lb - l2);i++)
				{
					if(a[nla] < b[nlb])
					nla++;
					else nlb++;
				}
				efen(nla,ra,nlb,rb);
			}
			else
			{
				int nra = ra,nrb = rb;
				for(int i = 1;i < (la - l1 + lb - l2) - (r1 - ra + r2 - rb);i++)
				{
					if(a[nra] < b[nrb])
					nra++;
					else nrb++;
				}
				efen(la,nra,lb,nrb);
			}
		}
	}
}

int main()
{
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	
	n = ri();m = ri();
	for(int i = 1;i <= n;i++)
		a[i] = ri();
	for(int i = 1;i <= n;i++)
		b[i] = ri();
	
	for(int i = 1;i <= m;i++)
	{
		int in;
		in = ri();
		if(in == 1)
		{
			int x,y,z;
			x = ri();y = ri();z = ri();
			if(x == 0)
				a[y] = z;
			else if(x == 1)
				b[y] = z;
			else	printf("Errow : #2\n");
		}
		else if(in == 2)
		{
			l1 = ri();r1 = ri();l2 = ri();r2 = ri();
			efen(l1,r1,l2,r2);
		}
		else
		{
			printf("Errow : #1\n");
			return 0;
		}
	}
	
	return 0;
}

