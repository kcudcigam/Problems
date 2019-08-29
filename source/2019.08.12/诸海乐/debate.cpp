#include<bits/stdc++.h>
using namespace std;
int a[401000];
int b[401000];
int c[401000];
int main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	int n,s1=0,s2=0,tt=0,ka=0,kb=0,kc=0;
	long long ans=0;
	cin>>n;
	for (int i=1;i<=n;i++){
		int x,y;
		cin>>x>>y;
		if (x==11){
			ans+=y;
			tt++;
			s1++;
			s2++;
		}
		else if (x==10){
			ka++;
			a[ka]=y;
		}
		else if (x==1){
			kb++;
			b[kb]=y;
		}
		else {
			kc++;
			c[kc]=y;
		}
	}
	sort(a+1,a+ka+1);
	reverse(a+1,a+ka+1);
	sort(b+1,b+kb+1);
	reverse(b+1,b+kb+1);
	sort(c+1,c+kc+1);
	reverse(c+1,c+kc+1);
	if (ka>=kb){
		for (int i=1;i<=kb;i++){
			ans+=a[i]+b[i];
			s1++;
			s2++;
			tt+=2;
		}
		int ia=kb+1,ic=1;
		while(true){
			if (s2*2<tt+1)break;
			if (ia<=ka){
				if (a[ia]>=c[ic]){
					ans+=a[ia];
					s1++;
					tt++;
					ia++;
				}
				else{
					ans+=c[ic];
					tt++;
					ic++;
				}
			}
			else {
				ans+=c[ic];
				tt++;
				ic++;
			}
		}
	}
	else {
		for (int i=1;i<=ka;i++){
			ans+=a[i]+b[i];
			s1++;
			s2++;
			tt+=2;
		}
		int ib=ka+1,ic=1;
		while(true){
			if (s1*2<tt+1)break;
			if (ib<=kb){
				if (b[ib]>=c[ic]){
					ans+=b[ib];
					s2++;
					tt++;
					ib++;
				}
				else{
					ans+=c[ic];
					tt++;
					ic++;
				}
			}
			else {
				ans+=c[ic];
				tt++;
				ic++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}


