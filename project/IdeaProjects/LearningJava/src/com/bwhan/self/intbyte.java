package self;

/**
 * Created by Jimmy on 2015/5/19.
 */
public class intbyte {
    public static void main(String[] args) {
        int i = 32;
        byte[] barray = toByteArray(i, 4);
/*
        for(int j = 0; j< barray.length; j++)
            System.out.println("byte[" + j + "] is: " + barray[j]);
*/

        for(byte bb: barray){
            System.out.println(bb);
        }
        {
            i = 2;
        }

    }
    public static byte[] toByteArray(int iSource, int iArrayLen) {
        byte[] bLocalArr = new byte[iArrayLen];
        for ( int i = 0; (i < 4) && (i < iArrayLen); i++) {
            bLocalArr[i] = (byte)( iSource>>8*i & 0xFF );

        }
        return bLocalArr;
    }

    // 将byte数组bRefArr转为一个整数,字节数组的低位是整型的低字节位
    public static int toInt(byte[] bRefArr) {
        int iOutcome = 0;
        byte bLoop;

        for ( int i =0; i<bRefArr.length ; i++) {
            bLoop = bRefArr[i];
            iOutcome+= (bLoop & 0xFF) << (8 * i);

        }

        return iOutcome;
    }
}
