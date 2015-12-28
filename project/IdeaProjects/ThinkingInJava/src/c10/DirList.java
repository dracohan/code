package c10;

/**
 * Created by bwhan on 5/5/15.
 */
//: DirList.java
// Displays directory listing
import java.io.*;
public class DirList {
    public static void main(String[] args) {
        try {
            File path = new File(".");
            String[] list;
            System.out.println("args[0]="+args[0]);
            if(args.length == 0)
                list = path.list();
            else
                list = path.list((java.io.FilenameFilter) new DirFilter(args[0]));
            for(int i = 0; i < list.length; i++)
                System.out.println(list[i]);
            //createJavaThread("fubar", quickTest, (void*) "hello");
        } catch(Exception e) {
            e.printStackTrace();
        }
    }
    private native void test();
}



class DirFilter implements FilenameFilter {
    String afn;
    DirFilter(String afn) { this.afn = afn; }
    public boolean accept(File dir, String name) {
// Strip path information:
        String f = new File(name).getName();
        return f.indexOf(afn) != -1;
    }
} ///:~
