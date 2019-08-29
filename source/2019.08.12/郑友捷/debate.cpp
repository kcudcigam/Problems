#include<cstdio>
#include<algorithm>
using namespace std;
int n;
bool inv[400010][3];
int a[400010],cnt1,cnt2,cnt,cnt3;
int len1[400010],len2[400010],len[400010];
int ans;
inline int pd(int x){
	if(x>=0) return x;
	else return -x;
}
inline bool comp(int x,int y){
	return x>y;
}
int main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	scanf("%d",&n);
	for(register int i=1;i<=n;i++){
		char ch[4];
		scanf("%s",ch);
		if(ch[0]=='0') inv[i][1]=false;
		else if(ch[0]=='1') inv[i][1]=true;
		if(ch[1]=='0') inv[i][2]=false;
		else if(ch[1]=='1') inv[i][2]=true;
		scanf("%d",&a[i]);
	}
	for(register int i=1;i<=n;i++){
		if(inv[i][1]&&inv[i][2]){
			cnt++;
			ans+=a[i];
		}
		if(inv[i][1]&&!inv[i][2]){
			cnt1++;
			len1[cnt1]=a[i];
		}
		if(inv[i][2]&&!inv[i][1]){
			cnt2++;
			len2[cnt2]=a[i];
		}
		if(!inv[i][1]&&!inv[i][2]){
			len[++cnt3]=a[i];
		}
	}
	if(cnt1>cnt2){
		sort(len1+1,len1+cnt1+1,comp);
		for(register int i=1;i<=cnt2;i++){
			ans+=len1[i]+len2[i];
		}
		for(register int i=cnt2+1;i<=cnt1;i++){
			len[++cnt3]=len1[i];
		}
	}
	else {
		sort(len2+1,len2+cnt2+1,comp);
		for(register int i=1;i<=cnt1;i++){
			ans+=len1[i]+len2[i];
		}
		for(register int i=cnt1+1;i<=cnt2;i++){
			len[++cnt3]=len2[i];
		}
	}
	sort(len+1,len+cnt3+1,comp);
	for(register int i=1;i<=min(cnt,cnt3);i++){
		ans+=len[i];
	}
	printf("%d\n",ans);
}
