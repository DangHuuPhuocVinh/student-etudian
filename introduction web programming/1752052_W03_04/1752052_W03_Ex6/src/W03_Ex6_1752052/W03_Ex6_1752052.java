package W03_Ex6_1752052;

import java.util.Scanner;

public class W03_Ex6_1752052 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Triangle triangle = new Triangle();
		Scanner scanner = new Scanner(System.in);
		while(true) {
		System.out.println("\n\nInsert your x1: ");
		double x1 = scanner.nextDouble();
		
		System.out.println("Insert your x2: ");
		double x2 = scanner.nextDouble();
		
		System.out.println("Insert your x3: ");
		double x3 = scanner.nextDouble();
		
		System.out.println("Insert your y1: ");
		double y1 = scanner.nextDouble();
		
		System.out.println("Insert your y2: ");
		double y2 = scanner.nextDouble();
		
		System.out.println("Insert your y3: ");
		double y3 = scanner.nextDouble();
		
		triangle.printTriangle(x1, x2, x3, y1, y2, y3);
		}
	}

}
