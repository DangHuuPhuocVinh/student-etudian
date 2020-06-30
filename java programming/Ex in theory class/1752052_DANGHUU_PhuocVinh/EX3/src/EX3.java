import java.util.Scanner;
import java.lang.Math;

public class EX3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		//Get number
		int n = 1;
		double[] sqrt_array = new double[101];
		
		while(n <= 100) {
			sqrt_array[n] = Math.sqrt(n); 
			n++;
		} 

		System.out.println("Square root array is: ");
		
		for(int j = 0; j <= 100; j++) {
			System.out.println(j + " square root: " + sqrt_array[j]);
		}
		
		System.out.println("Rounding error is square root 2 * square root 2: " + sqrt_array[2]*sqrt_array[2]);
		
	}
}