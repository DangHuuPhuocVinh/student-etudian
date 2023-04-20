import java.io.*;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.StringTokenizer;

class Contact {
	String firstName;
	String name;
	String telephone;
	
	Contact() {
		this.firstName = "First name";
		this.name = "Name";
		this.telephone = "Telephone number";
	}
	
	Contact(String firstName, String name, String telephone) {
		this.firstName = firstName;
		this.name = name;
		this.telephone = telephone;
	}
	
	void setFirstName(String firstName) {
		this.firstName = firstName;
	}
	
	void setName(String name) {
		this.name = name;
	}
	
	void setTelephone(String telephone) {
		this.telephone = telephone;
	}
	
	void Output() {
		System.out.println("First name: " + this.firstName);
		System.out.println("Name: " + this.name);
		System.out.println("Telephone number: " + this.telephone);
	}
	
}

class ContactList {
	
	 ArrayList<Contact> list;
	
	void Output() {
		for(int i = 0; i < this.list.size(); i++) {
			this.list.get(i).Output();
		}
	}
	
	ContactList() {
		this.list = new ArrayList<Contact>();
	}
	
	int getSize() {
		return this.list.size();
	}
	
	Contact getIndex(int i) {
		return this.list.get(i);
	}
	
	void Add(String firstName, String name, String telephone) {
		Contact contact = new Contact(firstName, name, telephone);
		this.list.add(contact);
	}
	
	void Adjust(int n, String firstName, String name, String telephone) {
		this.list.get(n).setFirstName(firstName);
		this.list.get(n).setName(name);
		this.list.get(n).setTelephone(telephone);
	}
	
	void Remove(String telephone) {
		for(int i = 0; i < this.list.size(); i++) {
			if(telephone.equals(list.get(i).getTelephone()) == true) {
				this.list.remove(i);
				return;
			}
		}
	}
	
	
}

public class main {
	public static void main(String[] args) throws FileNotFoundException, IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream("C:\\Users\\Vinh\\Desktop\\phones.txt"), "UTF8"));
			String string;
			ContactList list = new ContactList();
			
			while( (string = reader.readLine()) != null ) {
				if(string.equals("Ho	Ten	SoDT"))
					continue;
				
				StringTokenizer str = new StringTokenizer(string, "\t", false);
				ArrayList<String> arrl = new ArrayList<String>();
				
				while(str.hasMoreTokens()) {
					arrl.add(str.nextToken());
				}
				
				list.Add(arrl.get(1), arrl.get(0), arrl.get(2));
			}
			
			list.Output();
			list.Remove("0980123456");
			list.Adjust(1, "Vinh", "Vinhtiger", "123456");
		
			FileWriter fw = new FileWriter("C:\\Users\\Vinh\\Desktop\\result.txt");
			
			for(int i = 0; i < cl.GetSize(); i++) {
				fw.write(list.getIndex(i).toString());
				fw.write("\n");
			}
			fw.close();
	} 
}
