package c01;

/**
 * Created by Jimmy on 2015/6/9.
 */
public class BadRecurseCall {
    public static int bad (int n){
        if(n == 0)
            return 0;
        else
            return bad(n/3 + 1) + n - 1;
    }

    public static void main(String[] args){
        int res = bad(4);
    }
}
