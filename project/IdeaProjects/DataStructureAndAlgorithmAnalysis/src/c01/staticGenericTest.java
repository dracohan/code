package c01;

/**
 * @project: DataStructureAndAlgorithmAnalysis
 * @filename: staticGenericTest.java
 * @version: 0.10
 * @author: Powell
 * @date: 13:02 2015/9/29
 * @comment: Test Purpose
 * @result:
 */

class genericClass<Anytype>{
	private Anytype storeValue;
	//no static in generic class
	//static Anytype staticStoreValue;

}

class B{

}
public class staticGenericTest {
	public static void main(String[] args) {
		genericClass<String>[] garr = new genericClass[10];
		garr[0] = new genericClass<String>();
	}
}
