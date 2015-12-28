///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   inherite.h
//  Version     :   0.10	created	2013/07/24 09:43:03		
//  Author      :   Jimmy Han
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////
#ifndef __H__
#define __H__

class Base {
	public: 
		Base();
		~Base();
		int public_val;
		void public_func();
		virtual void public_virtual_func();
	
		//non-virtual function call public_virtual_func()
		void public_virtual_func_caller();

		//nested class 
		class inherite
		{
		protected:
			/* data */
			int* pi;
			void retrieve(){;}
		};
		class deriveeeed : public inherite
		{
		public:
			/* data */
			void retrieve_caller()
			{
				pi = 0;
				retrieve();
			}
		};

	protected: 
		int protected_val;
		void protected_func();
		virtual void protected_virtual_func();
	
	private: 
		int private_val;
		void private_func();
		virtual void private_virtual_func();
};

class Derived : public Base {
	public:
		//illegal overwritten base::public_func()
		void public_func();
		
		//normal overwritten base::public_virtual_func()
		virtual void public_virtual_func();

		//public funtion call base::public_func() and base::protected_func()
		void public_func_caller();

	private:
		//overwritten base::private_virtual_func()
		virtual void private_virtual_func();
};


//private继承
class Derived2 : private Derived {
	public:
	
};
		
//private继承
class Derived3 : private Base {
	public:
		void public_virtual_func();
};

#endif