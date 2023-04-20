
class BankAccount{
    String nomDuDeposant;
    String adresseDuDeposant;
    String typeDeCompte;
    int soldeEnCompte;
    String numeroDeTelephone;
    int nombreDeTransaction;

    BankAccount(){
        this.nomDuDeposant = "0";
        this.adresseDuDeposant = "0";
        this.typeDeCompte = "0";
        this.soldeEnCompte = 0;
        this.numeroDeTelephone = "0";
        this.nombreDeTransaction = 0;
    }

     BankAccount(String name, String address, String type, int solde, String number, int transaction){
        this.nomDuDeposant = name;
        this.adresseDuDeposant = address;
        this.typeDeCompte = type;
        this.soldeEnCompte = solde;
        this.numeroDeTelephone = number;
        this.nombreDeTransaction = transaction;
    }
    
     public BankAccount(BankAccount bank){
         this.nomDuDeposant = bank.nomDuDeposant;
         this.adresseDuDeposant = bank.adresseDuDeposant;
         this.numeroDeTelephone = bank.numeroDeTelephone;
         this.typeDeCompte = bank.typeDeCompte;
         this.soldeEnCompte = bank.soldeEnCompte;
         this.nombreDeTransaction = bank.nombreDeTransaction;
     }
     
     public String toString()
 	{
 		 String.valueOf(this.soldeEnCompte);
 		 String.valueOf(this.nombreDeTransaction);
 		 String output = "";
 		 
         output += ("Name: " + this.nomDuDeposant);
         output += ("\nAddress: " + this.adresseDuDeposant);
         output += ("\nBalance: " + this.soldeEnCompte);
         output += ("\nType: " + this.typeDeCompte);
         output += ("\nTelephone number: " + this.numeroDeTelephone);
         output += ("\nNumber of transactions: " + this.nombreDeTransaction);
         
         return output;
 	}
     
    void Display() {
    	System.out.println("Name of depositor: " + this.nomDuDeposant);
    	System.out.println("Address of depositor: " + this.adresseDuDeposant);
    	System.out.println("Type of account: " + this.typeDeCompte);
    	System.out.println("Account balance: " + this.soldeEnCompte);
    	System.out.println("Telephone number: " + this.numeroDeTelephone);
    	System.out.println("Number of transaction: " + this.nombreDeTransaction);	
    }
    
    void Display(String name, String address, String type, int solde, String number, int transaction ) {
    	System.out.println("Name of depositor: " + name);
    	System.out.println("Address of depositor: " + address);
    	System.out.println("Type of account: " + type);
    	System.out.println("Account balance: " + solde);
    	System.out.println("Telephone number: " + number);
    	System.out.println("Number of transaction: " + transaction);	
    }
    
    int Deposer(int deposit) {
    	return this.soldeEnCompte + deposit;
    }
    
    int Deposer(int deposit, int newDeposit) {
    	return deposit + newDeposit;
    }
    
    boolean isValid(int deposit) {
    	if(deposit > this.soldeEnCompte) 
    		return true;
    	return false;
    }
    
    boolean isValid(int deposit, int newDeposit) {
    	if(newDeposit > deposit) 
    		return true;
    	return false;
    }
    
    int Retirer(int deposit) {
    	return this.soldeEnCompte - deposit;
    }
    
    int Retirer(int deposit, int newDeposit) {
    	return deposit - newDeposit;
    	
    }
    
    void setName(String name) {
        try {
            this.nomDuDeposant = name;
        }catch(NullPointerException exc) {
            System.out.println("exception");
        }
    }
    
    void setAddress(String address) {
        try {
            this.adresseDuDeposant = address;
        }catch(NullPointerException exc) {
            System.out.println("exception");
        }
    }
    
    boolean setBalance(int balance) {
        if(balance < 0) {
            System.out.println("Balance must > 0");
            return false;
        }
        else if (balance < 50000) {
            System.out.println("Balance must > 50000");
            return false;
        }
        else {
            this.soldeEnCompte = balance;
            return true;
        }
    }
    
    boolean setTelephone(String telephone) {
        if(telephone.length() > 10){
            System.out.println("Your telephone number is invalid");
            return false;
        }
        try {
            this.numeroDeTelephone = telephone;
        }catch(NullPointerException exc) {
            System.out.println("exception");
            return false;
        }
        return true;
    }
    
    boolean setType(String type) {
        try {
            this.typeDeCompte = type;
        }catch(NullPointerException exc) {
            System.out.println("exception");
            return false;
        }
        return true;
    }
    
    String getName() {
        return this.nomDuDeposant;
    }

    String getTelephone() {
        return this.numeroDeTelephone;
    }
}
