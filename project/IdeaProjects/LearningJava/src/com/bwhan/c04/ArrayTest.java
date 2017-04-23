package c04;

import javax.sound.midi.Instrument;
import java.util.Arrays;

/**
 * Created by Jimmy on 2015/5/24.
 */
public class ArrayTest {


    public static void main(String[] args){
        //1 - 声明
        int[] arrayOfInts;

        //初始化方法1
        arrayOfInts = new int[42];

        //初始化方法2
        double[] doublenums = new double[20];

        //初始化方法3
        int[] arrayOfInt1 = {1,2,3,4,5,6};

        //2 - 拷贝
        //arraycopy
        String[] names = {"Ryan", "Tim", "Shark", "Ted"};
        String[] tmparray = new String[names.length * 2];
        System.arraycopy(names, 0, tmparray, 0, 4);

        //copyOf
        String[] namearray = Arrays.copyOf(names, names.length);
        namearray = Arrays.copyOf(names, names.length + 2);

        //copyOfRange, 不包括to的元素
        namearray = Arrays.copyOfRange(names, 1, 3);

        //增强for循环遍历数组
        System.out.println("Copy function test: ");
        for(String d: namearray)
            System.out.print(" " + d);
        System.out.println();

        //3 - 多维数组
        boolean[][] checked;
        checked = new boolean[3][];
        checked[0] = new boolean[8];
        checked[1] = new boolean[8];
        checked[2] = new boolean[8];
        System.out.println("Multiarray test: ");
        for(boolean[] b:checked){
            for(boolean bv:b)
                System.out.print(bv + " ");
            System.out.println();
        }

        //System.out.println(doublenums.toString());

    }
}
