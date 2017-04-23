package oschina.IT100;
/**
 * @project: oschina
 * @filename: IT7.java
 * @version: 0.10
 * @author: JM Han
 * @date: 10:17 2015/11/4
 * @comment: Test Purpose
 * @result:
 */

class LinkedList7 {
	public static class Node{
		int data;
		Node next;
	}

	private Node head;

	//if there is no cycle
	boolean isJoinedSimple(Node n1, Node n2){
		while(n1 != null)
			n1 = n1.next;
		while(n2 != null)
			n2 = n2.next;
		return n1 == n2;
	}

	boolean hasLoop(Node n){
		Node nFast = n;
		Node nSlow = n;
		while(nFast != null && nSlow != null){
			nFast = nFast.next.next;
			nSlow = nSlow.next;
			if(nFast == nSlow)
				return true;
		}
		return false;
	}

	Node findLoopPort(LinkedList7 lst){
		Node nFast = lst.head;
		Node nSlow = lst.head;

		while(nFast != null && nFast.next!= null){
			nFast = nFast.next.next;
			nSlow = nSlow.next;
			if(nFast == nSlow) break;
		}
		if(nFast == null || nSlow == null)
			return null;
		nSlow = head;
		while(nSlow != nFast){
			nSlow = nSlow.next;
			nFast = nFast.next;
		}
		return nSlow;
	}
}

public class IT7 {
	public static void main(String[] args) {

	}
}
