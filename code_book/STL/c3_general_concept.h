///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   c3_general_concept.h
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2014/1/7 12:56:14
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////
#ifndef C3_GENERAL_CONCEPT_H
#define	C3_GENERAL_CONCEPT_H

class E1;
class E2;

void f() throw(E1)
{
	...
	throw E1(); //OK, throw exception of type E1
	throw E2(); //NOK, called unexpected()
}




#endif