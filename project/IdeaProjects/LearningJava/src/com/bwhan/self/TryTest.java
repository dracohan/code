package self;

import java.io.FileWriter;
import java.io.IOException;
import java.net.Socket;

/**
 * Created by Jimmy on 2015/5/24.
 */
public class TryTest {
    public static void main(String[] args) {
        int i;
        try {
            i = 14;
        } catch (Exception e) {
            System.out.println("shit");
        }
        //int j = i;
        //System.out.println("j: " + i);

/*        try(
                Socket soc = new Socket("127.0.0.1", 80);
                FileWriter file = new FileWriter("foo");
                )
        {

        } catch (IOException e) {

        }*/
    }
}

