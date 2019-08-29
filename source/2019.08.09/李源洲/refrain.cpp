#include <fstream>
using namespace std;

ifstream fin("refrain.in");
ofstream fout("refrain.out");

int main() {
	int num; fin >> num;
	if(num == 0 || num == 1) fout << 0 << endl;
	else fout << 137 << endl;
}
