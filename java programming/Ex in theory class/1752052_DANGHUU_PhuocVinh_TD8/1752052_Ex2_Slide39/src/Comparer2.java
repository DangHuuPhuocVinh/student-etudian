import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Comparer2 {

	 public static void main(String[] args) throws IOException
	    {	

	        File file = new File("C:\\\\Users\\\\Vinh\\\\Desktop\\\\phones.txt"); 
	        FileInputStream fileStream = new FileInputStream(file); 
	        InputStreamReader input = new InputStreamReader(fileStream); 
	        BufferedReader reader = new BufferedReader(input); 
	        
	        File file2 = new File("C:\\\\Users\\\\Vinh\\\\Desktop\\\\java_notes.txt"); 
	        FileInputStream fileStream2 = new FileInputStream(file2); 
	        InputStreamReader input2 = new InputStreamReader(fileStream2); 
	        BufferedReader reader2 = new BufferedReader(input2); 
	        
	        String line1 = reader.readLine();
	         
	        String line2 = reader2.readLine();
	         
	        boolean areEqual = true;
	         
	        int lineNum = 1;
	         
	        while (line1 != null || line2 != null)
	        {
	            if(line1 == null || line2 == null)
	            {
	                areEqual = false;
	                 
	                break;
	            }
	            else if(! line1.equalsIgnoreCase(line2))
	            {
	                areEqual = false;
	                 
	                break;
	            }
	             
	            line1 = reader.readLine();
	             
	            line2 = reader2.readLine();
	             
	            lineNum++;
	        }
	         
	        if(areEqual == true)
	        {
	            System.out.println("These two files have same content");
	        }
	        else
	        {
	            System.out.println("Two files have different content. They differ at line " + lineNum);
	             
	            System.out.println("File1 has "+ line1 + " and File2 has " + line2 + " at line " + lineNum);
	        }
	        
	        reader.close();
	         
	        reader2.close();
	    }

}
