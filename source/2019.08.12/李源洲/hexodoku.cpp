#include <fstream>
#include <vector>
using namespace std;

ifstream cin("hexodoku.in");
ofstream cout("hexodoku.out");

vector<int> force[32]; int canbe[32][32]; int state[32]; int answers, targ, K;
void initforce() {

force[1].push_back(2);
force[1].push_back(4);
force[1].push_back(5);
force[1].push_back(6);
force[1].push_back(9);
force[1].push_back(10);
force[1].push_back(11);
force[1].push_back(14);
force[1].push_back(17);
force[1].push_back(19);
force[1].push_back(23);
force[1].push_back(29);

force[2].push_back(1);
force[2].push_back(4);
force[2].push_back(5);
force[2].push_back(6);
force[2].push_back(10);
force[2].push_back(11);
force[2].push_back(12);
force[2].push_back(15);
force[2].push_back(18);
force[2].push_back(20);
force[2].push_back(24);
force[2].push_back(25);

force[3].push_back(4);
force[3].push_back(5);
force[3].push_back(6);
force[3].push_back(7);
force[3].push_back(8);
force[3].push_back(9);
force[3].push_back(10);
force[3].push_back(14);
force[3].push_back(15);
force[3].push_back(21);
force[3].push_back(27);
force[3].push_back(31);

force[4].push_back(1);
force[4].push_back(2);
force[4].push_back(3);
force[4].push_back(5);
force[4].push_back(6);
force[4].push_back(7);
force[4].push_back(8);
force[4].push_back(9);
force[4].push_back(10);
force[4].push_back(11);
force[4].push_back(14);
force[4].push_back(15);
force[4].push_back(16);
force[4].push_back(19);
force[4].push_back(22);
force[4].push_back(28);

force[5].push_back(1);
force[5].push_back(2);
force[5].push_back(3);
force[5].push_back(4);
force[5].push_back(6);
force[5].push_back(7);
force[5].push_back(10);
force[5].push_back(11);
force[5].push_back(15);
force[5].push_back(17);
force[5].push_back(20);
force[5].push_back(23);
force[5].push_back(25);
force[5].push_back(29);

force[6].push_back(1);
force[6].push_back(2);
force[6].push_back(3);
force[6].push_back(4);
force[6].push_back(5);
force[6].push_back(7);
force[6].push_back(10);
force[6].push_back(11);
force[6].push_back(12);
force[6].push_back(13);
force[6].push_back(16);
force[6].push_back(17);
force[6].push_back(18);
force[6].push_back(21);
force[6].push_back(24);
force[6].push_back(26);

force[7].push_back(3);
force[7].push_back(4);
force[7].push_back(5);
force[7].push_back(6);
force[7].push_back(11);
force[7].push_back(12);
force[7].push_back(13);
force[7].push_back(17);
force[7].push_back(18);
force[7].push_back(22);
force[7].push_back(27);
force[7].push_back(30);

force[8].push_back(3);
force[8].push_back(4);
force[8].push_back(9);
force[8].push_back(10);
force[8].push_back(11);
force[8].push_back(12);
force[8].push_back(13);
force[8].push_back(14);
force[8].push_back(15);
force[8].push_back(20);
force[8].push_back(21);
force[8].push_back(26);
force[8].push_back(27);
force[8].push_back(30);
force[8].push_back(31);

force[9].push_back(1);
force[9].push_back(3);
force[9].push_back(4);
force[9].push_back(8);
force[9].push_back(10);
force[9].push_back(11);
force[9].push_back(12);
force[9].push_back(13);
force[9].push_back(14);
force[9].push_back(15);
force[9].push_back(19);

force[10].push_back(1);
force[10].push_back(2);
force[10].push_back(3);
force[10].push_back(4);
force[10].push_back(5);
force[10].push_back(6);
force[10].push_back(8);
force[10].push_back(9);
force[10].push_back(11);
force[10].push_back(12);
force[10].push_back(13);
force[10].push_back(14);
force[10].push_back(15);
force[10].push_back(16);
force[10].push_back(17);
force[10].push_back(20);
force[10].push_back(21);
force[10].push_back(22);
force[10].push_back(25);
force[10].push_back(28);

force[11].push_back(1);
force[11].push_back(2);
force[11].push_back(4);
force[11].push_back(5);
force[11].push_back(6);
force[11].push_back(7);
force[11].push_back(8);
force[11].push_back(9);
force[11].push_back(10);
force[11].push_back(12);
force[11].push_back(13);
force[11].push_back(15);
force[11].push_back(16);
force[11].push_back(17);
force[11].push_back(18);
force[11].push_back(21);
force[11].push_back(22);
force[11].push_back(23);
force[11].push_back(26);
force[11].push_back(29);

force[12].push_back(2);
force[12].push_back(6);
force[12].push_back(7);
force[12].push_back(8);
force[12].push_back(9);
force[12].push_back(10);
force[12].push_back(11);
force[12].push_back(13);
force[12].push_back(17);
force[12].push_back(18);
force[12].push_back(22);
force[12].push_back(24);
force[12].push_back(27);
force[12].push_back(30);

force[13].push_back(6);
force[13].push_back(7);
force[13].push_back(8);
force[13].push_back(9);
force[13].push_back(10);
force[13].push_back(11);
force[13].push_back(12);
force[13].push_back(17);
force[13].push_back(18);
force[13].push_back(23);
force[13].push_back(28);
force[13].push_back(31);

force[14].push_back(1);
force[14].push_back(3);
force[14].push_back(4);
force[14].push_back(8);
force[14].push_back(9);
force[14].push_back(10);
force[14].push_back(15);
force[14].push_back(16);
force[14].push_back(17);
force[14].push_back(18);
force[14].push_back(19);
force[14].push_back(20);
force[14].push_back(21);
force[14].push_back(25);
force[14].push_back(26);
force[14].push_back(30);

force[15].push_back(2);
force[15].push_back(3);
force[15].push_back(4);
force[15].push_back(5);
force[15].push_back(8);
force[15].push_back(9);
force[15].push_back(10);
force[15].push_back(11);
force[15].push_back(14);
force[15].push_back(16);
force[15].push_back(17);
force[15].push_back(18);
force[15].push_back(19);
force[15].push_back(20);
force[15].push_back(21);
force[15].push_back(22);
force[15].push_back(25);
force[15].push_back(26);
force[15].push_back(27);
force[15].push_back(31);

force[16].push_back(4);
force[16].push_back(6);
force[16].push_back(10);
force[16].push_back(11);
force[16].push_back(14);
force[16].push_back(15);
force[16].push_back(17);
force[16].push_back(18);
force[16].push_back(21);
force[16].push_back(22);
force[16].push_back(26);
force[16].push_back(28);

force[17].push_back(1);
force[17].push_back(5);
force[17].push_back(6);
force[17].push_back(7);
force[17].push_back(10);
force[17].push_back(11);
force[17].push_back(12);
force[17].push_back(13);
force[17].push_back(14);
force[17].push_back(15);
force[17].push_back(16);
force[17].push_back(18);
force[17].push_back(21);
force[17].push_back(22);
force[17].push_back(23);
force[17].push_back(24);
force[17].push_back(27);
force[17].push_back(28);
force[17].push_back(29);
force[17].push_back(30);

force[18].push_back(2);
force[18].push_back(6);
force[18].push_back(7);
force[18].push_back(11);
force[18].push_back(12);
force[18].push_back(13);
force[18].push_back(14);
force[18].push_back(15);
force[18].push_back(16);
force[18].push_back(17);
force[18].push_back(22);
force[18].push_back(23);
force[18].push_back(24);
force[18].push_back(28);
force[18].push_back(29);
force[18].push_back(31);

force[19].push_back(1);
force[19].push_back(4);
force[19].push_back(9);
force[19].push_back(14);
force[19].push_back(15);
force[19].push_back(20);
force[19].push_back(21);
force[19].push_back(22);
force[19].push_back(23);
force[19].push_back(24);
force[19].push_back(25);
force[19].push_back(26);

force[20].push_back(2);
force[20].push_back(5);
force[20].push_back(8);
force[20].push_back(10);
force[20].push_back(14);
force[20].push_back(15);
force[20].push_back(19);
force[20].push_back(21);
force[20].push_back(22);
force[20].push_back(23);
force[20].push_back(24);
force[20].push_back(25);
force[20].push_back(26);
force[20].push_back(30);

force[21].push_back(3);
force[21].push_back(6);
force[21].push_back(8);
force[21].push_back(10);
force[21].push_back(11);
force[21].push_back(14);
force[21].push_back(15);
force[21].push_back(16);
force[21].push_back(17);
force[21].push_back(19);
force[21].push_back(20);
force[21].push_back(22);
force[21].push_back(23);
force[21].push_back(24);
force[21].push_back(25);
force[21].push_back(26);
force[21].push_back(27);
force[21].push_back(28);
force[21].push_back(30);
force[21].push_back(31);

force[22].push_back(4);
force[22].push_back(7);
force[22].push_back(10);
force[22].push_back(11);
force[22].push_back(12);
force[22].push_back(15);
force[22].push_back(16);
force[22].push_back(17);
force[22].push_back(18);
force[22].push_back(19);
force[22].push_back(20);
force[22].push_back(21);
force[22].push_back(23);
force[22].push_back(24);
force[22].push_back(26);
force[22].push_back(27);
force[22].push_back(28);
force[22].push_back(29);
force[22].push_back(30);
force[22].push_back(31);

force[23].push_back(1);
force[23].push_back(5);
force[23].push_back(11);
force[23].push_back(13);
force[23].push_back(17);
force[23].push_back(18);
force[23].push_back(19);
force[23].push_back(20);
force[23].push_back(21);
force[23].push_back(22);
force[23].push_back(24);
force[23].push_back(28);
force[23].push_back(29);
force[23].push_back(31);

force[24].push_back(2);
force[24].push_back(6);
force[24].push_back(12);
force[24].push_back(17);
force[24].push_back(18);
force[24].push_back(19);
force[24].push_back(20);
force[24].push_back(21);
force[24].push_back(22);
force[24].push_back(23);
force[24].push_back(28);
force[24].push_back(29);

force[25].push_back(2);
force[25].push_back(5);
force[25].push_back(10);
force[25].push_back(14);
force[25].push_back(15);
force[25].push_back(19);
force[25].push_back(20);
force[25].push_back(21);
force[25].push_back(26);
force[25].push_back(27);
force[25].push_back(28);
force[25].push_back(29);

force[26].push_back(6);
force[26].push_back(8);
force[26].push_back(11);
force[26].push_back(14);
force[26].push_back(15);
force[26].push_back(16);
force[26].push_back(19);
force[26].push_back(20);
force[26].push_back(21);
force[26].push_back(22);
force[26].push_back(25);
force[26].push_back(27);
force[26].push_back(28);
force[26].push_back(29);
force[26].push_back(30);
force[26].push_back(31);

force[27].push_back(3);
force[27].push_back(7);
force[27].push_back(8);
force[27].push_back(12);
force[27].push_back(15);
force[27].push_back(17);
force[27].push_back(21);
force[27].push_back(22);
force[27].push_back(25);
force[27].push_back(26);
force[27].push_back(28);
force[27].push_back(29);
force[27].push_back(30);
force[27].push_back(31);

force[28].push_back(4);
force[28].push_back(10);
force[28].push_back(13);
force[28].push_back(16);
force[28].push_back(17);
force[28].push_back(18);
force[28].push_back(21);
force[28].push_back(22);
force[28].push_back(23);
force[28].push_back(24);
force[28].push_back(25);
force[28].push_back(26);
force[28].push_back(27);
force[28].push_back(29);
force[28].push_back(30);
force[28].push_back(31);

force[29].push_back(1);
force[29].push_back(5);
force[29].push_back(11);
force[29].push_back(17);
force[29].push_back(18);
force[29].push_back(22);
force[29].push_back(23);
force[29].push_back(24);
force[29].push_back(25);
force[29].push_back(26);
force[29].push_back(27);
force[29].push_back(28);

force[30].push_back(7);
force[30].push_back(8);
force[30].push_back(12);
force[30].push_back(14);
force[30].push_back(17);
force[30].push_back(20);
force[30].push_back(21);
force[30].push_back(22);
force[30].push_back(26);
force[30].push_back(27);
force[30].push_back(28);
force[30].push_back(31);

force[31].push_back(3);
force[31].push_back(8);
force[31].push_back(13);
force[31].push_back(15);
force[31].push_back(18);
force[31].push_back(21);
force[31].push_back(22);
force[31].push_back(23);
force[31].push_back(26);
force[31].push_back(27);
force[31].push_back(28);
force[31].push_back(30);

}
void set(int loc, int v) {
	state[loc] = v;
	for(int i=0; i<force[loc].size(); i++) {
		canbe[force[loc][i]][v]++;
	}
}
void unset(int loc) {
	int v = state[loc];
	state[loc] = 0; 
	for(int i=0; i<force[loc].size(); i++) {
		canbe[force[loc][i]][v]--;
}
}
void dfs(int loc) {
	if(answers == targ) return;
	if(loc == 32) { answers++; return; }
	if(state[loc] != 0) { dfs(loc+1); return; }
	for(int nstate=1; nstate<=K; nstate++) if(canbe[loc][nstate] == 0) {
		if(answers == targ) return;
		set(loc, nstate); dfs(loc+1); 
		if(answers != targ) unset(loc);
	}
}

int main(){
	initforce();
	cin >> K >> targ;
	bool noway = false;
	for(int i=1; i<=31; i++)
		for(int j=1; j<=K; j++) canbe[i][j] = 0;
	for(int i=1; i<=31; i++) {
		cin >> state[i];
		if(state[i] != 0 && (canbe[i][state[i]] != 0)) noway = true;
		if(state[i] != 0) set(i, state[i]);
	}
	if((K == 7 && targ > 5040) || noway) {
		cout << "No way" << endl;
		return 0;
	}
	if(K == 7 && targ > 4320) {
		if(state[1] != 0 && state[1] != 7) {
			cout << "No way" << endl;
			return 0;
		}
		if(state[1] == 0) {
			state[1] = 7;
			targ -= 4320;
		}
	}
	dfs(1);
	if(answers != targ) cout << "No way" << endl; 
	else {
		cout << "Found" << endl;
		for(int i=1; i<=31; i++) {
			if(i != 1) cout << ' ';
			cout << state[i];
		}
	}
}
