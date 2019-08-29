#include<bits/stdc++.h>
using namespace std;

int jnum[10][2]={0,0,2,3,1,5,1,6,2,6,2,7,3,7,5,6,0,0};
int spadd[8][2]={0,0,2,3,3,2,3,5,4,4,5,3,5,6,7,5};
int spdir[8][2]={0,0,-1,-1,-1,0,0,-1,0,1,1,0,1,1,0,0};
int mp[8][8],sum,n,k,fflag;
bool l1[8][35],l2[8][35],h[8][35],sp[8][35];

void dfs(int a,int b)
{
	int x=a,y=b;
	while(mp[x][y]!=0)
	{
		y++;
		if(y>jnum[x][1]) x++,y=jnum[x][0];
    }
	if(x==8&&y==0)
	{
	    sum++;
		if(sum==n)
		{	
		cout<<"Found"<<endl;
	    for(int i=1;i<=7;i++)
        for(int j=jnum[i][0];j<=jnum[i][1];j++)
            cout<<mp[i][j]<<" ";
        fflag=true;
        }
        return ;
	}
	int spnum[5],spn=0;
	for(int i=1;i<=8;i++)
	{
		int nx=spadd[i][0],ny=spadd[i][1];
		for(int j=1;j<=7;j++)
			if(nx+spdir[j][0]==x&&ny+spdir[j][1]==y)
			{
				spn++;spnum[spn]=i;break;
			}
	}
	for(int i=1;i<=k;i++)
	{
		bool flag=false;
		for(int j=1;j<=spn;j++)
			if(sp[spnum[j]][i]) 
			{
				flag=true;
				break;
			}
		if(!h[x][i]&&!l1[y][i]&&!l2[8-y][i]&&!flag)
		{
			
			h[x][i]=l1[y][i]=l2[8-y][i]=true;
			mp[x][y]=i;
			for(int j=1;j<=spn;j++)
		       sp[spnum[j]][i]=true;
			dfs(x,y);
			if(fflag) return ;
			h[x][i]=l1[y][i]=l2[8-y][i]=false;
			mp[x][y]=0;
			for(int j=1;j<=spn;j++)
		       sp[spnum[j]][i]=false;
		}
	}
	return ;
}

int main()
{
	freopen("hexodoku.in","r",stdin);
	freopen("hexodoku.out","w",stdout);
    cin>>k>>n;
    for(int i=1;i<=7;i++)
       for(int j=jnum[i][0];j<=jnum[i][1];j++)
       {
          cin>>mp[i][j];
          if(mp[i][j]!=0) 
          {
          	  h[i][mp[i][j]]=true;
          	  l1[j][mp[i][i]]=true;
          	  l2[8-j][mp[i][j]]=true;
          	  for(int k=1;k<=8;k++)
	          {
                  int nx=spadd[k][0],ny=spadd[k][1];
		          for(int l=1;l<=7;l++)
			         if(nx+spdir[l][0]==i&&ny+spdir[l][1]==j)
				         sp[k][mp[i][j]]=true;
	          }
		  }
       }
    if(k<=7) {cout<<"No way";return 0;}
    dfs(1,2);
    if(!fflag)cout<<"No way";
	return 0;
}
