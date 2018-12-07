/*
 *Date : 20181207
 *Author : ElmaHuang
 */
import java.io.*;

public class FilterDemo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String DirName = "C:\\Users\\24681\\Desktop\\file";
		String[] fileName = getFileName(DirName);
		for(String file_name:fileName) {
			filterFile(DirName+"\\"+file_name);
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
	

	private static void filterFile(String file_name) {
		// TODO Auto-generated method stub
		try {
			BufferedReader reader = new BufferedReader(new FileReader(file_name));
			String line = reader.readLine();
			while(line != null) {
				String new_line = filterLine(line);
				//write new_line into file
				
				//read next line
				line = reader.readLine();
			}		
		
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}		
	}


	private static String filterLine(String line) {
		// TODO Auto-generated method stub
		String[] Pattern = line.split("\\|");
		for(String tokens:Pattern) {
			switch(tokens) {
				case "5113":
				case "6113":
				case "7113":
				case "8113":
					//System.out.println(line);
					line = line.replace(tokens, "F35F");
					//System.out.println(line);					
			}
		}
		return line;
	}

}

