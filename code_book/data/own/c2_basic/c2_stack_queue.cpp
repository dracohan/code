#include "c2_stack_queue.h"
#include <iostream>
using namespace std;

int main(){
	Stack<int> s;
	Queue<int> q;


	for(int i = 0; i < 20; i++)
	{
		s.push(i);
		q.enqueue(i);
	}

	while(!s.isEmpty())
	{
		cout << s.pop() << " ";
	}

	cout << endl;
	
	while(!q.isEmpty())
	{
		cout << q.dequeue() << " ";
	}


	return 0;
}