import java.io.*;
import java.util.StringTokenizer;
import java.util.ArrayList;

class Student {
	private int number;
	private String name;
	private String firstName;
	private double tp;
	private double td;
	private double finalNote;
	private double total;
	
	Student() {
		this.number = 0;
		this.name = "Name";
		this.firstName = "First name";
		this.tp = 0;
		this.td = 0;
		this.finalNote = 0;
		this.total = 0;
	}
	
	Student(int number, String name, String firstName, double tp, double td, double finalNote, double total) {
		this.number = number;
		this.name = name;
		this.firstName = firstName;
		this.tp = tp;
		this.td = td;
		this.finalNote = finalNote;
		this.total = total;
	}
	
	Student(Student student) {
		this.number = student.number;
		this.name = student.name;
		this.firstName = student.firstName;
		this.tp = student.tp;
		this.td = student.td;
		this.finalNote = student.finalNote;
		this.total = student.total;
	}
	
	void Output() {
		System.out.println("Student number is: " + this.number);
		System.out.println("Name is: " + this.name);
		System.out.println("First name is: " + this.firstName);
		System.out.println("TP Notes are: " + this.tp);
		System.out.println("TD Notes ares: " + this.td);
		System.out.println("Final Note is: " + this.finalNote);
		System.out.println("Total is: " + this.total);
	}
	
	String totalDisplay() {
		return this.firstName + " " + this.name + " " + this.total;
	}
	
	double Total() {
		return this.total = this.total + (this.td + this.tp + this.finalNote) / 3; 
	}
}

class StudentList {
	private ArrayList<Student> list;
	
	StudentList() {
		this.list = new ArrayList<Student>(); 
	}
	
	void Add(int number, String name, String firstName, double tp, double td, double finalNote, double total) {
		Student student = new Student(number, name, firstName, tp, td, finalNote, total);
		this.list.add(student);
	}
	
	void Output() {
		for(int i = 0; i < this.list.size(); i++) {
			this.list.get(i).Output();
		}
	}
	
	int getSize() {
		return this.list.size();
	}
	
	Student getIndex(int index) {
		return this.list.get(index);
	}
}
public class main {

	public static void main(String[] args) throws FileNotFoundException, IOException {
		// TODO Auto-generated method stub
		BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream("C:\\Users\\Vinh\\Desktop\\java_notes.txt"), "UTF8"));
				String string;
				StudentList stl = new StudentList();
				StringTokenizer str = new StringTokenizer(string, "\t", false);
				ArrayList<String> arrl = new ArrayList<String>();
				double td;
				double tp = Double.parseDouble(arrl.get(4));
				double finalNote = Double.parseDouble(arrl.get(5));
				double total;
				while( (string = reader.readLine()) != null ) {
					if(string.equals("STT	Ho	Ten	BTTL	BTTH	CuoiKy	TB")) 
						continue;
					while(str.hasMoreTokens()) {
						arrl.add(str.nextToken());
					}
					
					if(arrl.get(3).equals(null)) 
						td = 0;
					else 
						td = Double.parseDouble(arrl.get(3));
					
					if(arrl.size() == 7) 
						total = Double.parseDouble(arrl.get(6));
					else 
						total = 0;
					
					stl.Add(Integer.parseInt(arrl.get(0)), arrl.get(1), arrl.get(2), td, tp, finalNote, total);
				}
				
				stl.Output();
				
				FileWriter fw = new FileWriter("C:\\Users\\Vinh\\Desktop\\Output2.txt");
				
				for(int i = 0; i < stl.getSize(); i++) {
					stl.getIndex(i).Total();
					fw.write(stl.getIndex(i).totalDisplay());
					fw.write("\n");
				}
				fw.close();
	}

}
