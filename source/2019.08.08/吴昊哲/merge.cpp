#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x)
{
    int f=1;x=0;char c=getchar();
    for (;!isdigit(c);c=getchar()) if (c==' -') f= -f;
    for (; isdigit(c);c=getchar()) x=x*10+c -'0';
    x*=f;
}
int n,Q,num,x,y,a,b;
int nm[6000][6000],cnm[6000][6000];
int main()
{
	//freopen("merge.in","r",stdin);
	//freopen("merge.out","w",stdout);
    read(n);read(Q);
    for(int i=1;i<=n;i++)
    {
    	nm[i][1]=1;
    	nm[i][0]=1;
	}
    for(int i=1;i<=Q;i++)
    {
    	cin>>num;
    	if(num==1)
		{
    		read(x),read(y);
    		if(x==y)continue;
    		else 
    		{
    			for(int i=1;i<=nm[y][0];i++)
    			{
    			    nm[x][nm[y][0]+i]=nm[y][i];	
    			    nm[y][i]=0;
				}
				nm[x][0]+=nm[y][0];
			}
		}
    	if(num==2)
		{
			read(a),read(b);
			for(int i=1;i<=nm[a][0];i++)
			{
				cnm[a][i]+=nm[a][i]*b;
			}
		}
	}
	for(int i;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(cnm[i][j]!=0)cout<<cnm[i][j]<<endl;
		}
	}
	return 0;
}

