import java.util.Scanner;

class Student { 
	private String studentId;
	private String fullName;
	private String dateOfBirth;
	Student(){
		studentId = "";
		fullName = "";
		dateOfBirth = "";
	}
	
	Student(String studentId, String fullName, String dateOfBirth){
		this.studentId = studentId ;
		this.fullName = fullName ;
		this.dateOfBirth = dateOfBirth;
	}
	
	String getStudentId() {
		return studentId;
	}
	
	String getFullName() {
		return fullName;
	}
	
	String getDateOfBirth() {
		return dateOfBirth;
	}

    static int Students = 0; 
    { 
        Students += 1; 
    } 
}

public class Student_1752052 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
//		String  fullName, dateOfBirth;
		while(true) {
		System.out.print("Please insert student ID: ");
		Scanner stuId = new Scanner(System.in);
	    String studentId = stuId.nextLine();
	    
		System.out.print("Please insert full name: ");
		Scanner full = new Scanner(System.in);
		String fullName = full.nextLine();
		
		System.out.print("Please insert date of birth: ");
		Scanner date = new Scanner(System.in);
		String dateOfBirth = date.nextLine();
		
		Student student = new Student(studentId, fullName, dateOfBirth);
		
		System.out.println("\nStudent ID is: " + student.getStudentId());
		System.out.println("Fullname is: " + student.getFullName());
		System.out.println("Date of birth is: " + student.getDateOfBirth());
		System.out.println("\nThe number of students in class are: " + student.Students + "\n");
		}

	}

}
