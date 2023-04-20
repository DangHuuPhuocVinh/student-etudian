import java.util.Scanner;

class Combination{
	
	public long Factorial(int n){

        long result = 1;
        int i;
        
        for(i = 2; i <= n; i++)
        {
           result *= i;
        }
        
        return result;
   }
	
	public long calculateCombination(int n,int k){

	        return Factorial(n) / ( Factorial(n - k) * Factorial(k));

	    }
	
	boolean isValid(int n, int k) {
		if(n > k)
			return true;
		return false;
	}
}


public class W03_Ex1_1752052 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Combination combination = new Combination();
		//combination.Display();
		while(true) {
		System.out.println("\nThis is combination program with format c(n,k)");
		System.out.print("Please insert your n: ");
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		System.out.print("\nPlease insert your k: ");
		int k = scanner.nextInt();
		System.out.print("\nYour n: " + n + " and your k: " + k);
		
		if(combination.isValid(n, k) == true) {
			System.out.println("\nYour result: " + combination.calculateCombination(n, k));
		}
		else
			System.out.println("\nYour type is wrong, you have to insert n bigger than k");
		}
	}

}
