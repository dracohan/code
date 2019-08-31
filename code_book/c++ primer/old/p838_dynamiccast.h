///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   page_content.h
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/07/26 16:50:14
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////
#ifndef PAGE_CONTENT_H
#define	PAGE_CONTENT_H
class employee {
	public:
	virtual int salary();
};
	
class manager : public employee {
	public:
	int salary();
};

class programmer : public employee {
	public:
	int salary();
	void bonus();
};




#endif