#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
void xiaoshuju(ll Y)
{
	if  (Y==1)
		{
			printf("%d %d\n",1,0);
			exit(0);
		}
	if  (Y==2)
		{
			printf("%d %d\n",3,3);
			printf("%d %d\n",1,2);
			printf("%d %d\n",2,3);
			printf("%d %d\n",1,3);
			exit(0);
		}
	if  (Y==3)
		{
			printf("%d %d\n",4,5);
			printf("%d %d\n",1,2);
			printf("%d %d\n",1,3);
			printf("%d %d\n",1,4);
			printf("%d %d\n",2,4);
			printf("%d %d\n",3,4);
			exit(0);
		}
	if  (Y==4)
		{
			printf("%d %d\n",5,6);
			printf("%d %d\n",1,2);
			printf("%d %d\n",1,3);
			printf("%d %d\n",2,3);
			printf("%d %d\n",3,4);
			printf("%d %d\n",3,5);
			printf("%d %d\n",4,5);
			exit(0);
		}
	if  (Y==5)
		{
			printf("%d %d\n",5,7);
			printf("%d %d\n",1,2);
			printf("%d %d\n",1,3);
			printf("%d %d\n",2,3);
			printf("%d %d\n",3,4);
			printf("%d %d\n",3,5);
			printf("%d %d\n",4,5);
			printf("%d %d\n",1,5);
			exit(0);
		}
}
void _2(int x)
{
	int N=2*x+1,M=3*x;
	printf("%d %d\n",N,M);
	for  (int i=1;i<=x;i++)
		{
			int xx=2*i-1,yy=2*i,zz=2*i+1;
			printf("%d %d\n",xx,yy);
			printf("%d %d\n",yy,zz);
			printf("%d %d\n",xx,zz);
		}
	exit(0);
}
int pp[1005];
void fenjie(ll x)
{
	ll xx=x,kk=2,tot=0;
	int N=1,M=0;
	while  (x!=1&&kk*kk<=xx)
		{
			if  (x%kk==0)
				{
					x/=kk;
					pp[++tot]=kk;
					N+=kk,M+=2*kk-1;
				}
			else
				kk++;
		}
	if  (x!=1)
		pp[++tot]=x,N+=x,M+=2*x-1;
	printf("%d %d\n",N,M);
	int last_=1;
	for  (int i=1;i<=tot;i++)
		{
			for  (int j=1;j<pp[i];j++)
				{
					printf("%d %d\n",last_,last_+j);
					printf("%d %d\n",last_+j,last_+pp[i]);
				}
			printf("%d %d\n",last_,last_+pp[i]);
			last_+=pp[i];
		}
	exit(0);
}
int main()
{
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	ll Y;
	cin>>Y;
	if  (Y<=5)
		xiaoshuju(Y);
	if  (Y>1000&&Y<=1000000000)
		{
			int x=log2(Y);
			_2(x);
		}
	fenjie(Y);
	return 0;
}

