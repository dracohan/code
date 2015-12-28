package c12;
/**
 * @project: LearningJava
 * @filename: FileTest.java
 * @version: 0.10
 * @author: JM Han
 * @date: 22:36 2015/10/23
 * @comment: Test Purpose
 * @result:
 */

import java.io.File;
import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.List;

import static tool.util.*;

public class FileTest {
	public static void main(String[] args) {
		File file = new File("D:\\download\\effective2\\examples\\abc");
		System.out.println("==========part 1=========");
		//可以直接以字符串输出
		System.out.println(file);
		//得到文件名
		System.out.println(file.getName());
		//得到路径
		System.out.println(file.getPath());
		System.out.println(file.getAbsoluteFile());
		System.out.println(file.getAbsolutePath());
		//得到父目录
		System.out.println(file.getParent());

		System.out.println("==========part 2=========");
		String[] files = file.list();
		File[] filelst = file.listFiles();
		System.out.println(files);
		System.out.println(filelst);
		//List list = Arrays.asList(filelst);
		//Collections.sort(list);
		//System.out.println(list);

		System.out.println("==========part 3=========");




	}
}
