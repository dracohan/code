package oschina.IT100;
/**
 * @project: oschina
 * @filename: IT3.java
 * @version: 0.10
 * @author: JM Han
 * @date: 14:59 2015/10/22
 * @comment: Test Purpose
 * @result:
 */

import data.tree.BSTree;

public class IT4 {
	public static void main(String[] args) {
		BSTree bsTree = new BSTree();
		bsTree.insert(14);
		bsTree.insert(5);
		bsTree.insert(16);
		bsTree.insert(3);
		bsTree.insert(11);
		bsTree.findPath(30);
	}
}
