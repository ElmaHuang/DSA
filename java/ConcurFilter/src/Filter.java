import java.io.*;

public class Filter {
	public Filter(String Input_fileName){
		try {
			FileReader fileReader = new FileReader(Input_fileName);
			System.out.print(fileReader);
		
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
}
