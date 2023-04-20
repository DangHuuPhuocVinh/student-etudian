package W03_Ex4_1752052;

import java.util.Scanner;

public class W03_Ex4_1752052 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Palindrome palindrome = new Palindrome();
		while(true) {
			System.out.print("Insert your string or number to test: ");
			Scanner scanner = new Scanner(System.in);
			String sentence = scanner.nextLine();
		        if (palindrome.isPalindrome(sentence))
		            System.out.println("This string/number is a palindrome");
		        else System.out.println("This string/number is not a palindrome");
		}
		
	}

}
