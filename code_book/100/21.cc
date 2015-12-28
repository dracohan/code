// 21.cc
#include <iostream>
#include <cstring>
using namespace std;

void print(int* aux, int n) {
	for (int i = 0; i < n; i++)
		if (aux[i])
			cout << i << " ";
	cout << endl;
}

void helper(int m, int cur, int* aux, int n) {
	if (m == 0)
		print(aux, n);
	if (m <= 0 || cur == n)
		return;

	// 不选cur
	helper(m, cur + 1, aux, n);

	// 选cur
	aux[cur] = 1;
	helper(m - cur, cur + 1, aux, n);
	aux[cur] = 0;  // 回溯
}

void find_combi(int n, int m) {
	if (n > m) 
		find_combi(m, m);

	int* aux = new int[n];  // aux[i] = 1，表示选择i
	memset(aux, 0, n * sizeof(int));
	helper(m, 0, aux, n);
}

int main() {
	int n, m;
	cout << "input n and m:" << endl;
	cin >> n >> m;
	find_combi(n, m);
	return 0;
}