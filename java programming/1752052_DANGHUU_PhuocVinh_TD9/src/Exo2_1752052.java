
class  Divisor2{
	void findDivisor(int number) 
    { 
        for (int i = 1; i <= number; i++) 
            if (number % i == 0) 
                System.out.printf("%d ", i); 
    } 
}

public class Exo2_1752052 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Divisor2 divisor2 = new Divisor2();

		
		              
	       int maxDivisors;  
	       int numMax;   
	       
	       maxDivisors = 1;  
	       numMax = 1;
	       
	       for ( int i = 2;  i <= 10000;  i++ ) {
	       
	           int div;  
	           int count;  
	           
	           count = 0;
	           
	           for ( div = 1;  div <= i;  div++ ) {  
	              if ( i % div == 0 )
	                 count++;
	           }
	           
	           if (count > maxDivisors) {
	              maxDivisors = count;
	              numMax = i;
	           }
	       
	       }
	       
	       System.out.println("The maximum number of divisors between 1 and 10000 is " + maxDivisors);
	       System.out.println("A number with " + maxDivisors + " divisors is " + numMax);
	       
	       System.out.println("The divisors of " + numMax + " are: ");
	       divisor2.findDivisor(numMax);
	   } 
	

}
