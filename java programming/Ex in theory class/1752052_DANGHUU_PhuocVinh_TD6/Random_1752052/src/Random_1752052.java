import java.util.Scanner;
import java.util.ArrayList;
import java.util.Random;



public class Random_1752052 {
	 static ArrayList<Integer> randomNumber() {
		int min, max;
		Random random = new Random();
		Scanner scanner = new Scanner(System.in);
		 
		System.out.println("Insert the number of numbers that you want to display: ");
		int number = scanner.nextInt();
		
		System.out.println("Insert your min number: ");
		min = scanner.nextInt();
		
		System.out.println("Insert your max number: ");
		max = scanner.nextInt();
		
		ArrayList<Integer> result = new ArrayList<Integer>();
		int index = 0;
		int value;
		boolean flag;
		
		while(index < number) {
			flag = false;
			value = min + random.nextInt((max - min) + 1);
			
			for(int i = 0; i < result.size(); i++){
				if(((Integer)result.get(i)).intValue() == value) {
				flag = true;
				break;
				}
			}
			
			if(!flag){
				result.add(value);
				index++;
			}
		}
		
		return result;
	}
	 
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		  
		System.out.println("Your result: " + randomNumber());
	}
}
