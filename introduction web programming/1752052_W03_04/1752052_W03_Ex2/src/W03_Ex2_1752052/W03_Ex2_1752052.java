package W03_Ex2_1752052;

import java.util.Scanner;

public class W03_Ex2_1752052 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		while(true) {
		PremierNumber premier = new PremierNumber();
		Scanner scanner = new Scanner(System.in);
		System.out.print("\nInsert your number to check: ");
		int number = scanner.nextInt();
		if(premier.Verifier(number) == true) {
			System.out.println("\nThis numbet is premier");
		}
		else
			System.out.println("\nThis numbet isn\'t premier");
	}
	}
}
