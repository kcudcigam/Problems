#include<bits/stdc++.h>
using namespace std;
int n,b[15],sum,o,p,q,r,l,m=400005,s,d,e=1,num,f=1;
struct node{
	int t,h;
}a[400005];
int cmp(node x,node y){
	if(x.t==y.t)return x.h>y.h;
	else return x.t>y.t;
}
int main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i].t>>a[i].h;
		b[a[i].t]++;
	}
	sort(a+1,a+1+n,cmp);
	o=b[11];p=b[10];q=b[1];r=b[0];
	for(int i=1;i<=o;++i){
		sum+=a[i].h;
		l++;
	}
	if(p>q){
		m=q;
		for(int i=1;i<=m;++i){
		sum+=a[o+i].h;
		sum+=a[o+p+i].h;
		l+=2;
		}
		for(int i=1;i<=400005;i++){
			if((l+i)%2==0&&(l+i)/2>o+m){
				num=i-1;
				break;
			}
			if((l+i)%2==1&&(l+i)/2+1>o+m){
				num=i-1;
				break;
			}
		}
		s=p-q;
		for(int i=1;i<=num;i++){
			if(f==s){
				d=a[o+p+q+e].h;
				e++;
				sum+=d;
				d=0;
			}
			if(e==r){
				d=a[o+m+f].h;
				f++;
				sum+=d;
				d=0;
			}
			if(f!=s&&e!=r){
				d=max(a[o+p+q+e].h,a[o+m+f].h);
				if(a[o+p+q+e].h>a[o+m+f].h)e++;
				else f++;
				sum+=d;
				d=0;
			}
		}
	}
	if(p<q){
		m=p;
		for(int i=1;i<=m;++i){
		sum+=a[o+i].h;
		sum+=a[o+p+i].h;
		l+=2;
		}
		s=q-p;
		for(int i=1;i<=400005;i++){
			if((l+i)%2==0&&(l+i)/2>o+m){
				num=i-1;
				break;
			}
			if((l+i)%2==1&&(l+i)/2+1>o+m){
				num=i-1;
				break;
			}
		}
		for(int i=1;i<=num;i++){
			if(f==s){
				d=a[o+p+q+e].h;
				e++;
				sum+=d;
				d=0;
			}
			if(e==r){
				d=a[o+p+m+f].h;
				f++;
				sum+=d;
				d=0;
			}
			if(f!=s&&e!=r){
				d=max(a[o+p+q+e].h,a[o+p+m+f].h);
				if(a[o+p+q+e].h>a[o+m+p+f].h)e++;
				else f++;
				sum+=d;
				d=0;
			}
		}
	}
	if(q==p){
		m=q;
	for(int i=1;i<=m;++i){
		sum+=a[o+i].h;
		sum+=a[o+p+i].h;
		l+=2;
		}
		for(int i=1;i<=400005;i++){
			if((l+i)%2==0&&(l+i)/2>o+m){
				num=i-1;
				break;
			}
			if((l+i)%2==1&&(l+i)/2+1>o+m){
				num=i-1;
				break;
			}
		}
		for(int i=1;i<=num;i++){
			sum+=a[o+p+q+i].h;
			l++;
		}
	}
	cout<<sum<<endl;
	return 0;
}
