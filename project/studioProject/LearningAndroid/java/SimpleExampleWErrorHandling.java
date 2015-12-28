package com.bwhan.examples;
/*
A simple example class with a basic main method
that instantiates several objects of the class,
manipulates the objects, and outputs information
about the object
*/
public class SimpleExampleWErrorHandling {
	private int number;
	public SimpleExampleWErrorHandling() { }
	//------- ERROR HANDLING PART 1
	public void setValueWithException(int val) throws Exception {
		if(val < 0) throw new Exception(
			"setValue Exception- Value that is set is Negative!");
		number = val;
	}
	public int getNumber() {
		return number;
	}
	
	// here we override toString so the set value
	// is returned rather than the object's textual
	// representation
	// @Override
	// public String toString() {
	// 	//return number;
	// }
	
	public static void main(String[] args) {
		for(int i=0;i<10;i++) {
			SimpleExampleWErrorHandling example = new SimpleExampleWErrorHandling();
			if(i/2 <= 2) {
				//------- ERROR HANDLING PART 4
				try { example.setValueWithException(i); }
				catch (Exception e) { e.printStackTrace(); }
			} else {
				//------- ERROR HANDLING PART 4
				try { example.setValueWithException(i*10); }
				catch (Exception e) { e.printStackTrace(); }
			}
			System.out.println("SimpleExampleWErrorHandling #"+i+
								"'s value is "+example.getNumber());
		}
		showErrorHandling(); //------- ERROR HANDLING PART 2
	}
	//------- ERROR HANDLING PART 3
	public static void showErrorHandling() {
		// here we show Error Handling
		try {
			System.out.println();
			System.out.println("SimpleExampleWErrorHandling BadValue Insert Case Start");
			SimpleExampleWErrorHandling example = new SimpleExampleWErrorHandling();
			example.setValueWithException(-10);
			System.out.println("SimpleExampleWErrorHandling BadValue's value is "+
			example.getNumber());
			System.out.println("SimpleExampleWErrorHandling BadValue Insert Case End");
		} catch (Exception e) {
			System.err.println("SimpleExampleWErrorHandling BadValue "+
			"Insert Case threw an exception");
			e.printStackTrace();
		} finally {
			System.out.println("SimpleExampleWErrorHandling BadValue "+
			"Insert Case Finally Called");
		}
	}
}