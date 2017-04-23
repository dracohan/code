package oschina.IT100;

import data.tree.BSTree;

/**
 * @project: oschina
 * @filename: IT16.java
 * @version: 0.10
 * @author: JM Han
 * @date: 4:58 PM 12/17/2015
 * @comment: Test Purpose
 * @result: Your test result
 */

public class IT16 {
	public static void main(String[] args) {
		BSTree bsTree = new BSTree();
		bsTree.insert(6);
		bsTree.insert(4);
		bsTree.insert(12);
		bsTree.insert(2);
		bsTree.insert(5);
		bsTree.insert(8);
		bsTree.insert(16);
		System.out.println("DFS:");
		bsTree.DFSTraverse();
		System.out.println("BFS:");
		bsTree.BFSTraverse();
	}
}
