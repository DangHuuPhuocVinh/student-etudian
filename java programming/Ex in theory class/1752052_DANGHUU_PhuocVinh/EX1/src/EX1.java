import java.util.Scanner;

public class EX1 {

		public static void main(String[] args) {
			while(true) {
			//Get fullname
			System.out.println("What's your fullname?");
			String fullname = new Scanner(System.in).nextLine();
			
			//Get gender
			System.out.println("What's your gender?");
			String gender = new Scanner(System.in).nextLine();
			
			//Get birthday
			System.out.println("What's your birthday?");
			String birthday = new Scanner(System.in).nextLine();
			
			//Get address
			System.out.println("Which place do you live in ?");
			String address = new Scanner(System.in).nextLine();
			
			//Get bank account
			System.out.println("What's your bank account");
			String bank_account = new Scanner(System.in).nextLine();
			//Print
			System.out.println("User informations: ");
			System.out.println("User name: " + fullname);
			System.out.println("User gender: " + gender);
			System.out.println("User birthday: " + birthday);
			System.out.println("User addresse: " + address);
			System.out.println("User bank account: " + bank_account);
			System.out.println("");
			System.out.println("Next infomation");
			System.out.println("");
			}	
		}
}


