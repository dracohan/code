package data.list;

import java.util.Hashtable;

/**
 * @project: oschina
 * @filename: linkedlist.java
 * @version: 0.10
 * @author: JM Han
 * @date: 16:29 2015/11/22
 * @comment: Test Purpose
 * @result:
 */

public class linkedlist<AnyType> {
	public static class Node{
		public int data;
		public Node next = null;
		public Node(int d, Node p){
			data = d;
			next = p;
		}
	}
	private Node head;
	private Node tail;
	private int size;

	public linkedlist(){
		head = new Node(-1, null);
		tail = new Node(-1, null);
		head.next = tail;
		size = 0;
	}

	public int size(){
		return size;
	}

	public void print(){
		Node p = head.next;
		for (int i = 0; i < size(); i++) {
			System.out.print(p.data + " ");
			p = p.next;
		}
		System.out.print("\n");
	}

	//GET Operations
	public Node head(){
		return getNode(0);
	}

	public Node tail(){
		return getNode(size()-1);
	}

	public Node getNode(int idx){
		if(idx < -1 || idx > size())
			throw new IndexOutOfBoundsException();

		Node p = head;
		for (int i = -1; i < idx; i++)
			p=p.next;
		return p;
	}

	//SIMPLE MODIFY Operations
	public void add(int x){
		addAfter(getNode(size() - 1), x);
	}

	private void addAfter(Node p, int x){
		Node newNode = new Node(x, p);
		newNode.next = p.next;
		p.next = newNode;
		size++;
	}

	public void remove(int idx){
		removeAfter(getNode(idx));
	}

	public void removeHead(){
		removeAfter(getNode(-1));
	}

	public void removeTail(){
		removeAfter(getNode(size()-2));
	}

	private void removeAfter(Node p){
		p.next = p.next.next;
		size--;
	}

	//COMPLICATED MODIFY Operations
	public void reverse(){
		reverse(head);
	}

	private Node reverse(Node current){
		if(current == tail){
			Node preHead = head;
			head = current;
			tail = preHead;
			//BUGFIX: 20151215
			//has to set tail.next to null
			//or it will point to first element and generate cycle
			tail.next = null;
		}else
			reverse(current.next).next = current;
		return current;
	}


	///
	///Below is for specific purpose
	///

	//创造有环的节点以供测试
	public Node genCycle(){
		Node n1 = new Node(1, null);
		Node n2 = new Node(2, null);
		Node n3 = new Node(3, null);
		Node n4 = new Node(4, null);
		Node n5 = new Node(5, null);
		Node n6 = new Node(6, null);
		Node n7 = new Node(7, null);
		Node n8 = new Node(8, null);
		Node n9 = new Node(8, null);

		head.next = n1;
		n1.next = n2;
		n2.next = n3;
		n3.next = n4;
		n4.next = n5;
		n5.next = n6;
		n6.next = n7;
		n7.next = n8;
		n8.next = n9;
		n9.next = n7;

		return head;
	}

	//reverse the list

	//cc0201, deleteDuplicate
	public void deleteDup() {
		//version1, 使用缓存
		Hashtable hashtable = new Hashtable<Integer, Boolean>();
		Node p = head;
		while (p.next != null) {
			if (hashtable.containsKey(p.next.data) == false) {
				hashtable.put(p.next.data, true);
				//不包含元素是，前进
				p = p.next;
			} else {
				//包含元素是，删除元素操作已经包含了前进动作，不用执行p = p.next
				removeAfter(p);
			}
		}

		//version2,不使用缓存
/*
		Node p = head.next;
		while(p != null){
			Node runner = p;
			while(runner.next != null){
				if(runner.next.data == p.data){
					runner.next = runner.next.next;
					size--;
				}else{
					runner = runner.next;
				}
			}
			p = p.next;
		}*/
	}


	//cc0202/IT13, 找到倒数第k个元素
	public void nthToLast(int k){
		//nthToLastv1(head, k);
		nthToLastv2(k);
	}
	private int nthToLastv1(Node p, int k){
		if(p.next == null)
			return 0;
		int i = nthToLastv1(p.next, k) + 1;
		if(k == i)
			System.out.println(p.data);
		return i;
	}
	private void nthToLastv2(int k){
		Node p1 = head.next;
		Node p2 = head.next;
		for (int i = 1; i < k; i++){
			p2 = p2.next;
		}

		while(p2.next != tail){
			p1 = p1.next;
			p2 = p2.next;
		}
		if(p1 != null) System.out.println(p1.data);
	}

	//cc0203, 删除某一个节点之后的节点
	public boolean deleteNode(Node currentNode){
		if(currentNode == null || currentNode.next == null) return false;

		currentNode.data = currentNode.next.data;
		currentNode.next = currentNode.next.next;
		return true;
	}

	//cc0204, 以某一个值x将链表排序
	public void splitByX(int x){
		//用另外的两个链表串接链表
		Node larger = null;
		Node smaller = null;
		Node equaller = null;
		Node largerHead = null;
		Node smallerHead = null;
		for (int i = 0; i < size(); i++){
			Node node = getNode(i);
			if(node.data < x){
				if(smaller == null){
					smaller = node;
					smallerHead = node;
				}else{
					smaller.next = node;
					smaller = node;
				}
			} else if(node.data > x){
				if(larger == null){
					larger = node;
					largerHead = node;
				}else{
					larger.next = node;
					larger = node;
				}
			} else{
				equaller = node;
			}
		}

		if(larger != null) larger.next = null;

		if(smaller == null){
			//直接返回某一部分链表
			if(equaller != null){
				//重新设置头节点
				head.next = equaller;
				return;
			}
			if(larger != null){
				//重新设置头节点
				head.next = larger;
				return;
			}
		} else {
			//拼接链表
			if (equaller != null){
				smaller.next = equaller;
				equaller.next = largerHead;
			} else{
				smaller.next = largerHead;
			}
			//重新设置头节点
			head.next = smallerHead;
		}
	}

	public static void main(String[] args) {
		linkedlist lst = new linkedlist();
		lst.add(9);	lst.add(8);	lst.add(7);	lst.add(6);	lst.add(5);	lst.add(1);
		lst.add(4);	lst.add(3);	lst.add(2);	lst.add(0);	lst.add(7);	lst.add(6);

		System.out.println("list operation test:");
		lst.print();
		System.out.println("after remove the last item");
		lst.removeTail();
		lst.print();
		System.out.println("after reverse:");
		lst.reverse();
		lst.print();

		System.out.println();
		System.out.println("cc150 excise test:");

		System.out.println("cc0201:");
		System.out.println("before: ");
		lst.print();
		lst.deleteDup();
		System.out.println("after: ");
		lst.print();System.out.print("\n");

		System.out.println("cc0202:");
		lst.nthToLast(10);System.out.print("\n");

		System.out.println("cc0204:");
		//Bugfound: 20151215
		//lst.splitByX(5);
		lst.print();
	}
}
