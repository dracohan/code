package self;

/**
 * Created by Jimmy on 2015/5/17.
 */
public class arguments {
    public static void main(String[] args){
        int num = args.length;
        String str = System.getProperty("street");

        System.out.println("num is: " + num);
        System.out.println("args[0] is: " + args[0]);
        System.out.println("args[1] is: " + args[1]);
        System.out.println("street is: " + str);

    }
}
