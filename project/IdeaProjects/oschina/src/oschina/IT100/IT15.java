package oschina.IT100;

import data.tree.BSTree;

/**
 * @project: oschina
 * @filename: IT15.java
 * @version: 0.10
 * @author: JM Han
 * @date: 4:51 PM 12/16/2015
 * @comment: Test Purpose
 * @result:  mirror ur BStree
 */

public class IT15 {
	public static void main(String[] args) {
		//refer to BSTree
		BSTree bsTree = new BSTree();
		bsTree.insert(14);
		bsTree.insert(5);
		bsTree.insert(16);
		bsTree.insert(3);
		bsTree.insert(11);
		bsTree.printTree();
		bsTree.mirrorChange();
		bsTree.printTree();
	}
}
