///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   deepinherite.h
//  Version     :   0.10	created	2013/12/02 00:00:00		
//  Author      :   Jimmy Han
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////
class B1{
public:
	void B1F1();
protected:
	void B1F2();
private:
	void B1F3();
};

class B2{
public:
	void B2F1();
protected:
	void B2F2();
private:
	void B2F3();
};

void
B1::B1F1(){
	cout << "B1F1" << endl;
}

void
B1::B1F2(){
	cout << "B1F2" << endl;
}

void
B1::B1F3(){
	cout << "B1F3" << endl;
}

void
B2::B2F1(){
	cout << "B1F1" << endl;
}

void
B2::B2F2(){
	cout << "B1F2" << endl;
}

void
B2::B2F3(){
	cout << "B1F3" << endl;
}

