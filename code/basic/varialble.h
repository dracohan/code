///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   varialble.h
//  Version     :   0.10	created	2013/07/25 10:27:45		
//  Author      :   Jimmy Han
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