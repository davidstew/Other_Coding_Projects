/*********************************************************************************************
Name: David Stewart
Course: CS125-01
Lab #: Lab Four
Submission Date: 7/11/16
Brief Description: This driver demonstrates the power of using a polymorphic array. Each objects 
toString method is called and information about each object will be printed. 
*********************************************************************************************/
public class PolymorphismApp {
	
	public static void main (String args[])
	{
	// Create array of superclass ship objects
	Ship [] array = new Ship[3];
	
	//Assuming CruiseShip IS A Ship and CargoShip IS A Ship, they all have the same names...
	
	//initialize first element as ship object calling it's constructor
	array[0] = new Ship("Flying Dutchman", "1990");
	//initialize second element as CargoShip object calling it's constructor
	array[1] = new CargoShip(array[0], 100);
	//initialize third element as CruiseShip object calling it's constructor
	array[2] = new CruiseShip(array[0], 15);
	
	//calls static method printResults
	printResults(array);
	}
	
	//implements polymorphic array
	private static void printResults(Ship input[])
	{
		//polymorphic array that calls each object's overridden toString method
		for (int num = 0; num < input.length; num++)
			System.out.println(input[num].toString());
		
	}
}
