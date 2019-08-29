#include<bits/stdc++.h>
#define Inf 400009
using namespace std;
int n,l,r,a,b,c,k,kk,ans,x[Inf],y[Inf],z[Inf];
int main(){
	freopen("debate.in","r",stdin);	freopen("debate.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){scanf("%d %d",&k,&kk);if(k==11){ans+=kk;l++;r++;}else if(k==10) x[++a]=kk;else if(k==1) y[++b]=kk;else if(!k) z[++c]=kk;}
	k=kk=l;sort(x+1,x+1+a);sort(y+1,y+1+b);sort(z+1,z+1+c);
	while(a&&b){ans+=x[a]+y[b];a--;b--;k++;kk++;l+=2;r+=2;}
	while(a){if(kk<=r/2)break;if(c&&k>l/2){if(x[a]>=z[c]){ans+=x[a];a--;l++;r++;k++;}else{ans+=z[c];c--;l++;r++;}}else{ans+=x[a];a--;l++;r++;k++;}}
	while(b){if(k<=l/2)break;if(c&&kk>r/2){if(y[b]>=z[c]){ans+=y[b];b--;l++;r++;kk++;}else{ans+=z[c];c--;l++;r++;}}else{ans+=y[b];b--;l++;r++;kk++;}}
	while(c){if(k<=l/2||kk<=r/2)break;else{ans+=z[c];c--;l++;r++;}}
	printf("%d",ans);return 0;
}
