package c04;
/**
 * @project: DataStructureAndAlgorithmAnalysis
 * @filename: BinarySearchTree.java
 * @version: 0.10
 * @author: JM Han
 * @date: 18:38 2015/10/19
 * @comment: Test Purpose
 * @result:
 */

import c02.BinarySearch;
import master.UnderflowException;
import java.util.Comparator;
import static tool.util.*;

public class BinarySearchTree<AnyType extends Comparable<? super AnyType>> {
	private BinaryNode<AnyType> root;
	private static class BinaryNode<AnyType>{
		BinaryNode(AnyType theElement)
		{this(theElement, null, null);}

		BinaryNode(AnyType theElement, BinaryNode<AnyType> lt, BinaryNode<AnyType> rt)
		{element = theElement; left = lt; right = rt;}

		AnyType element;
		BinaryNode<AnyType> left;
		BinaryNode<AnyType> right;
	}



	public BinarySearchTree(){
		root = null;
	}

	public void makeEmpty(){
		root = null;
	}

	public boolean isEmpty(){
		return null == root;
	}

	public boolean contains(AnyType x){
		return contains(x, root);
	}

	public AnyType findMin(){
		if(isEmpty())
			throw new UnderflowException();
		return findMin(root).element;
	}

	public AnyType findMax(){
		if(isEmpty())
			throw new UnderflowException();
		return findMax(root).element;
	}

	public void insert(AnyType x){
		root = insert(x, root);
	}

	public void remove(AnyType x){
		root = remove(x, root);
	}

	public void printTree(){
		if(isEmpty())
			System.out.println("Empty Tree");
		else
			printTree(root);
	}

	private boolean contains(AnyType x, BinaryNode<AnyType> t){
		if(t == null)
			return false;

		int comparableResult = x.compareTo(t.element);

		if(comparableResult < 0)
			return contains(x, t.left);
		else if(comparableResult > 0)
			return contains(x, t.right) ;
		else
			return true;
	}
	private BinaryNode<AnyType> findMin(BinaryNode<AnyType> t){
		if(null == t)
			return null;
		else if(t.left == null)
			return t;
		return findMin(t.left);
	}

	private BinaryNode<AnyType> findMax(BinaryNode<AnyType> t){
		if(t != null)
			while(t.right != null)
				t = t.right;
		return t;
	}
	private BinaryNode<AnyType> insert(AnyType x, BinaryNode<AnyType> t){
		if(null == t)
			return new BinaryNode<AnyType>(x, null, null);
		int compareResult = x.compareTo(t.element);
		if(compareResult < 0)
			t.left = insert(x, t.left);
		else if(compareResult > 0)
			t.right = insert(x, t.right);
		else
			;
		return t;
	}
	private BinaryNode<AnyType> remove(AnyType x, BinaryNode<AnyType> t){
		if(null == t)
			return t;
		int compareResult = x.compareTo(t.element);

		if(compareResult < 0)
			t.left = remove(x, t.left);
		else if(compareResult > 0)
			t.right = remove(x, t.right);
		else if(t.left != null && t.right != null){
			t.element = findMin(t.right).element;
			t.right = remove(t.element, t.right);
		}
		else
			t = (t.left != null)?t.left:t.right;
		return t;
	}
	private void printTree(BinaryNode<AnyType> t){
		if(null != t){
			printTree(t.left);
			System.out.println(t.element);
			printTree(t.right);
		}
	}

	public static void main(String[] args) {
		BinarySearchTree<Integer> bst = new BinarySearchTree<Integer>();
		bst.insert(4);
		bst.insert(3);
		bst.insert(6);
		bst.insert(0);
		bst.insert(2);
		bst.insert(3);
		System.out.println("Contains 3: " + bst.contains(3));
		System.out.println("Max: " + bst.findMax());
		System.out.println("Min: " + bst.findMin());
		bst.remove(3);
		bst.printTree();
	}
}
