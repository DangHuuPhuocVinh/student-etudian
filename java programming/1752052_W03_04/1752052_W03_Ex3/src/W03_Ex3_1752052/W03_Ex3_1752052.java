package W03_Ex3_1752052;
import java.util.Scanner;

public class W03_Ex3_1752052 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		InverseNumber inverse = new InverseNumber();
		while(true) {
		Scanner scanner = new Scanner(System.in);
		System.out.print("\nInsert your number to check: ");
		int number = scanner.nextInt();
		System.out.println("Your result: " + inverse.Inverse(number));
	}

	
}
}
