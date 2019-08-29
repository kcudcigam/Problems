#include<bits/stdc++.h>
using namespace std;
int a[400008],b[400008];
string st[400008];
int n,maxi=-1;
int zzc(string st)
{
	int f=0,sum1=0,sum2=0;
	for (int i=0;i<st.size();i++)
	{
		if ((i+1)%2==1&&st[i]=='1') sum1++;
		if ((i+1)%2==0&&st[i]=='1') sum2++;
	 } 
	 int k=0;
	 k=st.size()/2; 
    if (k%2==0) k=k/2;
	         else k=k/2+1;
	if (sum1>=k&&sum2>=k) return 1;
	return 0;
}
int hh(string st)
{
	int i,ans=0;
	for (i=0;i<st.size();i++)
	{
		ans=ans+a[char(st[i])-48];
	}
	return ans;
 } 
void dfs(int dep,string sti,string stii)
{
	if (dep>n) {
	  if (zzc(sti)==1) maxi=max(maxi,hh(stii));
	}
	else {
		dfs(dep+1,sti,stii);
		dfs(dep+1,sti+st[dep],stii+char(dep+48));
	}
}
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
   freopen("debate.in","r",stdin);
   freopen("debate.out","w",stdout);
   int i,j=0,k1=0,k2=0,sum=0;
   cin>>n;
   for (i=1;i<=n;i++)
   {
      cin>>st[i];
	  cin>>a[i]; 
   }
   if (n<10) {dfs(1,"","");cout<<maxi<<endl;return 0;} 
   for (i=1;i<=n;i++)
   {
   	if (st[i]=="00") {
   		j++;
   		b[j]=a[i];
     }
    if (st[i]=="01")
	{ 
      	k2++;
    }
    if (st[i]=="10")
      k1++;
    if (st[i]=="11")
    {
    	k1++;
    	k2++;
	}
   }
   for (i=1;i<=n;i++)
     if (st[i]!="00") sum=sum+a[i];
   sort(b+1,b+j+1,cmp);
   int ojk=min(k1*2,k2*2);
   int umb=ojk-(n-j);
   for (i=1;i<=umb;i++)
     sum=sum+b[i];
   cout<<sum<<endl; 
   return 0; 	
} 
