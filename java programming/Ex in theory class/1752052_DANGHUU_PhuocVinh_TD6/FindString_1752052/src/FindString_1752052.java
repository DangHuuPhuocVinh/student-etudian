import java.util.Set;
import java.util.HashSet;
import java.util.Scanner;

public class FindString_1752052 {
	public static void allInterleavings(String result, String sentence1, String sentence2, Set < String > out) {
		  if (sentence1.length() == 0 && sentence2.length() == 0) {
		   out.add(result);
		   return;
		  }
		  
		  if (sentence1.length() > 0) {
		   allInterleavings(result + sentence1.charAt(0), sentence1.substring(1), sentence2, out);
		  }
		  
		  if (sentence2.length() > 0) {
		   allInterleavings(result + sentence2.charAt(0), sentence1, sentence2.substring(1), out);
		  }
		 }
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		while(true) {
		System.out.print("\nInsert your first sentence: ");
		Scanner scanner = new Scanner(System.in);
		String sentence1 = scanner.nextLine();
		
		System.out.print("Insert your second sentence: ");
		String sentence2 = scanner.nextLine();
		
		  System.out.println("\nThe given strings are: " + sentence1 + "  " + sentence2);
		  System.out.println("The interleavings strings are: ");
		  
		  Set < String > out = new HashSet < > ();
		  allInterleavings("", sentence1, sentence2, out);

		  out.stream().forEach(System.out::println);
		}
	}

}
