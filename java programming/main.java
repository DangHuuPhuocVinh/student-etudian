import java.util.Scanner;

public class main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BankAccount bank = new BankAccount();
		BankAccount bank1 = new BankAccount("abc", "nchh", "nhcd", 200000, "0142536014", 12);
		BankAccount bank2 = new BankAccount("dfe", "nddeh", "nedd", 500000, "0526536", 55);
		BankAccount bank3 = new BankAccount("nhdehd", "cee", "nhcd", 800000, "0805040201", 20);
		Scanner scanner = new Scanner(System.in);
	
		System.out.print("Insert name of account: ");
		String name = scanner.nextLine();
		
		System.out.print("Insert address of account: ");
		String address = scanner.nextLine();
		
		System.out.print("Insert telephone number: ");
		String tele = scanner.nextLine();
		
		System.out.print("Insert type of account: ");
		String type = scanner.nextLine();
		
		System.out.print("Insert account balance: ");
		int solde = scanner.nextInt();
		
		System.out.print("Insert number of transaction: ");
		int trans = scanner.nextInt();
		
		bank.Display(name, address, type, solde, tele, trans);
		
		
		System.out.print("Insert new deposit which you want to add: ");
		int deposit = scanner.nextInt();
		int result1 = bank.Deposer(deposit);
		
		System.out.print("New account balance: " + result1 );
		System.out.print("\nInsert money which you want to withdraw: ");
		int money = scanner.nextInt();
		
		if(bank.isValid(result1, money) == true) {
			System.out.println("Can\'t make");
		}
		else
		{
			System.out.print("New account balance: " + bank.Retirer(result1, money));
		}
		
	}

}
