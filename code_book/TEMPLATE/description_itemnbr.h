///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   description_itemnbr.h
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/07/23 14:40:03
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////

#ifndef __H__
#define __H__

class Shape {
	public: 
		enum ShapeColor {RED, GREEN, BLUE};
		virtual void draw(ShapeColor color = RED) const;
};

class Rectangel : public Shape {
	public:
		virtual void draw(ShapeColor color = GREEN) const;
};

#endif