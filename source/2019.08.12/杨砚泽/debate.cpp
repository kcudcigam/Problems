#include<bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x)
{
  int f=1;x=0;
  char ch=getchar();
  for (;!isdigit(ch);ch=getchar()) if (ch=='-') f=-1;
  for (;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
  x*=f;
}struct node{
	int m1;
	int m2;
};
node a[400051];
int num=0,sum=0;
int l1=0,l2=0,l3;
node a1[400051],a2[400051],a3[800051];
bool cmp(node x,node y)
{
	return x.m2>y.m2;
}
inline int chu2(int t)
{
	if (t%2==0) return t/2;
	else return t/2+1;
}
int v[400051];
int main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
    int n,m;
    string s;
    read(n);
    memset(a,0,sizeof(a));
    for (int i=1;i<=n;i++)
    {
     cin>>s;
     if (s[0]=='0') a[i].m1=0;
     else a[i].m1=1;
     if (s[1]=='0') a[i].m2=0;
     else a[i].m2=1;
     read(v[i]);
     if (a[i].m1==1&&a[i].m2==1) {
     	sum+=v[i];
     	num++;
	 }
	 if (a[i].m1==0&&a[i].m2==1) {
	 	l2++;
	 	a2[l2].m1=i;
	 	a2[l2].m2=v[i];
	 }
     if (a[i].m1==1&&a[i].m2==0) {
     	l1++;
     	a1[l1].m1=i;
     	a1[l1].m2=v[i];
	 }
	 if (a[i].m1==0&&a[i].m2==0)
	 {
	 	l3++;
	 	a3[l3].m1=i;
	 	a3[l3].m2=v[i];
	 }
	 
	}	
//	cout<<l1<<" "<<l2<<endl;
	int p=num;
	sort(a1+1,a1+l1+1,cmp);
	sort(a2+1,a2+l2+1,cmp);
	int f,l;
	if (l1<=l2) {
		f=0;
		l=l1;
	}
	if (l1>l2)
	{
		f=1;
		l=l2;
	}

	for (int i=1;i<=l;i++)
	  {
	  	num=num+2;
	  	sum=sum+v[a1[i].m1]+v[a2[i].m1];
	  }
	if (f==0)
	{
		for (int i=l+1;i<=l2;i++)
		  {
		  	l3++;
		  	a3[l3]=a2[i];
		  }
		sort(a3+1,a3+l3+1,cmp);
		for (int i=1;i<=l3;i++)
		  {	num++;
		  	if (p+l<chu2(num)) break;	
		  		sum=sum+v[a3[i].m1];
		  }
	}
	else 
	{
		for (int i=l+1;i<=l1;i++)
		  {
		  	l3++;
		  	a3[l3]=a1[i];
		  }
		sort(a3+1,a3+l3+1,cmp);
		for (int i=1;i<=l3;i++)
		  {
			 num++;
		  	if (p+l<chu2(num)) break;		
		  		sum=sum+v[a3[i].m1];
		  }
	}
	cout<<sum<<endl;
	return 0;
}


