
public class CruiseShip extends Ship {
	//private field that holds max passengers
	private int max_passengers;
	
	//constructor calls superclass constructor first, then initializes it's own private field
	CruiseShip(Ship arg,int num)
	{
		super(arg.getName(),arg.getYear()); //superclass constructor with parameters from ship object arg
		max_passengers = num;
	}
	
	//overrides the Ship's toString method
	public String toString()
	{
		String str = " The ships name is: " + this.getName() + 
				"\n The maximum amount of passengers is: " + this.getPassengers() + " \n";
		return str;
	}
	
	//accessor method returning value of max_passengers, cannot be overridden
	public final int getPassengers()
	{
		return max_passengers;
	}	
}
