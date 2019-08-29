#include <bits/stdc++.h>
using namespace std;

int x, y, xx[32], yy[32], t = 0, len1, len2, maxlen;

int main(){
	freopen("area.in", "r", stdin);
	freopen("area.out", "w", stdout);
	memset(xx, 0, sizeof(xx));
	memset(yy, 0, sizeof(yy));
	cin>>x>>y;
	x++, y++;
	while (x / 2){
		xx[t] = x % 2;
		x /= 2;
		t++;
	}
	xx[t] = x;
	len1 = t+1;
	t = 0;
	while (y / 2){
		yy[t] = y % 2;
		y /= 2;
		t++;
	}
	yy[t] = y;
	len2 = t+1;
	maxlen = max(len1, len2);
	if (len1 > len2){
		for (int i = len1 - len2; i <= maxlen;  i++){
			yy[i] = yy[i-(len1-len2)];
		}
		for (int i = 0; i < len1 - len2; i++){
			yy[i] = 0;
		}
	}
	if (len1 < len2){
		for (int i = len2 - len1; i <= maxlen; i++){
			xx[i] = xx[i-(len2-len1)];
		}
		for (int i = 0; i < len2 - len1; i++){
			xx[i] = 0;
		}
	}
	int bse = 1;
	for (int i = 0; i < maxlen; i++){
		if (xx[i] == 1 && yy[i] == 1) bse *= -1;
	}
	if (bse == 1) printf("infinity");
	else printf("%.0f", pow(2.0, (double)(maxlen-1)) + 1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
