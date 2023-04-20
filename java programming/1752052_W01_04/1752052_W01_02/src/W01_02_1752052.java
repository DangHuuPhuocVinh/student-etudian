import java.io.IOException;
import java.util.Scanner;

class Convert {
	void menu() {
		System.out.println("Which mode that you want to display ? Please choose");
		System.out.print("1. Convert to binary\n");
		System.out.print("2. Convert to octal\n");
		System.out.print("3. Convert to hexadecimal\n");
		System.out.print("4. Convert to all above\n");
		System.out.print("Choose q to quit\n");
		System.out.println("Your choice is: ");
	}
	
	void choice(char choice, int number) {
		switch(choice) {
		case '1': 
			System.out.println("\nYour binary number is: " + convertBin(number));
			break;
		case '2':
			System.out.println("\nYour octal number is: " + convertOct(number));
			break;
		case '3':
			System.out.println("\nYour hexadecimal number is: " + convertHex(number));
			break;
		case '4': 
			System.out.println("\nYour binary number is: " + convertBin(number));
			System.out.println("Your octal number is: " + convertOct(number));
			System.out.println("Your hexadecimal number is: " + convertHex(number));
			break;
		case 'q':
			System.out.println("\nGood bye, see you later");
		}
	}
	
	boolean isValid(char choice) {
		if( choice == '1' || choice == '2' || choice == '3' || choice == '4' || choice == 'q') 
			return true;
		return false;
	}
	
	String convertHex(int number) {
		return Integer.toHexString(number);
	}
	
	String convertOct(int number) {
		return Integer.toOctalString(number);
	}
	
	String convertBin(int number) {
		return Integer.toBinaryString(number);
		
	}	

}


public class W01_02_1752052 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		 
		int dec;
		Scanner number;
		char choiceOfUser;
		Convert convert = new Convert();
		do {
		System.out.println("\nPlease insert your decimal number: ");
		number = new Scanner(System.in);
		dec = number.nextInt();
		
		convert.menu();
		choiceOfUser = (char)System.in.read();
	
		if(convert.isValid(choiceOfUser) == true)
			convert.choice(choiceOfUser, dec);
		else
			System.out.println("Sorry, we don't have that choice. Please try again.");
		}while(choiceOfUser != 'q');	
	}
}  






