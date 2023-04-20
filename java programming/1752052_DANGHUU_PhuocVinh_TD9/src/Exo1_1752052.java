import java.util.Scanner;


class Divisor
{ 
	void findDivisor(int number) 
    { 
        for (int i = 1; i <= number; i++) 
            if (number % i == 0) 
                System.out.printf("%d ", i); 
    } 
}

public class Exo1_1752052 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		while(true) {
		 Divisor divisor = new Divisor();
		 Scanner scanner = new Scanner(System.in);
		 System.out.print("\nInsert your number: ");
		 int number = scanner.nextInt();
		 System.out.println("The divisors of " + number + " are: "); 
	     divisor.findDivisor(number);
		}	
	}

}
