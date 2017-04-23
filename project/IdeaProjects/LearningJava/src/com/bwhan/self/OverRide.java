package self;

/**
 * @project: LearningJava
 * @filename: OverRide.java
 * @version: 0.10
 * @author: Han Powell
 * @date: 22:14 2015/8/23
 * @comment: Test Purpose
 * @result:
 */
class Father {
	public void f(){
		System.out.println("father's f()");
	}
}

public class OverRide extends Father{
	public void f(){
		System.out.println("son's public override");
	}
	public static void main(String[] arg){
		Father fa = new OverRide();
		fa.f();
	}
}