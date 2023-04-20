import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

public class Account {
     Dictionary account = new Hashtable();
     int Id = 1000;
    
     void addBA(String name, String address, String type, int money, String telephone, int trans){
        BankAccount bank = new BankAccount(name, address, type, money, telephone, trans);
        String id = "BA" + Integer.toString(Id);
        account.put(id, bank);
        Id++;
        System.out.print("Your account id is: " + id);
        System.out.println("Type your information");
    }

     BankAccount searchBA_Id(String id){
        Object obj;
        if(account.isEmpty()) {
            System.out.println("List of accounts are empty");
            return new BankAccount();
        }
        try{
            obj = account.get(id);
        }catch (NullPointerException exc) {
            System.out.println(exc);
            return new BankAccount();
        }
        return (BankAccount) obj;
    }

    BankAccount searchBA_Name(String name){
        if(account.isEmpty()) {
            System.out.println("List account is empty");
            return new BankAccount();
        }
        try{
            String temp = name;
        }catch (NullPointerException exc) {
            System.out.println(exc);
            return new BankAccount();
        }
        for(int i = 1000; i < Id; i++){
            String id = "BA"+Integer.toString(i);
            Object obj = account.get(id);
            BankAccount bank = (BankAccount) obj;
            
            if(bank.getName().compareToIgnoreCase(name) == 0){
                System.out.println("Bank account id: " + id);
                System.out.println(bank.toString());
                return bank;
            }
        }

        System.out.println("This user name does not exist");
        return new BankAccount();
    }

    BankAccount searchBA_TelePhone(String telephone){
        if(account.isEmpty()) {
            System.out.println("List account is empty");
            return new BankAccount();
        }
        try{
            String temp = telephone;
        }catch (NullPointerException exc) {
            System.out.println(exc);
            return new BankAccount();
        }
        for(int i = 1000; i < Id; i++){
            String id = "BA" + Integer.toString(i);
            BankAccount bank = searchBA_Id("id");
            
            if(bank.getTelephone().compareToIgnoreCase(telephone) == 0){
                System.out.println("Bank account id: " + id);
                System .out.println(bank.toString());
                return bank;
            }
        }

        System.out.println("This user name does not exist");
        return new BankAccount();
    }

    Dictionary getAcc(){
        return account;
    }

    Account[] readFile(String file) throws NumberFormatException, IOException {
		Account[] account = null;
        int i;
        BufferedReader readbuffer = new BufferedReader(new FileReader(file));
        int temp = Integer.parseInt(readbuffer.readLine());
        account = new Account[temp];
	    for(i = 0; i < temp; i++) {
	          String[] info = readbuffer.readLine().split("\t");
	          account[i] = new Account();
	          System.out.println(account[i]);
	       }
	        readbuffer.close();  
	        
        return account;
    }
    
    void saveFile(Account[] account_, String file) throws IOException {
        DataOutputStream output = null;
        
        output = new DataOutputStream(new FileOutputStream(file));
        output.writeInt(account_.length);
        BankAccount bac = new BankAccount();
        
        for (Account account : account_) {
            output.writeUTF(bac.getName());
           	output.writeUTF(bac.getTelephone());
           	output.writeUTF(bac.getAddress());
           	output.writeUTF(bac.getType());
           	output.writeInt(bac.getSolde());
           	output.writeInt(bac.getTrans());
          }
        output.close();
    }
	
	 void printFile(Account account, String file) throws IOException {
        int i;
		FileWriter fw = new FileWriter(file);
		Enumeration enu = account.elements();
		
        for(i = 0; i < account.size(); i++){
            fw.write(account.elements(i));
            fw.write("\n");
        }
        
        fw.close();
    }
}


