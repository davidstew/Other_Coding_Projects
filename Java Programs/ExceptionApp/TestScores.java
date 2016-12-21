
public class TestScores {
	//private field that holds scores
	private double scores_array[];
	
	//constructor that initializes private field
	TestScores(double scores[])
	{
		int x = scores.length;
		scores_array = new double[x]; //allocate memory for private array
		
		for (int num = 0; num < scores.length; num++)
			scores_array[num] = scores[num]; //copy values into private array
	}
	
	//calculates average with corrected input from any exceptions
	public void calculate_average() 
	{
		double total = 0.0;
		int subtract_scores = 0; //counts number of invalid scores
		
		for (int num = 0; num < scores_array.length; num++)
		{
			if (scores_array[num] == -1 )
			{
				subtract_scores++; //increase number of invalid scores
			}
		
		total += scores_array[num]; //accumulator variable
		}
		
		total += subtract_scores; //makes up elements that were equal to negative 1 in total
		
		double average = total / (scores_array.length - subtract_scores); //calculate average with corrected number of tests
		
		//display results
		System.out.println(" ");
		System.out.println("The average the test scores is : " + average);
	}
	
	/* For part 1 of the program
	public void check_element(int index) throws IllegalArgumentException
	{
		if (scores_array[index] < 0 || scores_array[index] > 100)
		{
			double holder = scores_array[index];
			scores_array[index] = -1;
			throw new IllegalArgumentException(" The score " + holder + " has been removed from the scores array and will not affect average score");
		}
	}
	*/
	
	//methods checks each element, throws exception if less than 0 or greater than 100
	public void check_element(int index)throws InvalidTestScore //method header
	{
		if (scores_array[index] < 0 || scores_array[index] > 100) // if statement that throws exception
		{
			InvalidTestScore e = new InvalidTestScore(scores_array[index]); //create InvalidTestScore object
			scores_array[index] = -1; //make value = -1
			throw e; //throw exception
		}
	}
}
