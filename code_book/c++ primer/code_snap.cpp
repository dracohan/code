template < class elemType >
class Array {
public:
	//public code
	//...
	explicit Array( int sz ); 
	Array( elemType *array, int sz );
	Array( Array &rhs );

	virtual ~Array( ) { delete [] _ia; }

	bool operator==( const Array &rhs ) const;
	bool operator!=( const Array &rhs ) const;

private:
	//private code
	//blablabla
	int _size;
	elemType _ia;

};

const int array_size;
Array<int> ia(array_size);
Array<double> da(array_size);
Array<char> ca(array_size);

for ( int ix = 0; ix < array_size; ++ix)
	ia[ix] = ix;
	da[ix] = ix*1.75;
	ca[ix] = ix + 'a';
}

namespace IBM_canada_laboratory {
    template <class elemType>
        class Array {
            public:
            private:
        };
    }

namespace LIB = IBM_canada_labotory

int main()
{
    LIB::Array<int> ia(1024);
    //...
    //
}

const int size = 8
const int value = 1024
vector<int> vec
vector<int> vec( size )
vector<int> vec( size, value )

int ia[] = { 1, 2, 13, 4}
vector<int> vec( ia, ia+4 );
vector<int> vec2( vec );

int size = getSize();
vector< int > vec( size );
for ( int ix = 0; ix < size; ++ix )
    vec[ ix ] = ix;

vector<int>::interator iter = vec.begin();

for ( int ix = 0; iter != vec.end(); ix++, iter++ )
    *iter = ix;

sort( ivec.begin(), ivec.end() );
sort( ivec.begin(), ivec.begin()+ivec.size()/2 );

#include <string>

string st( "The expense of spirit\n" );
st.size();
st.empty();
string st3(st);
replace( str.begin(), str.end(), '.', '_');

int ival = 1024;
int &refval = ival;

const int &ival = 1024;

enum open_modes{ input = 1, outpu, append }

template <class elemType>
void print( elemType *pbegin, elemType *pend ) {
    while ( pbegin != pend ) {
        cout << *pbegin << " "; 
        pbegin++;
    }
}


ivec.push_back( ia[ix] );

typedef double wages;
typedef vector<int> vec_int;

typedef char *cstring;
const cstring cstr;

char *const cstr;

volatile int display_register;


#include <utility>
pair <string, string> author( "James", "Joyce" );




