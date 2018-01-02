import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

//subclass inheriting from JPanel
public class MilagePanel extends JPanel{
		
private JTextField input; //JTextField object to hold input from user
private JLabel messageLabel; //JLabel used to prompt user
	
    MilagePanel()
	{
	//Call JLabel constructor, creates JLabel object to prompt user	
	messageLabel = new JLabel("How many miles can be driven on a full tank?");
			
	input = new JTextField(10); //input references JTextFiled object used for input
			
	add(messageLabel); //add JLabel to panel
	add(input); //add JTextField to panel
    }
	
	public JTextField input() //accessor method
	{
		return input; //return reference to user's input
	}

}