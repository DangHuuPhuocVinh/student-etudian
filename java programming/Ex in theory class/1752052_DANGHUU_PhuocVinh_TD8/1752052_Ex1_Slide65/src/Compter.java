import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

public class Compter {

	 public static void main(String[] args) throws IOException 
	    { 
	        File file = new File("C:\\Users\\Vinh\\Desktop\\phones.txt"); 
	        FileInputStream fileStream = new FileInputStream(file); 
	        InputStreamReader input = new InputStreamReader(fileStream); 
	        BufferedReader reader = new BufferedReader(input); 
	          
	        String line; 
	          
	         
	        int countWord = 0; 
	        int lineCount = 0; 
	       
	          
	      
	        while((line = reader.readLine()) != null) 
	        { 
	                String[] wordList = line.split("\\s+"); 
	                countWord += wordList.length; 
	                String[] sentenceList = line.split("[!?.:]+"); 
	                lineCount += sentenceList.length; 
	        } 
	          
	        System.out.println("Total word count is: " + countWord); 
	        System.out.println("Total number of lines is: " + lineCount); 
	        
	    } 

}
