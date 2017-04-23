package data.tree;

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.LinkedList;
import java.util.Stack;

import static tool.util.printGenericColection;

/**
 * @project: oschina
 * @filename: BSTree.java
 * @version: 0.10
 * @author: JM Han
 * @date: 2:05 PM 12/15/2015
 * @comment: Binary search tree
 * @result:
 */

public class BSTree{
	class BSTreeNode{
		BSTreeNode(int x, BSTreeNode lt, BSTreeNode rt){
			value = x;
			left = lt;
			right = rt;
		}
		int value;
		BSTreeNode left;
		BSTreeNode right;
	}
	//Elements
	private BSTreeNode root;
	//Constructor
	public BSTree(){
		root = null;
		//IT1 specific
		head = null; last = null;
		//IT4 specific
		currentSum = 0;
		path = new Stack<Integer>();
	}
	//Checker
	private boolean isLeaf(BSTreeNode bsTreeNode){
		return bsTreeNode.left == null && bsTreeNode.right == null;
	}
	//Operations
	public void insert(int value){
		root = insert(root, value);
	}
	private BSTreeNode insert(BSTreeNode t, int value) {
		if (null == t)
			return new BSTreeNode(value, null, null);

		if (t.value > value)
			t.left = insert(t.left, value);
		else if (t.value < value)
			t.right = insert(t.right, value);
		else
			//duplicate
			System.out.println("already exist");
		return t;
	}

	public boolean isEmpty(){
		return null == root;
	}

	public void printTree(){
		if(isEmpty())
			System.out.println("Empty Tree");
		else
			printTree(root);
	}

	private void printTree(BSTreeNode t){
		if(null != t){
			printTree(t.left);
			System.out.println(t.value);
			printTree(t.right);
		}
	}

	//IT1 start
	private BSTreeNode head;
	private BSTreeNode last;
	public void treeToList(){
		treeToList(root);
	}

	private void treeToList(BSTreeNode root){
		if(null == root)
			return;
		treeToList(root.left);
		//previous pointer
		root.left = last;
		if(null == last)
			head = root;
		else
			//next pointer
			last.right = root;
		//last is the current root node
		last = root;
		treeToList(root.right);
	}

	public void printList(){
		if(null == head)
			return;
		while(head != null) {
			System.out.println(head.value);
			head = head.right;
		}
	}
	//IT1 end

	//IT4 Start
	private int currentSum;
	private Stack<Integer> path;
	public void findPath(int expectSum){
		findPath(root, expectSum);
	}
	private void findPath(BSTreeNode t, int expectSum){
		if(null == t)
			return;
		currentSum += t.value;
		path.push(t.value);
		//1, check each point
		boolean isLeaf = (t.left == null && t.right == null);
		if(isLeaf && currentSum == expectSum){
			System.out.println("gotta:");
			printGenericColection(path);
		}
		//2, check left tree
		if(null != t.left)
			findPath(t.left, expectSum);
		//3, check right tree
		if(null != t.right)
			findPath(t.right, expectSum);
		//finish check on this node, pop
		currentSum -= t.value;
		path.pop();
	}
	//IT4 end

	//IT15 start
	public void mirrorChange(){
		mirrorChange(root);
	}
	public void mirrorChange(BSTreeNode n){
		if(n == null){
			return;
		}
		if(n.left != null){
			mirrorChange(n.left);
		}
		if(n.right != null){
			mirrorChange(n.right);
		}
		BSTreeNode tmp = n.left;
		n.left = n.right;
		n.right = tmp;
	}
	//IT15 end

	//IT16 start
	public void DFSTraverse(){
		if(null == root)
			return;
		Stack<BSTreeNode> stack = new Stack<BSTreeNode>();
		stack.push(root);
		while(!stack.isEmpty()){
			BSTreeNode node = stack.pop();
			System.out.println(node.value);
			if(node.right != null)
				stack.push(node.right);
			if(node.left != null)
				stack.push(node.left);
		}
	}

	public void BFSTraverse(){
		if(null == root)
			return;
		Deque<BSTreeNode> deque = new ArrayDeque<BSTreeNode>();
		deque.addLast(root);
		while(!deque.isEmpty()){
			BSTreeNode node = deque.removeFirst();
			System.out.println(node.value);
			if (node.left != null)
				deque.addLast(node.left);
			if (node.right != null)
				deque.addLast(node.right);
		}
	}
	//IT16 end

	//IT27 start
	private LinkedList<BSTreeNode> lst = new LinkedList<BSTreeNode>();
	public void findDepthPath(int depth){
		findDepthPath(root, depth);
	}
	private void findDepthPath(BSTreeNode bsTreeNode, int expected){
		//inorder traversal tree
		//checkNode for each node
		checkNode(bsTreeNode, expected);
		if(bsTreeNode.left != null)
			findDepthPath(bsTreeNode.left, expected);
		if(bsTreeNode.right != null)
			findDepthPath(bsTreeNode.right, expected);
	}
	//Find all the expected depth leaf and print path
	private void checkNode(BSTreeNode bsTreeNode, int expected){
		lst.addLast(bsTreeNode);
		if(isLeaf(bsTreeNode) && expected == 0) {
			System.out.println("Get: ");
			for (int i = 0; i < lst.size(); i++) {
				System.out.print(lst.get(i).value + " ");
			}
			System.out.println();
		}
		if(bsTreeNode.left != null && expected > 0) {
			checkNode(bsTreeNode.left, --expected);
			++expected;
		}
		if(bsTreeNode.right != null && expected > 0) {
			checkNode(bsTreeNode.right, --expected);
			++expected;
		}
		lst.removeLast();
	}
	//IT27 end
}
