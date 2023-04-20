package W03_Ex6_1752052;

class Triangle extends MyPoint {
	private MyPoint x, y;
	private MyPoint z;
	private String type;
	
	Triangle() {
		super();
		type = "Not a triangle";
	}
	
	Triangle(double x, double y, MyPoint z) {
		super(x, y);
		this.z = z;
		this.whichType();
	}
	
	Triangle(double x1, double y1, double x2, double y2, double x3, double y3) {
		x = new MyPoint(x1,y1);
		y = new MyPoint(x2,y2);
		z = new MyPoint(x3,y3);
		this.whichType();
	}
	
	void printTriangle(double x1, double x2, double x3, double y1, double y2, double y3) {
		
		x = new MyPoint(x1,y1);
		y = new MyPoint(x2,y2);
		z = new MyPoint(x3,y3);
		this.whichType();
		
		System.out.print("First point is: ");
		x.printPoint();
		
		System.out.print("\nSecond point is: ");
		y.printPoint();
		
		System.out.print("\nThird point is: ");
		z.printPoint();
		
		System.out.print("\nTriangle type is: " + type);
	}
	
	String getType() {
		return this.type;
	}
	
	boolean isEqual(double xy, double yz, double xz) {
		if(xy == yz && yz == xz && xy == xz)
			return true;
		else
			return false;
	}
	
	boolean isIsosceles(double xy, double yz, double xz) {
		if(xy == yz || yz == xz || xy == xz)
			return true;
		else
			return false;
	}
	
	boolean isRectangle(double xy, double yz, double xz) {
		double xyz = Math.sqrt(Math.pow((xy + yz), 2.0));
		double xzy = Math.sqrt(Math.pow((xz + yz), 2.0));
		double yxz = Math.sqrt(Math.pow((xy + xz), 2.0));
		
		if(xyz == xz || xzy == xy || yxz == yz )
			return true;
		else
			return false;
	}
	
	boolean isSameLine() {
		double xy = x.distance(y); // point a
		double yz = y.distance(z); // point b
		double xz = x.distance(z); // point c
		double nuaChuVi = (xy + yz + xz) / 2;
		double ChieuCao = 2 * (Math.sqrt(nuaChuVi * (nuaChuVi - xy) * (nuaChuVi - yz) * (nuaChuVi - xz)) / xy);
		double xYz = Math.toDegrees(Math.asin( ChieuCao / xy));
		
		System.out.println("Degrees of vertex X: " + xYz);
		
		if(Math.abs(xYz) == 180.0 || Math.abs(xYz) == 360.0 || xYz == 0.0)
			return true;
		else
			return false;
	}
	
	void whichType() {
		if(this.isSameLine()) {
			this.type = "It's not a triangle";
		}
		else 
		{
			this.type = "It's a normal triangle";
			
			double xy = x.distance(y);
			double yz = y.distance(z);
			double xz = x.distance(z);

			if(this.isIsosceles(xy, yz, xz))
				this.type = "Isosceles triangle";
			if(this.isRectangle(xy, yz, xz))
				if(this.isIsosceles(xy, yz, xz))
					this.type = "Rectangles Isosceles triangle";
				else
					this.type = "Rectangles triangle";
			if(this.isEqual(xy, yz, xz))
				this.type = "Equilateral triangle";
		}
	}
}
