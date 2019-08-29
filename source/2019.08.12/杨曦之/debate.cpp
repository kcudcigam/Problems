#include<bits/stdc++.h>
using namespace std;
struct node{
	int val,pos;
}a[400000+10];
int n,num1;
bool operator <(node x,node y){
	return x.val<y.val;
}
priority_queue<node> q0x,q10,q01;
int main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	int i,j,ans=0,op;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&op,&a[i].val);
		a[i].pos=i;
		if(op==0) q0x.push(a[i]);
		if(op==1) q01.push(a[i]);
		if(op==10) q10.push(a[i]);
		if(op==11) num1++,ans+=a[i].val;
	}
	node tmp;
	while(!q01.empty()&&!q10.empty()){
		tmp=q01.top();q01.pop();
		ans+=tmp.val;
		tmp=q10.top();q10.pop();
		ans+=tmp.val;
	}
	while(!q01.empty()){
		tmp=q01.top();q01.pop();
		q0x.push(tmp);
	}
	while(!q10.empty()){
		tmp=q10.top();q10.pop();
		q0x.push(tmp);
	}
	while(num1--&&(!q0x.empty())){
		tmp=q0x.top();q0x.pop();
		ans+=tmp.val;
	}
	printf("%d\n",ans);
	return 0;
}

