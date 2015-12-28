///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   point_reference_item1.h
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/08/21 16:31:50
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