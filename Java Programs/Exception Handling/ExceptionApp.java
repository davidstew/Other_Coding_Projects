
import java.util.Scanner;


public class ExceptionApp {

	public static void main(String args[])
	{
	//create Scanner object for input
	Scanner keyboard = new Scanner(System.in);
	
	//create variables to hold information
	int input;
	double input1;
	double array[];
	
	//prompt user for size of array
	System.out.println("How many scores do you want to input and average?");
	input = keyboard.nextInt();
	
	//allocate size of array
	array = new double[input];
	
	//Run a loop to initialize array
	for (int i = 0; i < array.length; i++)
	{
		System.out.println("Enter test score # " + (i+1));
		input1 = keyboard.nextDouble();
		array[i] = input1;
	}
	
	//Create TestScores object
	TestScores object = new TestScores(array);
	
	//Test every element in array for validility
	for (int y = 0; y < array.length; y++)
	{
		try
		{
			//call method that checks element
			object.check_element(y);
		}
		
		/*For part 1 of program, catches system-defined IllegalArgumentException
		catch (IllegalArgumentException e)
		{
			System.out.println(" ");
			System.out.println("Invalid test score #" + (y + 1));
			System.out.println(e.getMessage());
		}
		*/
		
		//catch thrown exception and display the problem and corrected result
		//catches user-defined InvalidTestScore exception
		catch(InvalidTestScore e)
		{
			System.out.println(" ");
			System.out.println("Test Score number " + (y + 1) + e.getMessage());
			System.out.println("That value has been removed from the scores array and will not affect average score");
		}
	}
	
	//calculate average of scores
	object.calculate_average();
	
	//close keyboard object
	keyboard.close();
	}
		
}

