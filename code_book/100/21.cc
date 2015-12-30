// 21.cc
#include <iostream>
#include <cstring>
using namespace std;

void print(int* aux, int n) {
	for (int i = 1; i <= n; i++)
		if (aux[i])
			cout << i << " ";
	cout << endl;
}

void helper(int m, int cur, int* aux, int n) {
	if (m == 0){
		cout << "Got one: " << endl;
		print(aux, n);
		//if equal, no need to calculate further recurse
		//cause, further add will make it unequal
		return;
	}
	// m<0 for select, but sum too big
	//cur > n for selection out of range
	if (m < 0 || cur >  n){
		//cout << "calulate: " << endl;
		//for (int i = 1; i <= n; i++)
		//	cout << aux[i] << " ";
		//cout << endl;
		return;
	}

	// unselect cur
	helper(m, cur + 1, aux, n);

	// select cur
	aux[cur] = 1;
	helper(m - cur, cur + 1, aux, n);
	aux[cur] = 0;  // backout 
}

void find_combi(int n, int m) {
	if (n > m) 
		find_combi(m, m);
	else {
		int* aux = new int[n];  // aux[i] = 1 represent selected
		memset(aux, 0, n * sizeof(int));
		helper(m, 1, aux, n);
	}
}

int main() {
	int n, m;
	cout << "input n and m:" << endl;
	cin >> n >> m;
	find_combi(n, m);
	return 0;
}
