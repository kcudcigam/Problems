#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int N=4*1e5+15;
int n,ans;  
priority_queue<int> q[4],b[1];
int main()
 {
 freopen("debate.in","r",stdin);
 freopen("debate.out","w",stdout);	 
 scanf("%d",&n); char op[10]; int r;
 
 for(int i=1;i<=n;i++)
  {scanf("%s%d",op+1,&r);
   if(op[1]=='0'&&op[2]=='0')      q[0].push(r);
   else if(op[1]=='0'&&op[2]=='1') q[1].push(r);
   else if(op[1]=='1'&&op[2]=='0') q[2].push(r);
   else if(op[1]=='1'&&op[2]=='1') q[3].push(r);
  }

 while(q[0].size() && q[3].size())
  {int x=q[0].top(),y=q[3].top(); q[0].pop(); q[3].pop();
   b[0].push(-x); 
   ans=ans+x+y;
  }
 while(q[1].size() && q[2].size())
  {int x=q[1].top(),y=q[2].top(); q[1].pop(); q[2].pop();
   ans=ans+x+y;
  }
  
 while(q[3].size()) {ans=ans+q[3].top(); q[3].pop();}  
 while(q[1].size()) {q[2].push(q[1].top()); q[1].pop(); }
 
 while(q[2].size() && b[0].size())
  {int x=q[2].top(),y=-b[0].top();
      if(x<y) break;
      q[2].pop();     b[0].pop();
      ans=ans+x-y;
  }
 printf("%d\n",ans); 
return 0; 	
 } 
