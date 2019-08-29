#include<cstdio>
#include<algorithm>
using namespace std;
int x,y;
int main()
 {
 freopen("area.in","r",stdin);
 freopen("area.out","w",stdout);	
 scanf("%d%d",&x,&y);

 x++; y++;
 if(x%4==2 && y%4==2) printf("1\n");
 else if((x%8==2&&y%8==4) || (x%8==3 && (y%8==3 || y%8==4)) || (x%8==4 && (y%8==2 || y%8==3)) )
       printf("5\n");
 else printf("infinity\n");

return 0; 	
 } 
