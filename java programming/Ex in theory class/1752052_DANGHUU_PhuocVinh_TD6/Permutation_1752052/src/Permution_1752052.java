import java.util.Arrays;
import java.util.Scanner;

public class Permution_1752052 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		  int n1, n2;
		    Scanner scanner = new Scanner(System.in);
		         
		    do {
		        System.out.println("Insert the long of the array 1: ");
		        n1 = scanner.nextInt();
		    } while (n1 < 0);
		         
		    
		    int array1[] = new int[n1];
		         
		    System.out.println("Insert the element of the array 1: ");
		    for (int i = 0; i < n1; i++) {
		        System.out.print("Insert the element " + i + ": ");
		        array1[i] = scanner.nextInt();
		    }
		    
		    do {
		        System.out.println("\nInsert the long of the array 2: ");
		        n2 = scanner.nextInt();
		    } while (n2 < 0);
		         
		    
		    int array2[] = new int[n2];
		         
		    System.out.println("Insert the element of the array 2: ");
		    for (int i = 0; i < n2; i++) {
		        System.out.print("Insert the element " + i + ": ");
		        array2[i] = scanner.nextInt();
		    }
		    
		    System.out.println("\nArray 1: ");
		    for (int i = 0; i < n1; i++) {
		        System.out.print(array1[i] + " ");
		    }
		    
		    System.out.println("\nArray 2: ");
		    for (int i = 0; i < n2; i++) {
		        System.out.print(array2[i] + " ");
		    }
		    
		    Arrays.sort(array1);
		    Arrays.sort(array2);
		    
		    if (array1.length != array2.length)
		    	System.out.println("\nTwo arrays aren't permutation");
		    else if(Arrays.equals(array1, array2))
		    	System.out.println("\nTwo arrays are permutation");
		    	
	}

}
