import java.util.ArrayList;
import java.util.Scanner;

//class for prince
class Prince{
	long Money;
	long IQ;
	long Power;
	Scanner number;
	void Input(){
		System.out.print( "Money: \n");
		number = new Scanner(System.in);
		Money = number.nextInt();
		
		System.out.print("Power : \n"); 
		number = new Scanner(System.in);
		Power = number.nextInt();
		
		System.out.print("IQ: \n"); 
		number = new Scanner(System.in);
		IQ = number.nextInt();
	}
	
	void Output() {
		System.out.println("Your money have: " + (Money));
		System.out.println("Your power have: " + (Power));
		System.out.println("Your iq have: " + (IQ));
	}
	
	boolean comparePower(long power) {
		if(this.Power > power)
			return true;
		return false;
	}
	
	long adjustMoney(long money) {
		return this.Money += money;
	}
	
	boolean compareMoney(long money) {
		if(this.Money > money)
			return true;
		return false;
	}
	
	boolean compareIQ(long iq) {
		if(this.IQ > iq)
			return true;
		return false;
	}
	
	long adjustPower(long power) {
		return this.Power += power;
	}
}

//class gates
abstract class Gate{
	abstract void Input();
	abstract long passGate(Prince prince);
}

class businessGate extends Gate{
	private long quantity;
	private long unit_price;
	Scanner number;
	
	void Input(){
		System.out.println("Insert quantity : ");
		number = new Scanner(System.in);
		quantity = number.nextInt();
		
		System.out.println("Insert unit price: ");
		number = new Scanner(System.in);
		unit_price = number.nextInt();
	}
	
	long passGate(Prince prince) {
		if(prince.compareMoney(this.unit_price * this.quantity)) 
			return 1;
		return 0;
	}
}

class academicGate extends Gate{
	private long iq;
	Scanner number;
	
	void Input(){
		System.out.println("insert IQ: ");
		number = new Scanner(System.in);
		iq = number.nextInt();
	}

	long passGate(Prince prince) {
		if(prince.compareIQ(this.iq)) 
			return 1;
		return 0;
	}
}

class powerGate extends Gate{
	private long power;
	Scanner number;
	void Input(){
		System.out.println("Power is: ");
		number = new Scanner(System.in);
		power = number.nextInt();
	}

	long passGate(Prince prince) {
		if (prince.comparePower(this.power))
			return 1;
		return 0;
	}
}

//To rescue the princess or die
class Rescue{
	ArrayList<Gate> arr = new ArrayList<Gate>();
	
	void Input(){
		int temp;
		
		System.out.println("Insert number of turns of gate: ");
		Scanner number;
		number = new Scanner(System.in);
		temp = number.nextInt();
		System.out.println("The number of turns of gate: " + temp);
		
		Gate gate;
		for (int i = 0; i <= temp; i++)
		{
			gate = null;
		
			if (temp == 1) 
			{
				gate = new businessGate();
				gate.Input();
			}
			else if (temp == 2) 
			{
				gate = new academicGate();
				gate.Input();
			}
			else
			{
				gate = new powerGate();
				gate.Input();
			}
			System.out.println("Gate's information: " + (i + 1));
			gate.Input();
			this.arr.add(gate);
		}
	}

	int rescuePrincess(Prince prince) {
		int flag = 1;
		int i;
	
		for (i = 0; i < this.arr.size(); i++)
		{
			if (((Gate) this.arr.get(i)).passGate(prince) == 0) 
				flag = 0;
		}
		return flag;
	}
}
	
public class W02_01_1752052 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//srand((int)time(0));
		Prince prince = new Prince();
		Rescue res = new Rescue();
		prince.Input();
		prince.Output();
		System.out.println("\nPress 1 to go to business gate, 2 to go to academic gate and other for the power one");
		res.Input();
		
		if (res.rescuePrincess(prince) == 1)
			System.out.println("Rescued the princess. Congratulations !");
		else 
			System.out.println("The prince died. Haha !!!");		
	}
}
