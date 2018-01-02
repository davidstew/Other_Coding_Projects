
public class InvalidTestScore extends Exception {
	
	InvalidTestScore(double score)
	{
		super(" with the value of " + score + " is not a valid test score");
	}

}
