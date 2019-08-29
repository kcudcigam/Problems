#include<bits/stdc++.h>
#define N 400001
using namespace std;
int q[N],h[N],to_3,to_2,to_1;
priority_queue<int> p;
char a,b;
int n;
int v[N];
int f[N][3];
int t[3],d[5],no[5],ans;
int main(){
freopen("debate.in","r",stdin);
freopen("debate.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++)
{
 
 cin>>a>>b>>v[i];
 f[i][1]=a-48;
 f[i][2]=b-48;

 //if(f[i][1]) t[1]++;
 //if(f[i][2]) t[2]++;
 if(f[i][1]==1&&f[i][2]==0) to_1+=v[i],d[1]++,q[d[1]]=v[i];

 if(f[i][1]==0&&f[i][2]==1) to_2+=v[i],d[2]++,h[d[2]]=v[i];
 if(f[i][1]==0&&f[i][2]==0) to_3+=v[i],d[3]++,p.push(v[i]);
  if(f[i][1]==1&&f[i][2]==1) {
  	ans+=v[i];
  	d[4]++;
  }

}

sort(q+1,q+d[1]+1);
sort(h+1,h+d[2]+1);
int nn=d[4];
if(d[1]>d[2]) { 
if(d[2]>0)
for(int i=1;i<=d[2];i++)
ans+=q[i]+h[i],nn+=2;
for(int i=d[2]+1;i<=d[1];i++){
	p.push(q[i]);
	
}
while(nn/2<d[2]+d[4]){
ans+=p.top();
p.pop();
nn++;
}}
if(d[1]<d[2]) { 
if(d[1]>0)
for(int i=1;i<=d[1];i++)
ans+=q[i]+h[i],nn+=2;
for(int i=d[1]+1;i<=d[2];i++){
	p.push(h[i]);
}
while(nn/2<(d[1]+d[4])){
ans+=p.top();p.pop();nn++;
}}
if(d[1]==d[2]) {ans+=to_1+to_2;
if(d[3]<=d[4]) ans+=to_3;
else for(int i=1;i<=d[4];i++){
	ans+=p.top();p.pop();
}}
cout<<ans<<endl;
	return 0;
}


