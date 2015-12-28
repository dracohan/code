package c01;


/**
 * @project: ${PROJECT_NAME}
 * @filename: ${NAME}.java
 * @version: 0.10
 * @author: Jimmy Han
 * @date: 22:54 2015/6/21
 * @comment: Test Purpose
 * @result:
 */

class Person{

}

class Employee extends Person{

}

class Student extends Person{

}

public class CovariantTest {
    public static void main(String[] args){
        Person[] arr = new Employee[5];
        //Runtime error
        arr[0] = new Student();
        //arr[0] = new Employee();
/*        arr[1] = new Employee();
        arr[2] = new Employee();
        arr[3] = new Employee();
        arr[4] = new Employee();
        for(Person p:arr){
            System.out.println(p);
        }*/
    }
}
