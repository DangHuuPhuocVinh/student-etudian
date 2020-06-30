package Operator_1752052;

import java.util.Scanner;
import java.util.InputMismatchException;

public class main_1752052 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int Size, i = 0, j = 0;
		Operator_1752052 operator = new Operator_1752052();
		Scanner scanner = new Scanner(System.in);
	 
		System.out.print(" Please insert number of elements in an array : ");
		Size = scanner.nextInt();	
		
		int a[] = new int[Size];
		int b[] = new int[Size];
	
		System.out.print(" Please Enter " + Size + " elements of an Array  : ");
		try {
		while(i < Size)
		{
			
			a[i] = scanner.nextInt();
			i++;
			
		}   
		
		}catch(Exception e) {
			System.out.println("Type Error ! Please insert number");
			scanner.next();
		}
		
		System.out.print(" Please Enter " + Size + " elements of an Array  : ");
		
		try {
		while(j < Size )
		{
			b[j] = scanner.nextInt();
			j++;
		}
		}catch(Exception e) {
			System.out.println("Type Error ! Please insert number");
			scanner.next();
		}
		
		operator.Operation(a, b, Size);
	}

}
