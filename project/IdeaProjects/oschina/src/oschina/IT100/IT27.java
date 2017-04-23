package oschina.IT100;

import data.tree.BSTree;

/**
 * @project: oschina
 * @filename: IT27.java
 * @version: 0.10
 * @author: JM Han
 * @date: 1:29 PM 1/6/2016
 * @comment: IT公司100题-tencent-打印所有高度为2的路径
 * @result: Your test result
 */

public class IT27 {
	public static void main(String[] args) {
		BSTree bsTree = new BSTree();
		bsTree.insert(10);
		bsTree.insert(6);
		bsTree.insert(16);
		bsTree.insert(4);
		bsTree.insert(8);
		bsTree.insert(14);
		bsTree.insert(18);
		bsTree.insert(2);
		bsTree.insert(5);
		bsTree.insert(12);
		bsTree.insert(15);
		bsTree.insert(20);
		bsTree.insert(11);
		//bsTree.printTree();
		bsTree.findDepthPath(2);
	}
}
