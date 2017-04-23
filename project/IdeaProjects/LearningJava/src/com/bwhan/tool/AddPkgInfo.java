package tool;
/**
 * @project: LearningJava
 * @filename: AddPkgInfo.java
 * @version: 0.10
 * @author: JM Han
 * @date: 15:55 2015/10/23
 * @comment: Test Purpose
 * @result:
 */

import java.io.*;

public class AddPkgInfo {

	private int fileNum;

	public static void parDir(File dir){
		System.out.println("Entering directory: " + dir.toString());

		File[] files = dir.listFiles();

		if(null == files)
			return;

		for(File file : files){
			if(file.isDirectory())
				parDir(file);
			else
				parFile(file);
		}

		System.out.println("leaving directory: " + dir.toString());
	}

	public static void parFile(File f){
		//System.out.println("parsing " + f.toString());
		try {
			RandomAccessFile pwdout =
					new RandomAccessFile(f.toString(),"rw");
			System.out.println("add info to " + f + "...");
			pwdout.seek(0);
			pwdout.writeUTF("really?.");
			pwdout.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
		//System.out.println("parsed " + f.toString());

	}

	public static void main(String[] args) {
		File file = new File("D:\\download\\effective2\\examples");

		if(!file.exists() || !file.canRead())
			System.out.println("Can't read!" + file);

		parDir(file);
	}
}
