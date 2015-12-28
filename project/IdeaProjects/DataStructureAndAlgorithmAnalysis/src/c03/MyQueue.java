package c03;

/**
 * @project: DataStructureAndAlgorithmAnalysis
 * @filename: MyQueue.java
 * @version: 0.10
 * @author: Powell
 * @date: 22:03 2015/10/12
 * @comment: Test Purpose
 * @result:
 */
public class MyQueue<AnyType> {
	public AnyType front(){
		return mlist.get(0);
	}

	public void enqueue(AnyType x){
		mlist.add(x);
	}

	public AnyType dequeue(){
		AnyType res =  mlist.get(0);
		mlist.remove(0);
		return res;
	}

	public boolean isEmpty(){
		return mlist.isEmpty();
	}

	private MyArrayList<AnyType> mlist;

}
