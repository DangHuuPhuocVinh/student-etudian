import java.io.IOException;

public class Help {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		char ch;
		 
		System.out.println("Help on: ");
		System.out.println("\t" + "1. if");
		System.out.println("\t" + "2. switch");
		ch = (char)System.in.read();
		
		if(ch == '1') {
			System.out.println("The if:");
			System.out.println("\t if(condition) statement;");
			System.out.println("\t else statement;");
		}
		
		else if(ch == '2') {
			System.out.println("The switch: ");
			System.out.println("\t switch(expression){");
			System.out.println("\t\t case constant:");
			System.out.println("\t\t\t statement sequence");
			System.out.println("\t\t\t break;");
			System.out.println("\t\t //...");
			System.out.println("}");
		}
		
		
	}

}
