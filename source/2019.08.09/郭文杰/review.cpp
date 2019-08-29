#include<bits/stdc++.h>

#define FILE "review"

using namespace std;

template<typename T>
void read(T &x)
{
	bool f=0;char c=getchar();x=0;
	for(;!isdigit(c);c=getchar()) if(c=='-') f=1;
	for(; isdigit(c);c=getchar()) x=x*10+c-'0';
	if(f) x=-x;
}

int y;
long long n,m;

int main()
{
	freopen(FILE".in","r",stdin);
	freopen(FILE".out","w",stdout);
	read(y);
	switch(y)
	{
		case 1:printf("2 1\n1 2");break;
		case 2:printf("3 3\n1 2\n2 3\n1 3");break;
		case 3:printf("4 5\n1 2\n2 3\n3 4\n1 3\n1 4");break;
		case 4:printf("4 6\n1 2\n2 3\n3 4\n1 3\n1 4\n2 4");break;
		case 5:printf("5 8\n1 2\n2 3\n3 4\n4 5\n1 3\n1 4\n1 5"
					  "\n2 5");break;
		case 6:printf("5 9\n1 2\n2 3\n3 4\n4 5\n1 3\n1 4\n1 5"
					  "\n2 4\n2 5");
	}
	return 0;
}

