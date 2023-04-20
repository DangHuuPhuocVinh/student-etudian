import java.io.IOException;

public class Helpv2 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		char ch;
		do {
			System.out.println("");
			System.out.println("Help on:");
			System.out.println("\t 1. if");
			System.out.println("\t 2. switch");
			System.out.println("\t 3. for");
			System.out.println("\t 4. while");
			System.out.println("\t 5. do...while");
			System.out.println("\t 6. break");
			System.out.println("\t 7. continue");
			System.out.println("Choose one(q to quit):");
			do {
				ch = (char)System.in.read();
			
				if(ch == '1'){
					System.out.println("the if:");
					System.out.println("\tif(condition)\tstatement;");
					System.out.println("\telse\tstatement;");
				}
				
				else if(ch == '2'){
					System.out.println("The switch: ");
					System.out.println("\tswitch(expression){");
					System.out.println("\t\tcase constant:");
					System.out.println("\t\t\tstatement sequence");
					System.out.println("\t\t\tbreak;");
					System.out.println("\t\t//...");
					System.out.println("}");
				}
				
				else if(ch == '3'){
					System.out.println("the for:");
					System.out.println("\tfor(init; condition; interation){");
					System.out.println("\t...tstatement;}");
				}
				
				else if(ch == '4'){
					System.out.println("the while:");
					System.out.println("\twhile(condition)\tstatement;");
				}
				
				else if(ch == '5'){
					System.out.println("the do...while:");
					System.out.println("\tdo{;");
					System.out.println("\t\tstatement;");
					System.out.println("\t}while (condition);");
				}
				
				else if(ch == '6'){
					System.out.println("break; (use break after the statement of switch or if to stop the condition)");
				}
				
				else if(ch == '7') {
					
				}
				
				else if(ch == 'q') {
					System.out.println()
					break;
				}
			}while(ch != '\n');
		}while(ch != 'q');
	}

}
