///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   use_private_inherit_judiciously_item39.h.h
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/07/23 16:52:30
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

class Rectangel : private Shape  {
	public:
	private:
};

#endif