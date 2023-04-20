import java.io.IOException;

public class W01_01_1752052 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		char print, ignore;
		
		do {
		System.out.println("Press p to print the face");
		print = (char)System.in.read();
		do { ignore = (char)System.in.read();
			}while(ignore != '\n');
		}while(print != 'p');
		
		if(print == 'p') {
			System.out.println("\n  +\" \" \" \" \"+  ");
			System.out.println(" [|  o   o  |]");
			System.out.println("  |    ^    | ");
			System.out.println("  |  \' - \'  | ");
			System.out.println("  +\" \" \" \" \"+  ");
		}
	}

}
