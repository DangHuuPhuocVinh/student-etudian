package W03_Ex6_1752052;

class MyPoint {
	private double x;
	private double y;
	
	MyPoint() {
		x = y = 0.0;
	}
	
	MyPoint(double x, double y) {
		this.x = x;
		this.y = y;
	}
	
	void printPoint() {
		System.out.print("x is: " + this.x + " and y is: " + this.y);
	}
	
	double getX() {
		return this.x;
	}
	
	double getY() {
		return this.y;
	}
	
	double distance(MyPoint p) {
		double result = Math.sqrt(Math.pow((p.getX() - this.x),2.0) + Math.pow((p.getY() - this.y), 2.0));
		return result;
	}
}
