package W03_1752052;

public class W03_Ex5_1752052 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MyDate mydate1 = new MyDate(2, 3, 1996);
		MyDate mydate2 = new MyDate(4, 5, 2010);
		mydate1.isValid();
		mydate2.isValid();
		if(mydate1.Compare(mydate2) == 1) 
			System.out.println("First date is bigger than second date");
		if(mydate1.Compare(mydate2) == -1) 
			System.out.println("First date is less than second date");
		if(mydate1.Compare(mydate2) == 0) 
			System.out.println("First date is equai second date");
		System.out.println("\nDistance is: " + mydate1.calculateDistance(mydate2) + " days");
		System.out.println(mydate1.toString());
		System.out.println(mydate2.toString());
		System.out.println(mydate1.toString(2));
		System.out.println(mydate2.toString(2));
	
	
		
	}

}
