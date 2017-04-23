package oschina.IT100;
/**
 * @project: oschina
 * @filename: IT8.java
 * @version: 0.10
 * @author: JM Han
 * @date: 15:31 2015/11/4
 * @comment: Test Purpose
 * @result:
 */

class LinkedListIT8{
	static class Node{
		int data;
		Node next;
		Node(int x, Node n){
			data = x;
			next = n;
		}
	}

	private Node head;
	private Node tail;
	private int theSize;

	LinkedListIT8(){
		head = new Node(-1, null);
		tail = new Node(-1, null);
		head.next = tail;
		theSize = 0;
	}

	public int size(){
		return theSize;
	}

	public void add(int x){
		addAfter(getNode(size()), x);
	}

	private void addAfter(Node p, int x){
		Node newNode = new Node(x, p);
		newNode.next = p.next;
		p.next = newNode;
		theSize++;
	}

	private Node getNode(int idx){
		Node p = head;
		for (int i = 0; i < idx; i++)
			p=p.next;
		return p;
	}

	public void printList(){
		Node p = head.next;
		for (int i = 0; i < size(); i++) {
			System.out.print(p.data + " ");
			p = p.next;
		}
	}

	public void reverse(){
		reverseR(head);
		//reverseNR(head);
	}

	private Node reverseR(Node currentNode){
		if(currentNode == tail) {
			Node phead = head;
			head = currentNode;
			tail = phead;
			tail.next = null;
		} else {
			reverseR(currentNode.next).next = currentNode;
		}

		return currentNode;
	}

	private void reverseNR(Node phead){
		Node pre = head;
		Node cur = head.next;
		Node np;

		while(cur != tail){
			np = cur.next;
			cur.next = pre;
			pre = cur;
			cur = np;
		}

		head = cur;
		cur.next = pre;

		tail = phead;
		tail.next = null;
	}
}
public class IT8 {
	public static void main(String[] args) {
		LinkedListIT8 ll = new LinkedListIT8();
		ll.add(0);ll.add(1);ll.add(2);ll.add(3);
		ll.add(4);ll.add(5);ll.add(6);ll.add(7);
		ll.printList();
		ll.reverse();
		System.out.println("\n***************");
		ll.printList();
		ll.reverse();
		System.out.println("\n***************");
		ll.printList();

		String str = "abc";
		StringBuilder sb = new StringBuilder(str);
		sb.reverse();
		System.out.println(sb);
	}
}
