#include<bits/stdc++.h>
using namespace std;
int n;
int l,r,al,ar;
long long ans=-1e10;
int a[100010];
long long find(int ll,int rr){
	long long MAX=-1e10,sum=0;
	l=1,r=0;
	for(int i=ll;i<=rr;++i){
		if(sum+a[i]<0){
			sum=0;
			l=i+1;
			r=i;
		}
		else{
			r++;
			sum+=a[i];
		}
		
		if(sum>MAX){
			MAX=sum;
			al=l;
			ar=r;
		}
	}
	return MAX;
}
long long find2(int ll,int rr){
	long long MAX=-1e10,sum=0;
	for(int i=ll;i<=rr;++i){
		if(sum+a[i]<0){
			sum=0;
		}
		else{
			sum+=a[i];
		}
		
		if(sum>MAX){
			MAX=sum;
		}
	}
	return MAX;
}

int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
		
	
	long long x=find(1,n);
	
	long long MIN=1e10,sum=0;
	for(int i=al+1;i<=ar-1;++i){
		sum=a[i];
		MIN=min(sum,MIN);
	}
		
	
	sum=0;
	for(int i=al;i<=ar;++i){
		
		if(sum+a[i]>0){
			sum=0;
		}
		else{
			sum+=a[i];
		}
		
		if(sum<MIN){
			MIN=sum;
		}
	}
	ans=max(ans,x-MIN);
	
	long long a1=find2(1,al-1),a2=find2(ar+1,n);
	ans=max(ans,x+a1);ans=max(ans,x+a2);
	
	cout<<ans<<endl;
	return 0;
}
