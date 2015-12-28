/* div_array.cc
*  2014/09/03 create
*  写一个函数，返回数组中所有元素被第一个元素除的结果,包含第一个元素，也要自己除自己
*/
#include <iostream>
using namespace std;

void div_array(int* parray, int size) {
	//判断输入是否合法
	if(parray == NULL || size == 0)
		return;
	//判断除数是否为0
	if(parray[0] == 0)
		return;
	//从后往前除以第一个元素
	for(int i = size -1 ; i >= 0; i--)
		parray[i] /= parray[0];
}

int main() {
	int array[5] = {3, 12, 7, 5, 1} ;
	div_array(array, sizeof(array)/sizeof(array[0]));
	for(int i = 0; i < sizeof(array)/sizeof(array[0]); i++)
		cout << array[i] << " ";
	return 0;
}
