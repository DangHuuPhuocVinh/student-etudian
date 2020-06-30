import java.util.Scanner;

public class Palindromic_1752052 {
	static void printSubStr(String sentence1, int l, int h) {
		  System.out.println(sentence1.substring(l, h + 1));
		 }

		 static int PalindromicSubstr(String sentence) {
		  int n = sentence.length();
		  boolean table[][] = new boolean[n][n];
		  int Length = 1;
		  for (int i = 0; i < n; ++i)
		   table[i][i] = true;
		  
		  int strt = 0;
		  for (int i = 0; i < n - 1; ++i) {
		   if (sentence.charAt(i) == sentence.charAt(i + 1)) {
		    table[i][i + 1] = true;
		    strt = i;
		    Length = 2;
		   }
		  }
		  
		  for (int k = 3; k <= n; ++k) {
		   for (int i = 0; i < n - k + 1; ++i) {
		    int j = i + k - 1;
		    if (table[i + 1][j - 1] && sentence.charAt(i) == sentence.charAt(j)) {
		     table[i][j] = true;

		     if (k > Length) {
		      strt = i;
		      Length = k;
		     }
		    }
		   }
		  }
		  System.out.print("The longest palindrome substring is; ");
		  printSubStr(sentence, strt, strt + Length - 1);
		  return Length;
		 }
		 
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		while(true) {
		System.out.print("Insert your string to test: ");
		Scanner scanner = new Scanner(System.in);
		String sentence = scanner.nextLine();
		  System.out.println("The given string is: " + sentence);
		  System.out.println("The length of the palindromic substring is: " + PalindromicSubstr(sentence));
		 }
		}
}
