#include <iostream>

using namespace std;

class B {
    public:
        B(int initVal = 0, string initStr = "") : _ix(initVal),  _text(initStr) {}
        const char& operator[](int pos) const {
        	cout << "const operator[] was called" << endl;
        	return _text[pos];
        	}
        /*
        // this could be omitted
                char& operator[](int pos) {
        	cout << "operator[] was called" << endl;
        	return _text[pos];
        	}

        void show() {
        	cout << "show() was called" << endl;
            cout << _ix << endl;
        }
		*/
		
        void show() const {
        	cout << "const show() was called" << endl;
            cout << _ix << endl;
        }
        
    private:
        int _ix;
        string _text;
};
