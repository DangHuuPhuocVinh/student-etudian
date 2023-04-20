
public class LogicalOpTable {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		boolean p = true;
		boolean q = false;
		
		System.out.println("P\t" + "Q\t" + "AND\t" + "OR\t" + "XOR\t" + "NOT");
		System.out.println("1\t" + "1\t" + (1&1) + "\t" + (1|1) + "\t" + (1^1) + "\t" + (1-1));
		System.out.println("1\t" + "0\t" + (1&0) + "\t" + (1|0) + "\t" + (1^0) + "\t" + (1-1));
		System.out.println("0\t" + "1\t" + (0&1) + "\t" + (0|1) + "\t" + (0^1) + "\t" + (1-0));
		System.out.println("0\t" + "0\t" + (0&0) + "\t" + (0|0) + "\t" + (0^0) + "\t" + (1-0));
		
		System.out.println("");
		
		System.out.println("P\t" + "Q\t" + "AND\t" + "OR\t" + "XOR\t" + "NOT");
		System.out.println("true\t" + "true\t" + (p&p) + "\t" + (p|p) + "\t" + (p^p) + "\t" + (!p));
		System.out.println("true\t" + "false\t" + (p&q) + "\t" + (p|q) + "\t" + (p^q) + "\t" + (!p));
		System.out.println("false\t" + "true\t" + (q&p) + "\t" + (q|p) + "\t" + (q^p) + "\t" + (!q));
		System.out.println("false\t" + "false\t" + (q&q) + "\t" + (q|q) + "\t" + (q^q) + "\t" + (!q));
	}

}
