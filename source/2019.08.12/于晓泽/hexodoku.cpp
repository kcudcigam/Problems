#include<cstdio>
#include<algorithm>
using namespace std;
int k,n,a[10][10],cnt,s[10]={0,2,1,1,2,2,3,5},t[10]={0,3,5,6,6,7,7,6}; bool c[10][10],flag;

int hang[7]={0,0,0,-1,-1,1,1},
    lie [7]={0,-1,1,0,-1,0,1};
inline bool check(int x,int y,int z)
 {
  for(int j=s[x];j<=t[x];j++) if(a[x][j]==z) return 0;
  for(int j=1;j<=7;j++)       if(a[j][y]==z) return 0;
   for(int j=1;j<=7;j++)      if(a[j][j+y-x]==z) return 0;
  for(int i=0;i<=6;i++)
    if(c[x+hang[i]][y+lie[i]])
     { int xx=x+hang[i],yy=y+lie[i];
       
       for(int j=0;j<=6;j++)
        if(a[xx+hang[j]][yy+lie[j]]==z) return 0;
	 }
  return 1; 
 }
void dfs(int x,int y)
 {if(x==8) { cnt++; 
            if(cnt==n) 
             {   printf("Found\n%d %d",a[1][2],a[1][3]);	
				 for(int j=1;j<=5;j++) 	printf(" %d",a[2][j]);	
				 for(int j=1;j<=6;j++) 	printf(" %d",a[3][j]);
				 for(int j=2;j<=6;j++) 	printf(" %d",a[4][j]);	
				 for(int j=2;j<=7;j++) 	printf(" %d",a[5][j]);	
				 for(int j=3;j<=7;j++) 	printf(" %d",a[6][j]);		
				 for(int j=5;j<=6;j++) 	printf(" %d",a[7][j]);	
				 exit(0);
			 }
			return ;
           }
           
  
  for(int i=1;i<=k;i++)	
    if(check(x,y,i)) { a[x][y]=i;
                       if(y==t[x]) dfs(x+1,s[x+1]);
                       else        dfs(x,y+1);
                     }
  
 }
int main()
 {
 freopen("hexodoku.in","r",stdin);
 freopen("hexodoku.out","w",stdout);		
 scanf("%d%d",&k,&n);	

 printf("No way\n");
 
return 0;
 }
