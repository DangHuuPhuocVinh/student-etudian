import java.sql.Array;
import java.util.Scanner;

class Produit{
	int[][] Display(){
		 int row, column;
		    Scanner scanner = new Scanner(System.in);
		         
		    System.out.println("Insert the row of the array: ");
		    row = scanner.nextInt();
		     
		    System.out.println("Insert the column of the array: ");
		    column = scanner.nextInt(); 
		     
		    int array[][] = new int[row][column]; 
		         
		    System.out.println("Insert the element of the array: ");
		    for (int i = 0; i < row; i++) {
		        for(int j = 0; j < column; j++) {
		        	 System.out.print("Insert the element " + i + ", " + j + ": ");
				        array[i][j] = scanner.nextInt();
		        }
		    }
		   
		    System.out.println("\nYour matrix: ");
			for (int i = 0; i < row; i++) {
			       for (int j = 0; j < column; j++) {
			           System.out.print(array[i][j] + " ");
			     }
			     System.out.println("\n");   
			}
			
			return array;
	}
	

}	


public class Produit_1752052 {
	 static int[][] calMatrix(int[][] arr1, int[][] arr2, int row, int column) {
	        int temp[][] = new int[row][column];
	        for(int i = 0;i < row; i++)
	            for(int j = 0; j < column; j++)
	                temp[i][j]=0;
	        for (int i = 0; i < row; i++) {
	            for (int j = 0; j < column; j++) {
	                for(int k = 0; k < row ; k++) {
	                    temp[i][j] += arr1[i][k] * arr2[k][j];
	                }
	            }
	        }
	        return temp;
	    }
	 
	public static void main(String[] args) {
		// TODO Auto-generated method stub
			Scanner scanner = new Scanner(System.in);
			Produit produit = new Produit();
			
		 	int arr1[][] = produit.Display();
	        int arr2[][] = produit.Display();
	        
	        System.out.println("Insert the row of your array result: ");
	        int row = scanner.nextInt();
	        System.out.println("Insert the column of your array result: ");
		    int column = scanner.nextInt();
		    
	        int result[][] = new int[row][column];
	        result = calMatrix(arr1, arr2, row, column);
	        System.out.println("Your array result: \n");
	        for(int i = 0; i < row; i++){
	            for(int j = 0; j < column;j++)
	            {
	            	
	                System.out.print(result[i][j] +"\t");
	            }
	            System.out.println(" ");
	        }
	}

}


