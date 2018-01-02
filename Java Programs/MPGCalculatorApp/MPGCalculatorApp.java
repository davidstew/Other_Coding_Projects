import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.text.DecimalFormat;

//Class inherits from JFrame, creating specialized window
public class MPGCalculatorApp extends JFrame {
	
	private final int WINDOW_WIDTH = 420; //width size in pixels for window
	private final int WINDOW_HEIGHT = 200; //height size in pixels for window
	private GallonsCapacityPanel panel1; //panel pertaining to Gallons information
	private MilagePanel panel2; //panel pertaining to milage information
	private JButton CalculateButton; //Button object used for calculating
	private JButton ExitButton; //Button object used for exiting
	
	//constructor, constructs the GUI
	MPGCalculatorApp()
	{
		super("Miles / Gallon Calculator"); //call superclass constructor to label window
		
		setLocationRelativeTo(null); //set window to appear in middle of screen
		
		setSize(WINDOW_WIDTH,WINDOW_HEIGHT); //set GUI window size
		
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); //Allow GUI to close
		
		setLayout(new FlowLayout(FlowLayout.LEFT)); //Using FlowLayout for objects placed in window
		
		 panel1 = new GallonsCapacityPanel(); //construct panel1
		
		 panel2 = new MilagePanel(); //construct panel2
		 
		 panel1.setBorder(BorderFactory.createLineBorder(Color.BLUE,2)); //give panel1 blue border
		 panel1.setBackground(Color.GREEN); //set panel1 background to green

		 panel2.setBorder(BorderFactory.createLineBorder(Color.YELLOW,2)); //give panel2 yellow border
		 panel2.setBackground(Color.RED); //set panel2 background to red
		
		add(panel1); //add pane1 to window pane
		
		add(panel2); //add pane2 to window pane
		
		makeButtons(); //function call to make buttons
		
		this.getContentPane().setBackground(Color.BLACK); //set background color of window pane

		setVisible(true); //make the window visible
		
		
	}
	
	//method used to make buttons
	private void makeButtons()
	{
		CalculateButton = new JButton("Calculate"); //call JButton constructor, make button named "Calculate"
	    ExitButton = new JButton("Exit"); //call JButton constructor, make button named "Exit"
	    
	    CalculateButton.addActionListener(new ButtonListener()); //Connect CalculateButton to event handler
	    ExitButton.addActionListener(new ButtonListener());	//Connect ExitButton to event handler
	    
	    add(CalculateButton); //add CalculateButton to window pane
	    add(ExitButton); //add ExitButton to window pane
	}
	
	//main method that calls constructor
	public static void main(String args[])
	{
		new MPGCalculatorApp();
	}
	
	//private inner class used for event handling, implements ActionListener Interface
	private class ButtonListener implements ActionListener
	{
		//implents actionPerfomed method for ActionListener interface
		public void actionPerformed(ActionEvent e)
		{
		
		String str1, str2; //variables to hold input from JTextFields
		double miles, gallons, MPG; //variables to conduct calculations
		
			//execute block is user clicks CalculateButton
			if (e.getSource() == CalculateButton)
			{
			//Panel1 calls accessor method to access reference to JTextLabel then accesses input 
			//through built in getText method for JTextLabel
				str1 = panel1.input().getText();
				
			//Panel2 calls accessor method to access reference to JTextLabel then accesses input 
			//through built in getText method for JTextLabel
				str2 = panel2.input().getText();
		
				//convert both strings to doubles
				miles = Double.parseDouble(str2);
				gallons = Double.parseDouble(str1);
				
				//calculate results
				MPG = miles / gallons;
				
				//format results
				DecimalFormat fmt = new DecimalFormat("#.######");
				
				//display results in a JOptionPane
				JOptionPane.showMessageDialog(null, "Your vehicle can drive " + fmt.format(MPG) + " miles per gallon", "Message", JOptionPane.PLAIN_MESSAGE);
			
			}
			
			//If user Clicks ExitButton
			if (e.getSource() == ExitButton)
			{
				int value;
				//value holds user's yes,no, or cancel selection
				value = JOptionPane.showConfirmDialog(null, "Are you sure you want to quit?", "Question",JOptionPane.YES_NO_CANCEL_OPTION);
			
				//If user selects yes, exit program
				if (value == JOptionPane.YES_OPTION)
				{
					JOptionPane.showMessageDialog(null, "Program terminated");
					System.exit(0);
				}
				
				//do nothing is user says no
				else if (value == JOptionPane.NO_OPTION)
				{
					
				}
				
				//do nothing is user says cancel
				else if (value == JOptionPane.CANCEL_OPTION)
				{
					
				}
			}
		}
	}
}
