package c03;

/**
 * @project: DataStructureAndAlgorithmAnalysis
 * @filename: MyStack.java
 * @version: 0.10
 * @author: Powell
 * @date: 20:51 2015/10/12
 * @comment: Test Purpose
 * @result:
 */
public class MyStack<AnyType> {

	public AnyType top(){
		return mlist.get(mlist.size());
	}

	public void push(AnyType x){
		mlist.add(x);
	}

	public AnyType pop(){
		AnyType res =  mlist.get(mlist.size());
		mlist.remove(mlist.size());
		return res;
	}

	public boolean isEmpty(){
		return mlist.isEmpty();
	}

	private MyArrayList<AnyType> mlist;

}
