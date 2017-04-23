package oschina.cc150;

import data.list.linkedlist;
import data.list.linkedlist.Node;
/**
 * @project: oschina
 * @filename: cc0206.java
 * @version: 0.10
 * @author: JM Han
 * @date: 21:42 2015/12/6
 * @comment: Test Purpose
 * @result:
 */

public class cc0206 {
	public static boolean judgeJoined(Node head){
		Node slow = head;
		Node fast = head;
		while(slow != null && fast != null){
			slow = slow.next;
			fast = fast.next.next;
			if(fast == slow)
				return true;
		}
		return false;
	}

	public static Node findJoinedNode(Node head){
		/*
		 * 从头节点到入口设为k
		 * slow到k的时候，fast已经在环内k个节点
		 * 那么，再经过loop-k步骤两个节点会相遇
		 * 所以，相遇点距入口点也为k
		 */
		Node slow = head.next;
		Node fast = head.next.next;
		while(slow != fast){
			slow = slow.next;
			fast = fast.next.next;
		}
		slow = head;
		while(slow != fast){
			slow = slow.next;
			fast = fast.next;
		}
		return slow;
	}



	public static void main(String[] args) {
		linkedlist lst = new linkedlist();
		Node head = lst.genCycle();
		boolean existS = judgeJoined(head);
		System.out.println(existS);
		int nodeData = findJoinedNode(head).data;
		System.out.println(nodeData);
	}
}
