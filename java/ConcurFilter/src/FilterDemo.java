/*
 *Date : 20181207
 *Author : ElmaHuang
 */
import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;

public class FilterDemo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String DirName = "C:\\Users\\24681\\Desktop\\file";
		String[] fileName = getFileName(DirName);
		String new_content;
		for(String file_name:fileName) {
			new_content = filterFile(DirName+"\\"+file_name);

			//write new file content
			writeFile(DirName+"\\fix_"+file_name,new_content);
		}		
	}


	private static void writeFile(String file_name, String content) {
		// TODO Auto-generated method stub
		try {
			System.out.println(content);
			Files.write(Paths.get(file_name),content.getBytes(),StandardOpenOption.CREATE);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}		
	}


	private static String[] getFileName(String dirName) {
		// TODO Auto-generated method stub
		File f = new File(dirName);
		String[] fn = new String[4];
		int i = 0;
		for(String name :f.list()) {
			fn[i]=name;
			i++;
		}			
		return fn;
	}
	

	private static String filterFile(String file_name) {
		// TODO Auto-generated method stub
		String new_content = null;
		try {
			//read file content
			String input_content = new String(Files.readAllBytes(Paths.get(file_name)),"UTF-8");
			
			//filter
			new_content = filter(input_content);			
		
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return new_content;
	}


	private static String filter(String content) {
		// TODO Auto-generated method stub
		String[] Pattern = content.split("\\|");
		for(String tokens:Pattern) {
			switch(tokens) {
				case "5113":
				case "6113":
				case "7113":
				case "8113":
					content = content.replace(tokens, "F35F");
			}
		}
		return content;
	}

}

