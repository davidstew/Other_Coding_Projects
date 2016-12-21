import javax.swing.*;

//subclass inheriting from JPanel
public class GallonsCapacityPanel extends JPanel {
	
	private JTextField input;  //JTextField object to hold input from user
	private JLabel messageLabel; //JLabel used to prompt user
	
	GallonsCapacityPanel()
	{
		//Call JLabel constructor, creates JLabel object to prompt user	
		messageLabel = new JLabel("How many gallons of gas can your car hold?");
		
		input = new JTextField(10); //input references JTextFiled object used for input
		
		add(messageLabel); //add JLabel to panel
		add(input); //add JTextField to panel
	}
	
	public JTextField input() //accessor method
	{
		return input; //return reference to user's input
	}
}
