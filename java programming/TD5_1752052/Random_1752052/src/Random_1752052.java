import java.util.Arrays;

class RandomNumber {
	
	double randomNumber() {
		return Math.random();
	}
	
	double randomNumber(double max) {
		return (Math.random() * (max + 1));
	}
	
	double randomNumber(double min, double max) {
		return (Math.random() * ((max - min) + 1) + min);
	}
	
	double[] randomNumber(int n) {
		double[] num_array = new double[n+1];
		for(int i = 0; i <= n; i++)
			{
				num_array[i] = Math.random();
			}
		
		return num_array;
	}
	
	double[] randomNumber(int n, double max) {
		double[] num_array = new double[n+1];
		for(int i = 0; i <= n; i++)
		{
			num_array[i] = ((Math.random() * (max + 1)));
		}
		return num_array;
	}
	
	 double[] randomNumber(int n, double min, double max) {
		double[] num_array = new double[n+1];
		for(int i = 0; i <= n; i++)
		{
			 num_array[i] = ((Math.random() * ((max - min) + 1)) + min);
		}
		return num_array;
	}
}

public class Random_1752052 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		RandomNumber random = new RandomNumber();
		double max = 50, min = 10;
		int n = 5;
		
		System.out.println(random.randomNumber());
		System.out.println(random.randomNumber(max));
		System.out.println(random.randomNumber(min, max));
		System.out.println(Arrays.toString(random.randomNumber(n)));
		System.out.println(Arrays.toString(random.randomNumber(n, max)));
		System.out.println(Arrays.toString(random.randomNumber(n, min, max)));
	}

}	
