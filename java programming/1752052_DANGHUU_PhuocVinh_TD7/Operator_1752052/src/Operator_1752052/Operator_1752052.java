package Operator_1752052;



class Operator_1752052 {
	 void Operation(int a[], int b[], int Size)
	{
		int i = 0, j = 0;
		int [] Addition = new int[Size];
		int [] Subtraction = new int[Size];
		int [] Multiplication = new int[Size];
		int [] Division = new int[Size];
		
		
		while(i < Size)
			try{
		{
			Addition [i] = a[i] + b[i];
		    Subtraction [i] = a[i] - b[i];
		    
		    Multiplication [i] = a[i] * b[i];
		   
		    try {
		    Division [i] = a[i] / b[i];
		    }catch(ArithmeticException exc) {
		    	System.out.println("Can\'t divide by zero");
			}
		    i++;
		}
			}catch(ArrayIndexOutOfBoundsException exc) {
				System.out.println("No matching element found");
			} 
				
		System.out.println("\nAdd\t Sub\t Multi\t Div");
		
		while(j < Size )
		{
			System.out.print(Addition[j] + " \t ");
			System.out.print(Subtraction[j] + " \t ");
			System.out.print(Multiplication[j] + " \t ");
			try {
			System.out.print(Division[j] + " \t ");
			}catch(ArithmeticException exc) {
		    	System.out.println("Can\'t divide by zero");
			}
		    System.out.print("\n");
		    j++;
		}
	}
}
