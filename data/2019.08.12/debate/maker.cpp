# include <bits/stdc++.h>
using namespace std; 
namespace Base{
	# define mr make_pair
	typedef long long ll;
	typedef double db;
	const int inf = 0x3f3f3f3f, INF = 0x7fffffff;
	const ll  infll = 0x3f3f3f3f3f3f3f3fll, INFll = 0x7fffffffffffffffll;
	template<typename T> void read(T &x){
    	x = 0; int fh = 1; double num = 1.0; char ch = getchar();
		while (!isdigit(ch)){ if (ch == '-') fh = -1; ch = getchar(); }
		while (isdigit(ch)){ x = x * 10 + ch - '0'; ch = getchar(); }
	    if (ch == '.'){
	    	ch = getchar();
	    	while (isdigit(ch)){num /= 10; x = x + num * (ch - '0'); ch = getchar();}
		}
		x = x * fh;
	}
	template<typename T> void chmax(T &x, T y){x = x < y ? y : x;}
	template<typename T> void chmin(T &x, T y){x = x > y ? y : x;}
}
using namespace Base;

void maker();
int worker();
void cleaner();

namespace Make{
	char prob[101]; int op; 
	void addid(char *s, int id){
		if (id == 0){s[0] = 0; return;}
		int tmp = 0;
		while (id > 0) s[tmp++] = id % 10 + '0', id /= 10;
		for (int i = 0, j = tmp - 1; i < j; i++, j--) std :: swap(s[i], s[j]);
		s[tmp] = 0;
	}
	void addout(char *s){s[0] = '.'; s[1] = 'o'; s[2] = 'u'; s[3] = 't'; s[4] = 0;}
	void addin(char *s){s[0] = '.'; s[1] = 'i'; s[2] = 'n'; s[3] = 0;}
	void prints(char *s){
		int tmp = strlen(s);
		for (int i = 0; i < tmp; i++) std :: cerr << s[i];
		std :: cerr << '\n';
	}
	int random(int l, int r){
		int size = r - l + 1;
		return l + abs(((rand() << 16) + rand())) % size;
	}
	void runMake(){
		scanf("\n%s", prob);
		int l, r, len = strlen(prob);
		read(l), read(r); 
		for (op = l; op <= r; op++){
			addid(prob + len, op); 
			addin(prob + strlen(prob));
			prints(prob);
			freopen(prob, "w", stdout);
			maker();
			fclose(stdout);
			freopen(prob, "r", stdin);
			addout(prob + strlen(prob) - 3);
			freopen(prob, "w", stdout);
			int tmp = worker();
			if (tmp != 0) cerr << "Error" << "\n";
				else cerr << "Success" << "\n";
			fclose(stdin);
			fclose(stdout);
			cleaner();
			freopen("CON", "r", stdin);
			freopen("CON", "w", stdout);
		}
	}
}

int main(){
	Make :: runMake();
	return 0;
}

void maker(){
	srand((int)time(0) + Make :: op);
	int n, op;
	read(n); read(op);
	printf("%d\n", n);
	int tmp = Make :: random(1, 5000), now;
	for (int i = 1; i <= n; i++){
		if (op == 2){
			int o = Make :: random(1, 2);
			if (o == 1) now = 0; else now = 3;
		}
		else now = Make :: random(0, 3);
		printf("%d%d ", now / 2 % 2, now % 2);
		if (op == 1)
			printf("%d\n", tmp);
			else printf("%d\n", Make :: random(1, 5000));
	}
}

const int N = 1000010;
int n, val[4][N], num[4], ans;
bool cmp(int x, int y){
	return x > y;
}
int worker(){
	read(n); ans = 0;
	memset(num, 0, sizeof(num));
	for (int i = 1; i <= n; i++){
		int x, v, c;
		read(x); read(v);
		if (x == 11) c = 0;
		if (x == 10) c = 1;
		if (x == 01) c = 2;
		if (x == 00) c = 3;
		val[c][++num[c]] = v;
	}
	sort(val[1] + 1, val[1] + num[1] + 1, cmp);
	sort(val[2] + 1, val[2] + num[2] + 1, cmp);
	int mn = min(num[1], num[2]);
	for (int i = 1; i <= mn; i++)
		ans = ans + val[1][i] + val[2][i];
	for (int i = mn + 1; i <= num[1]; i++) val[3][++num[3]] = val[1][i];
	for (int i = mn + 1; i <= num[2]; i++) val[3][++num[3]] = val[2][i];
	sort(val[3] + 1, val[3] + num[3] + 1, cmp);
	for (int i = 1; i <= num[0]; i++) 
		ans = ans + val[0][i] + val[3][i];
	printf("%d\n", ans);
	return 0;
}


void cleaner(){
	
}
