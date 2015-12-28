package self;
/**
 * @project: ThinkingInJava
 * @filename: collectionTest.java
 * @version: 0.10
 * @author: Jimmy Han
 * @date: 1:28 PM 10/13/15
 * @comment: Test Purpose
 * @result:
 */

import java.util.*;

import static tool.util.printEnumeration;
import static tool.util.printGenericColection;
import static tool.util.printGenericIterator;

abstract class testList implements List<String>{

}

public class collectionTest {
    public static void main(String[] args) {

        /*
        Collection       接口的接口     对象的集合
        ├ List             子接口         按进入先后有序保存   可重复
        │├ LinkedList    接口实现类     链表     插入删除   没有同步   线程不安全
        │├ ArrayList     接口实现类      数组     随机访问   没有同步   线程不安全
        │└ Vector        接口实现类       数组                      同步        线程安全
        │ 　 └ Stack
        └ Set             子接口       仅接收一次，并做内部排序
        ├ HashSet
        │ 　 └ LinkedHashSet
        └ TreeSet
*/
        //Collection

        //允许对元素进行快速随机访问，但是向 List 中间插入与移除元素的速度很慢。
        ArrayList<String> arrayList = new ArrayList<String>();
        //对顺序访问进行了优化，向 List 中间插入与删除的开销并不大。随机访问则相对较慢。
        LinkedList<String> linkedList = new LinkedList<String>();
        // Stack 继承自 Vector ，实现一个后进先出的堆栈。
        Stack<String> mystack = new Stack<String>();
        // Vector 非常类似 ArrayList ，但是 Vector 是同步的。
        Vector<String> myvec = new Vector<String>();

	    //iterator.remove的用法
	    System.out.println("test 1:");
	    ListIterator itr = arrayList.listIterator();
	    itr.add("a");
	    itr.add("b");
	    itr.add("d");
	    Iterator itrr = arrayList.iterator();
	    itrr.next();
	    itrr.remove();
	    printGenericIterator(itrr);


        //Set
        //Set 是一种不包含重复的元素的 Collection
        //加入 Set 的元素必须定义 equals() 方法以确保对象的唯一性
        // Set 接口不保证维护元素的次序。

        //为快速查找设计的 Set 。存入 HashSet 的对象必须定义 hashCode() 。
        HashSet<String> hashSet = new HashSet<String>();
        //具有 HashSet 的查询速度，且内部使用链表维护元素的顺序
        LinkedHashSet<String> linkedHashSet= new LinkedHashSet<String>();
        //保存排序的序列, 底层为树结构。使用它可以从 Set 中提取有序的序列。
        TreeSet<String> treeSet= new TreeSet<String>();

        //Set不允许有重复元素
	    System.out.println("test 2:");
        treeSet.add("a");treeSet.add("b");treeSet.add("c");treeSet.add("b");
        printGenericColection(treeSet);

	    //检查add返回值
	    boolean b = treeSet.add("b");
	    System.out.println("b: " + b);

/*      Map                接口      键值对的集合
        ├ Hashtable                 接口实现类                同步        线程安全
        ├ HashMap                  接口实现类                没有同步    线程不安全
        │├ LinkedHashMap
        │└ WeakHashMap
        ├ TreeMap
        └ IdentifyHashMap
*/
        //Map 也有内置的排序，因而不关心元素添加的顺序。
        // 如果添加元素的顺序对你很重要，应该使用 LinkedHashSet 或者 LinkedHashMap

        //Hashtable 继承 Map 接口，实现一个 key-value 映射的哈希表。
        // 任何非空（ non-null ）的对象都可作为 key 或者 value
        Hashtable<Integer, String> hashtable = new Hashtable<Integer, String>();
        //HashMap 和 Hashtable 类似，也是基于散列表的实现。不同之处在于 HashMap 是非同步的
        //并且允许 null ，即 null value 和 null key
        HashMap<Integer, String> hashMap = new HashMap<Integer, String>();
        //类似于 HashMap ，但是迭代遍历它时，取得“键值对”的顺序是其插入次序，或者是最近最少使用 (LRU) 的次序
        LinkedHashMap<Integer, String> linkedHashMap = new LinkedHashMap<Integer, String>();
        //弱键（ weak key ） Map 是一种改进的 HashMap ，它是为解决特殊问题设计的，对 key 实行 “ 弱引用 ”
        //如果一个 key 不再被外部所引用（没有 map 之外的引用），那么该 key 可以被垃圾收集器 (GC) 回收。
        WeakHashMap<Integer, String> weakHashMap = new WeakHashMap<Integer, String>();
        //基于红黑树数据结构的实现。
        //查看“键”或“键值对”时，它们会被排序 ( 次序由 Comparabel 或 Comparator 决定 ) 。
        //TreeMap 的特点在于，你得到的结果是经过排序的。
        // TreeMap 是唯一的带有 subMap() 方法的 Map ，它可以返回一个子树。
        TreeMap<Integer, String> treeMap = new TreeMap<Integer, String>();
        //使用 == 代替 equals() 对“键”作比较的 hash map
        IdentityHashMap<Integer, String> identityHashMap = new IdentityHashMap<Integer, String>();


        //Java 所有“存储及随机访问一连串对象”的做法， array 是最有效率的一种。但缺点是容量固定且无法动态改变。
        // array 还有一个缺点是，无法判断其中实际存有多少元素， length 只是告诉我们 array 的容量。
        //Java 中有一个数组类 (Arrays) ，专门用来操作 array 。数组类 (arrays) 中拥有一组 static 函数。
        //equals() ：比较两个 array 是否相等。 array 拥有相同元素个数，且所有对应元素两两相等。
        //fill() ：将值填入 array 中。
        //sort() ：用来对 array 进行排序。
        //binarySearch() ：在排好序的 array 中寻找元素。
        //System.arraycopy() ： array 的复制。
        //若编写程序时不知道究竟需要多少对象，需要在空间不足时自动扩增容量，则需要使用容器类库， array 不适用。



    }
}
