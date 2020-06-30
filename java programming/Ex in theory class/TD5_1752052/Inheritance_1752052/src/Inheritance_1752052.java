class Vehicle{
	private int passengers;
	private int fuelcap; 
	private int mpg;
	private String model;
	
	Vehicle() {
		passengers = 0;
		fuelcap = 0;
		mpg = 0;
	}

	// Return the range.
	int range() {
		return mpg * fuelcap;
	}

	// Compute fuel needed for a given distance.
	double fuelNeeded(int miles) {
		return (double) miles / mpg;
	}

	// Access methods for instance variables.
	int getPassengers() {
		return passengers;
	}

	void setPassengers(int p) {
		passengers = p;
	}

	int getFuelcap() {
		return fuelcap;
	}

	void setFuelcap(int f) {
		fuelcap = f;
	}

	int getMpg() {
		return mpg;
	}

	void setMpg(int m) {
		mpg = m;
	}
	
	String getModel() {
		return model;
	}
	
	void setModel(String mod){
		mod = model;
	}
	
	Vehicle(String model, int pass, int fuel, int mpg){
		this.passengers = pass;
		this.model = model;
		this.fuelcap = fuel;
		this.mpg = mpg;
	}
}

class Car extends Vehicle{
	private int color;
	private String owner;
	
	int getColor(){
		return color;
	}
	
	void setColor(int col) {
		col = color;
	}
	
	String getOwner() {
		return owner;
	}
	
	Car() {
		super();
		this.color = 0;
		this.owner = "";
	}
		Car(String mod, int pass, int fuel, int mpg, int col, String own) {
			super(mod, pass, fuel, mpg);
			this.color = col;
			this.owner = own;
		}
		
		
	
}

class Truck extends Vehicle{
	private int cargocap;
	
	Truck(){
		super();
		this.cargocap = 0;
	}
	Truck(String mod, int pass, int fuel, int mpg, int cargo) {
		super(mod, pass, fuel, mpg);
		this.cargocap = cargo;
	}

	int getCargocap() {
		return this.cargocap;
	}
	
	void setCargocap(int cargo) {
		this.cargocap = cargo;
	}
	
}
public class Inheritance_1752052 {
	public static void main(String[] args) {
		Vehicle vehicle = new Vehicle("cargo", 40, 40, 35);
		Car car = new Car("Ford", 7, 50, 35, 208, "John");
		Truck truck = new Truck("Mitsubishi", 3, 50, 100, 25);
		int miles = 200;
		System.out.println(car.fuelNeeded(miles));
		System.out.println(truck.getModel());
		System.out.println(vehicle.getPassengers());
		}

}
