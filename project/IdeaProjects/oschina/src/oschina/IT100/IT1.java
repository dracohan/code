package oschina.IT100;

import data.tree.BSTree;

/**
 * @project: oschina
 * @filename: IT1.java
 * @version: 0.10
 * @author: JM Han
 * @date: 14:55 2015/10/19
 * @comment: 将该二元查找树转换成一个排序的双向链表
 * @result:
 */

public class IT1 {
	public static void main(String[] args) {
		BSTree bsTree = new BSTree();
		bsTree.insert(10);
		bsTree.insert(6);
		bsTree.insert(14);
		bsTree.insert(4);
		bsTree.insert(8);
		bsTree.insert(12);
		bsTree.insert(16);
		bsTree.treeToList();
		bsTree.printList();
	}
}
