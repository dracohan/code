package oschina.IT100;

import java.util.Scanner;

/**
 * @project: oschina
 * @filename: IT18.java
 * @version: 0.10
 * @author: JM Han
 * @date: 21:59 2015/12/19
 * @comment: josephus
 * @result:
 */

public class IT18 {
	private static class Node{
		public int no;
		public Node next;
		public Node(int no){
			this.no = no;
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the whole number: ");
		int total = sc.nextInt();
		System.out.println("Enter the inter number: ");
		int count = sc.nextInt();
		Node header = new Node(1);
		Node current = header;
		for (int i = 2; i <= total; i++){
			current.next = new Node(i);
			current = current.next;
		}
		//cycle
		current.next = header;
		System.out.println("Below is the sequence of deletion: ");
		//while still have more than 1 element
		while(current.next != current){
			for (int i = 1; i < count; i++){
				current = current.next;
			}
			System.out.println("delete node: " + current.next.no);
			current.next = current.next.next;
		}
		System.out.println("The last node is: " + current.no);


	}
}