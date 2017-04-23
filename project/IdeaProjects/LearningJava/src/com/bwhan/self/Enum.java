package LearnJava;

/**
 * Created by Jimmy on 2015/5/21.
 */

public enum Enum {
    RED(1), GREEN(3), ABC(4);

    private int i;
    private Enum(int j){ i = j;}

    @Override
    public String toString(){ return String.valueOf(i);}

    public static void main(String[] args){
        //调用toString
        System.out.println("Enum.RED: " + Enum.RED);

        Enum ie = Enum.ABC;
        switch (ie){
            case RED:
                System.out.println("Enum.RED! ");
                break;
            case GREEN:
                System.out.println("Enum.GREEN! ");
                break;
            case ABC:
                System.out.println("Enum.ABC! ");
                break;
        }
        Enum[] colors = Enum.values();
        for(Enum e:colors){
            System.out.println(e);
            System.out.println(e.name());
            System.out.println(e.ordinal());
        }
    }
}
