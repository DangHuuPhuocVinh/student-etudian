
public class PowerOf2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int x = 1;
		System.out.println("2 to the 0 power is 1");
		for(int i = 1; i < 10; i++)
		{
			System.out.println("2 to the " + (i) + " power is: " + (x *= 2));
		}
	}
}
