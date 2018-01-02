
public class CargoShip extends Ship {
	//private field that holds max passengers
	private int cargo_capacity;
	
	//constructor calls superclass constructor first, then initializes it's own private field
	CargoShip(Ship arg, int num)
	{
		super(arg.getName(),arg.getYear()); //superclass constructor with parameters from ship object arg
		cargo_capacity = num;
	}
	
	//overrides the Ship's toString method to print results
	public String toString()
	{
		String str = " The ships name is: " + this.getName() + 
				"\n The cargo capacity in tonnages is: " + this.getCargo() + " \n";
		return str;
	}
	
	//accessor method returning value of cargo_capacity, cannot be overridden
	public final int getCargo()
	{
		return cargo_capacity;
	}
	
	
}
