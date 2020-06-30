import java.util.Scanner;

public class Palindrome_1752052 {
	static boolean isPalindrome(String sentence) {
        boolean flag = true;
        int temp = sentence.length() - 1;
        
        for (int i = 0; i < (sentence.length() / 2.0); i++) {
            if (sentence.charAt(i) != sentence.charAt(temp))
                flag = false;
            temp--;
        }
        return flag;
    }
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		while(true) {
		System.out.print("Insert your string to test: ");
		Scanner scanner = new Scanner(System.in);
		String sentence = scanner.nextLine();
	        if (isPalindrome(sentence))
	            System.out.println("This string is a palindrome");
	        else System.out.println("This string is not a alindrome");
	}
	}
}
