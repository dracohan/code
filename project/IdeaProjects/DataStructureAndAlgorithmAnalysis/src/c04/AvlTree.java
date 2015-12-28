package c04;
/**
 * @project: DataStructureAndAlgorithmAnalysis
 * @filename: AvlTree.java
 * @version: 0.10
 * @author: JM Han
 * @date: 15:04 2015/10/21
 * @comment: Test Purpose
 * @result:
 */

import master.UnderflowException;

import static tool.util.*;

public class AvlTree<AnyType extends Comparable<? super AnyType>>{
	private static final int ALLOWED_IMBALANCE = 1;
	private AvlNode<AnyType> root;

	private static class AvlNode<AnyType>{
		AvlNode(AnyType theElement)
		{this(theElement, null, null);}

		AvlNode(AnyType theElement, AvlNode lt, AvlNode rt)
		{element = theElement; left = lt; right = rt;}

		AnyType element;
		AvlNode<AnyType> left;
		AvlNode<AnyType> right;
		int height;
	}

	public int height(AvlNode<AnyType> t){
		return t == null?-1:t.height;
	}

	public boolean isEmpty(){
		return null == root;
	}

	public void insert(AnyType x){
		root = insert(x,root);
	}

	public void remove(AnyType x){
		root = remove(x,root);
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

	public boolean contains(AnyType x){
		return contains(x, root);
	}

	public void printTree(){
		if(isEmpty())
			System.out.println("Empty Tree");
		else
			printTree(root);
	}

	private AvlNode<AnyType> insert(AnyType x, AvlNode<AnyType> t){
		if(null == t)
			return new AvlNode<AnyType>(x, null, null);

		int compareResult = x.compareTo(t.element);

		if(compareResult < 0)
			t.left = insert(x, t.left);
		else if(compareResult > 0)
			t.right = insert(x, t.right);
		else
			;//Duplicat, do nothing

		return balance(t);
	}

	private AvlNode<AnyType> balance(AvlNode<AnyType> t) {
		if (null == t)
			return t;

		if (height(t.left) - height(t.right) > ALLOWED_IMBALANCE) {
			if (height(t.left.left) >= height(t.left.right))
				t = rotateWithLeftChild(t);
			else
				t = doubleWithLeftChild(t);
		}
		else if(height(t.right) - height(t.left) > ALLOWED_IMBALANCE){
			if(height(t.right.right) >= height(t.right.left))
				t = rotateWithRightChild(t);
			else
				t = doubleWithRightChild(t);
		}
		//不进行Rotate操作时依然需要更新t的height
		t.height = Math.max(height(t.left), height(t.right)) + 1;
		return t;

	}

	private AvlNode<AnyType> rotateWithLeftChild(AvlNode<AnyType> k2){
		AvlNode<AnyType> k1 = k2.left;
		k2.left = k1.right;
		k1.right = k2;
		k2.height = Math.max(height(k2.left), height(k2.right)) + 1;
		k1.height = Math.max(height(k1.left), k2.height) + 1;
		return k1;
	}

	private AvlNode<AnyType> rotateWithRightChild(AvlNode<AnyType> k2){
		AvlNode<AnyType> k1 = k2.right;
		k2.right = k1.left;
		k1.left = k2;
		k2.height = Math.max(height(k2.left), height(k2.right)) + 1;
		k1.height = Math.max(height(k1.right), k2.height) + 1;
		return k1;
	}

	private AvlNode<AnyType> doubleWithLeftChild(AvlNode<AnyType> k3){
		k3.left = rotateWithRightChild(k3.left);
		return rotateWithLeftChild(k3);
	}

	private AvlNode<AnyType> doubleWithRightChild(AvlNode<AnyType> k3){
		k3.right = rotateWithLeftChild(k3.right);
		return rotateWithRightChild(k3);
	}


	private AvlNode<AnyType> remove(AnyType x, AvlNode<AnyType> t){
		if(null == t)
			return t;

		int compareResult = x.compareTo(t.element);

		if(compareResult < 0)
			t.left = remove(x, t.left);
		else if(compareResult > 0)
			t.right = remove(x, t.right);
		else if(t.left != null && t.right != null){
			t.element   = findMin(t.right).element;
			t.right = remove(t.element, t.right);
		} else
			t = (t.left != null)?t.left:t.right;
		return balance(t);
	}

	private AvlNode<AnyType> findMin(AvlNode<AnyType> t){
		if(null == t)
			return null;
		else if(t.left == null)
			return t;
		return findMin(t.left);
	}

	private AvlNode<AnyType> findMax(AvlNode<AnyType> t){
		if(t != null)
			while(t.right != null)
				t = t.right;
		return t;
	}

	private boolean contains(AnyType x, AvlNode<AnyType> t){
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

	private void printTree(AvlNode<AnyType> t){
		if(null != t){
			printTree(t.left);
			System.out.println(t.element);
			printTree(t.right);
		}
	}

	public static void main(String[] args) {
		AvlTree<Integer> avlt = new AvlTree<Integer>();
		avlt.insert(4);
		avlt.insert(3);
		avlt.insert(6);
		avlt.insert(0);
		avlt.insert(2);
		avlt.insert(3);
		avlt.printTree();
		System.out.println("Contains 3: " + avlt.contains(3));
		System.out.println("Max: " + avlt.findMax());
		System.out.println("Min: " + avlt.findMin());
		avlt.remove(3);
		avlt.printTree();
	}


}
