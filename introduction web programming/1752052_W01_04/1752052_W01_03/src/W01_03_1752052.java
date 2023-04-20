import java.io.IOException;
import java.util.Scanner;

class Calculate{
	 int BinaryToDecimal(int binary){  
		    int decimal = 0;  
		    int n = 0;  
		    while(true){  
		      if(binary == 0){  
		        break;  
		      } 
		      else {  
		          int temp = binary % 10;  
		          decimal += temp*Math.pow(2, n);  
		          binary = binary/10;  
		          n++;  
		       }  
		    }  
		    return decimal; 
		    } 
	 
	 void menu() {
			System.out.println("\nWhich mode that you want to display ? Please choose");
			System.out.print("1. Sum\n");
			System.out.print("2. Subtract\n");
			System.out.print("3. Multiplication\n");
			System.out.print("4. Division\n");
			System.out.println("Your choice is: ");
		}
	 	
	 	String sum(int number1, int number2) {
			int total = number1 + number2;
			return convertBin(total);
			
		}
		
		String substract(int number1, int number2) {
			int total = number1 - number2;
			return convertBin(total);
		}
		
		String multi(int number1, int number2) {
			int total = number1 * number2;
			return convertBin(total);
		}
		
		String division(int number1, int number2) {
			int total = number1 / number2;
			return convertBin(total);
		}
		
		void choice(char choiceOfUser, int number1, int number2) {
			switch(choiceOfUser) {
			case '1': 
				System.out.println("\nYour sum is: " + sum(number1, number2));
				break;
			case '2':
				System.out.println("\nYour subtract is: " + substract(number1, number2));
				break;
			case '3':
				System.out.println("\nYour multiplication is: " + multi(number1, number2));
				break;
			case '4': 
				System.out.println("\nYour division is: " + division(number1, number2));
				break;
			}
		}
		
		boolean isValid(char choiceOfUser) {
			if( choiceOfUser == '1' || choiceOfUser == '2' || choiceOfUser == '3' || choiceOfUser == '4') 
				return true;
			return false;
		}
		
		String convertBin(int number) {
			return Integer.toBinaryString(number);
		}	
}

public class W01_03_1752052 {
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		
		Calculate cal = new Calculate();
		int bin1, bin2, term1, term2; // bin is binary
		char choiceOfUser;
		Scanner number;
		
		do {
		System.out.println("\nPlease insert your binary number: ");
		System.out.println("First binary number: ");
		number = new Scanner(System.in);
		bin1 = number.nextInt();

	
		System.out.println("Second binary number: ");
		number = new Scanner(System.in);
		bin2 = number.nextInt();
		
		term1 = cal.BinaryToDecimal(bin1);
		term2 = cal.BinaryToDecimal(bin2);
		
		cal.menu();
		choiceOfUser = (char)System.in.read();
		if(cal.isValid(choiceOfUser) == true) {
			cal.choice(choiceOfUser, term1, term2);
		}
		else
			System.out.println("Sorry, we don't have that choice. Please try again.");
		
		}while(true);
		
	
	}

}

