#include<bits/stdc++.h>
using namespace std;
int n,i,s,ans,k;
string c;
priority_queue<int> a,b,d;
int main(){
  freopen("debate.in","r",stdin);
  freopen("debate.out","w",stdout);
  cin>>n;
  for (i=1;i<=n;i++)
  {
  	cin>>c>>s;
  	if (c=="11") {
  		ans+=s;
  		k++;
	  }
	  else if (c=="10") {
	  	a.push(s);
	  }
	  else if (c=="01")
	  {
	  	b.push(s);
	  }
	  else d.push(s);
   } 
   while (a.size()>0&&b.size()>0) {
   	ans+=a.top()+b.top();
   	a.pop(); b.pop();
   }
   while (a.size()>0) {
   	d.push(a.top());
   	a.pop();
   }
   while (b.size()>0) {
   	d.push(b.top());
   	b.pop();
   }
   for (i=1;i<=k;i++)
   {
   	if (d.size()>0) {
   		ans+=d.top();
   		d.pop();
	   }
   }
   cout<<ans<<endl;
  return 0;
}


