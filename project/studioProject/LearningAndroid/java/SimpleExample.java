package com.bwhan.examples;
/*
A simple example class with a basic main method
that instantiates several objects of the class,
manipulates the objects, and outputs information
about the object
*/
public class SimpleExample {
	private int number;
	double[] someArray;
	String[] anotherArray = {"some string", "a", "string"};
	public SimpleExample() { someArray = new double[4];}
	public void setValue(int val) {
		number = val;
	}
	public int getNumber() {
		System.out.println("anotherArray: " + anotherArray);
		return number;
	}
	public static void main(String[] args) {
		for(int i=0;i<10;i++) {
			SimpleExample example = new SimpleExample();
			if(i/2 <= 2) {
			example.setValue(i);
		} else {
			example.setValue(i*10);
		}
		System.out.println("SimpleExample #"+i+
							"'s value is "+example.getNumber());
		}
	}
}