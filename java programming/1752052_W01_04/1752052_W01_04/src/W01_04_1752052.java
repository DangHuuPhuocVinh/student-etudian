import java.util.Scanner;

class Rot13 {
	char convert(char word) {
		char newWord = '0';
		
		if((int)word >= 110 && (int)word <= 122 || (int)word >= 78 && (int)word <= 90)
			newWord = (char)((int)word - 13);
		if((int)word >90 && (int)word < 110 || (int)word < 78)
			newWord = (char)((int)word + 13);
		
		return newWord;
	}
	
	boolean isValid(char word) {
		if((int)word < 65 || (int)word > 90 && (int)word < 97 || (int)word > 122)
			return false;
		return true;
	}
}

public class W01_04_1752052 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String sentence;
		Rot13 rot13 = new Rot13();
		Scanner w = new Scanner(System.in); // w is word
		
		while(true){

			System.out.print("\nPlease insert your word or sentence (press q to quit): ");
			sentence = w.nextLine();
			
			
			System.out.print("\nYour Rot13 is: ");
			
			for(int i = 0; i < sentence.length(); i++) {
				if(rot13.isValid(sentence.charAt(i))) 
					System.out.print(rot13.convert(sentence.charAt(i)));
				else
					System.out.print(sentence.charAt(i));
				}
			
			System.out.println("");
			
			if(sentence.contentEquals("q") == true) {
				System.out.print("\nGood bye, see you later");
				break;
			}
		}
	}
}


