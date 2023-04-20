import java.util.Scanner;

class Display{
	void change(String choiceOfUser) {
			switch(choiceOfUser) {
			case "1": 
				System.out.print("\nUn");
				break;
			case "2":
				System.out.println("\nDeux");
				break;
			case "3":
				System.out.println("\nTrois");
				break;
			case "4": 
				System.out.println("\nQuatre");
				break;
			case "5":
				System.out.println("\nCinq");
				break;
			case "6":
				System.out.println("\nSix");
				break;
			case "7":
				System.out.println("\nSept");
				break;
			case "8":
				System.out.println("\nHuit");
				break;
			case "9":
				System.out.println("\nNeuf");
				break;
			default:
				System.out.println("\nAutre");
				break;
			}
		
		}
	

}


public class W01_05_1752052 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String choiceOfUser;
		
		while(true) {
		Scanner s = new Scanner(System.in);
		Display display = new Display();
		System.out.println("\nPlease insert your number ( from 1 to 9): ");
		choiceOfUser = s.nextLine();
		display.change(choiceOfUser);
	
		}
	}

}
