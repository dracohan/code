package self;
/**
 * @project: ThinkingInJava
 * @filename: ConstructorTest.java
 * @version: 0.10
 * @author: Jimmy Han
 * @date: 3:51 PM 9/25/15
 * @comment: Test Purpose
 * @result:
 */


class Constructor {
    class inner{
        inner(){
            System.out.println("inner constructor");
        }
    }


    Constructor(){
        System.out.println("Constructor constructor");
    }
    private inner i = new inner();
}

class ConstructorTest{
    public static void main(String[] args) {
        Constructor c = new Constructor();
    }
}
