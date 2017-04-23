package c08;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by Jimmy on 2015/6/22.
 */
class Person{

}

class GenericMemory<AnyType>{
    private AnyType store;
}

class Employee extends Person{

}

class Student extends Person{

}

public class Covariant {
    public static void main(String[] args){
        Person[] arr = new Employee[5];
        //Compile OK, Runtime NOK
        //arr[0] = new Student();
        arr[0] = new Employee();
        arr[1] = new Employee();
        arr[2] = new Employee();
        arr[3] = new Employee();
        arr[4] = new Employee();


        for(Person p:arr){
            System.out.println(p);
        }

        Object[] persons = new Person[10];
        //Compile OK, Runtime NOK
        //persons[0] = "aaa";

        //OK
        List<Person> arrp = new ArrayList<Person>();

        List lst = arrp;
        List<String> lsta = lst;
        //String s = lsta.get(0);


        //generic test
        GenericMemory<String> gm = new GenericMemory<String>();

    }
}

