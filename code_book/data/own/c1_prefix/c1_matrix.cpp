#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
using namespace std;

template <class object>
class matrix {
public:
	matrix(int rows, int cols) : arr(rows)
		{
			for(int i = 0; i < rows; i++)
				arr[row].resize(cols);
		}
		
	const vector<object>& operator[](int row) const
	{return arr[row];}		
	vector<object>& operator[](int row)
	{return arr[row];}

	int numrows() const
	{return arr.size();}
	int numcols() const
	{return numrows() ? arr[0].size() : 0; }
	
private:
	vector<vector<object> > arr;
};

#endif