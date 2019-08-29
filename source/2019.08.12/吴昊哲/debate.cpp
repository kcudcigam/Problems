#include<bits/stdc++.h>
using namespace std;
int yt1[500000],yt2[500000],yt12[500000],yt0[500000];
int cmp(int x,int y){return x>y;}
int n,yt,tot0,num1,num2,tot1,tot2,num12;
int ans,maxn,tot,mid;
int main()
{
	freopen("debate.in","r",stdin);
	freopen("debate.out","r",stdout);
    cin>>n;
    while(n>0)
	{
		n--;
	    cin>>yt;
	    if(yt==10)
	    {
		    tot1++;
	        cin>>yt1[tot1];
		}
		if(yt==01)
		{
		    tot2++;
		    cin>>yt2[tot2];
		}
		if(yt==00)
		{
		    tot0++;
	        cin>>yt0[tot0];
		}
		if(yt==11)
		{
		    cin>>yt12[num12];//cout<<yt12[num12]<<endl;
		    ans+=yt12[num12];
		    num12++;tot++;
		}
	}
	sort(yt1+1,yt1+num1+1,cmp);
	sort(yt2+1,yt2+num2+1,cmp);
	sort(yt0+1,yt0+tot0+1,cmp);
	if(tot1<=tot2)maxn=tot1;
	else maxn=tot2;
	for(int i=1;i<=maxn;i++)
	{
		ans=ans+yt1[i]+yt2[i];
		tot+=2;tot1--;tot2--;
		num1++;num2++;
	}
	num1=num1+num12;
	num2=num2+num12;
	int i=maxn+1;
	while(1){
		tot++;
		if(tot%2==1)mid=tot/2+1;
		else mid=tot/2;
        if(mid>num1||mid>num2||tot2==0){
			tot--;break;
		}
        else{//cout<<yt2[i]<<endl;
			ans=ans+yt2[i];i++;
			tot2--;num2++;
		}		
	}
    i=maxn+1;
	while(1){
		tot++;
		if(tot%2==1)mid=tot/2+1;
		else mid=tot/2;
        if(mid>num1||mid>num2||tot1==0){
			tot--;break;
		}
        else{//cout<<yt1[i]<<endl;
			ans=ans+yt1[i];i++;
			tot1--;num1++;
		}		
	}
    i=1;
	while(1)
	{
	    tot++;
		if(tot%2==1)mid=tot/2+1;
		else mid=tot/2;
        if(mid>num1||mid>num2||tot0==0)break;
        else
		{//cout<<yt0[i]<<endl;
			ans=ans+yt0[i];tot0--;
			i++;
	    }
	}
	cout<<ans<<endl;
	return 0;
}


