
public class Ship {
	
	//private fields that hold Ship's name and year 
	private String name;
	private String year;
	
	//Super class constructor initializes it's name and field attributes
	Ship(String name, String year)
	{
		this.name = name;
		this.year = year;
	}
	
	//accessor method to return Ships name
	public String getName()
	{
		return name;
	}

	//accessor method to return Ships name, cannot be overridden
	public final String getYear()
	{
		return year;
	}
	
	//toString method to print results
	public String toString()
	{
		String str = " The ships name is: " + this.getName() +
		"\n The ships year is: " + this.getYear() + " \n";
		return str;
	}
	
	

}
