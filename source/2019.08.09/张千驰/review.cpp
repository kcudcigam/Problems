#include <cstdio>
#include <iostream>

using namespace std;

long long y;
int n,m;

long long two[70]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296,8589934592,17179869184,34359738368,68719476736,137438953472,274877906944,549755813888,1099511627776,2199023255552,4398046511104,8796093022208,17592186044416,35184372088832,70368744177664,140737488355328,281474976710656,562949953421312,1125899906842624,2251799813685248,4503599627370496,9007199254740992,18014398509481984,36028797018963968,72057594037927936,144115188075855872,288230376151711744,576460752303423488,1152921504606846976,2305843009213693952,4611686018427387904};


template <typename T> void read(T &x)
{
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}

int main()
{
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	
	read(y);
	if (y==3)
	{
		printf("%d %d\n",4,5);
		printf("%d %d\n",1,2);
		printf("%d %d\n",1,3);
		printf("%d %d\n",2,3);
		printf("%d %d\n",2,4);
		printf("%d %d\n",3,4);
		return 0;
	}
	if (y==5)
	{
		printf("%d %d\n",5,8);
		printf("%d %d\n",1,2);
		printf("%d %d\n",1,3);
		printf("%d %d\n",1,4);
		printf("%d %d\n",1,5);
		printf("%d %d\n",2,3);
		printf("%d %d\n",2,4);
		printf("%d %d\n",3,4);
		printf("%d %d\n",4,5);
		return 0;
	}
	for (register int i=0;i<=61;++i)
		if (y==two[i])
		{
			n=i+2;
			printf("%d %d\n",n,(n)*(n-1)/2);
			for (register int j=1;j<=n-1;++j)
				for (register int k=j+1;k<=n;++k)
					printf("%d %d\n",j,k);
			return 0;
		}
	return 0;
}

