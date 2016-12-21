import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.DecimalFormat;
import java.awt.event.*;
import javax.swing.event.*;

public class SkateBoardApp extends JFrame {
	
	private JList Decks_Menu; //JList object for a list
	private JList Truck_Assemblies_Menu; //JList object for a list
	private JList Wheels_Menu; //JList object for a list
	private JList Miscellaneous_Menu; //JList object for a list
	private JPanel Panel_1; //JPanel object to hold a list and JLabel
	private JPanel Panel_2; //JPanel object to hold a list and JLabel
	private JPanel Panel_3; //JPanel object to hold a list and JLabel
	private JPanel Panel_4; //JPanel object to hold a list and JLabel
	private JLabel label1;	//JLabel object to label a panel
	private JLabel label2;  //JLabel object to label a panel
	private JLabel label3;  //JLabel object to label a panel
	private JLabel label4;  //JLabel object to label a panel
	private JButton CalculateButton; //JButton object for user to click
	private JButton ExitButton; //JButton object for user to click
	private int cost1 = 0; //totals cost for a list
	private int cost2 = 0; //totals cost for a list
	private int cost3 = 0; //totals cost for a list
	private int cost4 = 0; //totals cost for a list
	
	//constructor
	SkateBoardApp()
	{
		//call superclass constructor, label GUI
		super("Build your own Skateboard!");
		
		//make window pop up in middle of screen
		setLocationRelativeTo(null);
		
		//allow window to close
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		//call makeLists method
		makeLists();
		
		//Layout for JPanel components
		GridLayout layout = new GridLayout(2,4, 5 ,5);
		setLayout(layout);
		
		//add each Panel
		add(Panel_1);
		add(Panel_2);
		add(Panel_3);
		add(Panel_4);
		
		//Create Calculate Button
		CalculateButton = new JButton("Calculate");
		
		//Create Exit Button
	    ExitButton = new JButton("Exit");
	    
	    //Connect event handlers with JButton objects
	    CalculateButton.addActionListener(new ButtonListener());
	    ExitButton.addActionListener(new ButtonListener());	
	    
	    //add buttons to window pane
	    add(CalculateButton);
	    add(ExitButton);
	
		//pack JPanel objects to fit on screen
		pack();
		
		//Make window visible
		setVisible(true);
	}
	
	//makes lists
	private void makeLists()
	{
		//create arrays to initialize each list
		String [] arr1 = {"The Master Thrasher ($60)", "The Dictator ($45)", "The Street King ($50)"};
		String [] arr2 = {"7.75 Inch axle ($35)", "8-inch Axle ($40)", "8.5 inch axle ($45)"};
		String [] arr3 = {"51 mm ($20)", "55 mm ($22)", "58mm ($24)", "61mm ($28)"};
		String [] arr4 = {"Grip tape ($10)", "Bearings ($30)", "Riser pads ($2)", "Nuts and bolts kit ($3)"};
		
		//give each panel a layout
		 Panel_1 = new JPanel(new BorderLayout());
		 Panel_2 = new JPanel(new BorderLayout());
		 Panel_3 = new JPanel(new BorderLayout());
		 Panel_4 = new JPanel(new BorderLayout());
	     
		 //constructor JLabel objects with appropriate text
		 label1 = new JLabel("Choose your Deck!");
		 label2 = new JLabel("Choose your Truck!");
		 label3 = new JLabel("Choose your Wheels!");
	     label4 = new JLabel("Miscellaneous");
	     
	     //Give Labels borders
	     label1.setBorder(BorderFactory.createLineBorder(Color.CYAN,2));
	     label2.setBorder(BorderFactory.createLineBorder(Color.RED,2));
	     label3.setBorder(BorderFactory.createLineBorder(Color.GREEN,2));
	     label4.setBorder(BorderFactory.createLineBorder(Color.BLUE,2));
	     
	     //center the labels
	     label1.setHorizontalAlignment(JLabel.CENTER);
	     label2.setHorizontalAlignment(JLabel.CENTER);
	     label3.setHorizontalAlignment(JLabel.CENTER);
	     label4.setHorizontalAlignment(JLabel.CENTER);
	     
	     //add the Labels to north section of JPanel object
	     Panel_1.add(label1,BorderLayout.NORTH);
	     Panel_2.add(label2,BorderLayout.NORTH);
		 Panel_3.add(label3,BorderLayout.NORTH);
	     Panel_4.add(label4,BorderLayout.NORTH);
	     
		 //intialize JList objects with arrays listed above
		 Decks_Menu = new JList(arr1);
		 Truck_Assemblies_Menu = new JList(arr2);
		 Wheels_Menu = new JList(arr3);
		 Miscellaneous_Menu = new JList(arr4);
		 
		 //Connect event handlers to each list
		//Decks_Menu.addListSelectionListener(new Decks_Menu_Listener());
		 Decks_Menu.addListSelectionListener(new ButtonListener());
		// Truck_Assemblies_Menu.addListSelectionListener(new Trucks_Menu_Listener());
		 Truck_Assemblies_Menu.addListSelectionListener(new ButtonListener());
		// Wheels_Menu .addListSelectionListener(new Wheels_Menu_Listener());
		 Wheels_Menu .addListSelectionListener(new ButtonListener());
		 Miscellaneous_Menu.addListSelectionListener(new ButtonListener());
		
		 //give each menu a border
		 Decks_Menu.setBorder(BorderFactory.createLineBorder(Color.CYAN,2));
		 Truck_Assemblies_Menu.setBorder(BorderFactory.createLineBorder(Color.RED,2));
		 Wheels_Menu.setBorder(BorderFactory.createLineBorder(Color.GREEN,2));
		 Miscellaneous_Menu.setBorder(BorderFactory.createLineBorder(Color.BLUE,2));
		 
		 //choose selectionMode for each Menu
		 Decks_Menu.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		 Truck_Assemblies_Menu.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		 Wheels_Menu.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		 Miscellaneous_Menu .setSelectionMode(ListSelectionModel.MULTIPLE_INTERVAL_SELECTION);
		 
		 //add Menu to Southern part of JLabel
		 Panel_1.add(Decks_Menu,BorderLayout.SOUTH);
		 Panel_2.add(Truck_Assemblies_Menu, BorderLayout.SOUTH);
		 Panel_3.add(Wheels_Menu, BorderLayout.SOUTH);
		 Panel_4.add(Miscellaneous_Menu, BorderLayout.SOUTH);
	    
	  
	    
	}
	
	//Private Inner class for Event Handling, implements both ActionListener and ListSelectionListener interfaces
	private class ButtonListener implements ActionListener, ListSelectionListener
	{
	//Implements ActionListener method
		public void actionPerformed(ActionEvent e) //If the calculate button is pressed
		{	
			if (e.getSource() == CalculateButton)
			{
				//receive index of element in list which was selected
				int selection1 = Decks_Menu.getSelectedIndex(); 
				
				//assign cost1 variable price depending on value of index
				if (selection1 == 0)
					cost1 = 60;
				else if (selection1 == 1)
					cost1 = 45;
				else if (selection1 == 2)
					cost1 = 50;
				
				//receive index of element in list which was selected
				int selection2 = Truck_Assemblies_Menu.getSelectedIndex();
				
				//assign cost2 variable price depending on value of index
				if (selection2 == 0)
					cost2 = 35;
				else if (selection2 == 1)
					cost2 = 40;
				else if (selection2 == 2)
					cost2 = 45;
				
				//receive index of element in list which was selected
				int selection3 = Wheels_Menu.getSelectedIndex();
				
				//assign cost3 variable price depending on value of index
				if (selection3 == 0)
					cost3 = 20;
				else if (selection3 == 1)
					cost3 = 22;
				else if (selection3 == 2)
					cost3 = 24;
				else if (selection3 == 3)
					cost3 = 28;
				
				//receive array of indicies which are selected with multiple interval list
				int array[] = Miscellaneous_Menu.getSelectedIndices();
				
				//cycle through array, accumulating cost in cost4 variable
				for (int x : array)
				{
				  if (x == 0)
					 cost4 += 10;
				 else if (x == 1)
					cost4 += 30;
				else if (x == 2)
					cost4 += 2;
				else if (x == 3)
					cost4 += 3;
				}
				
				//calculate subtotal
				double subtotal = cost1 + cost2 + cost3 + cost4;
				
				//calculate tax
				double tax = subtotal * .06;
				
				//calculate total 
				double total = subtotal + tax;
				
				//format output
				DecimalFormat fmt = new DecimalFormat("0.00");
				
				//display output in JOptionPane
				JOptionPane.showMessageDialog(null, "Subtotal: $" + fmt.format(subtotal) + "\n " +
				 		"Tax: $" + fmt.format(tax) + " \n Total: $" + fmt.format(total), "Costs", JOptionPane.PLAIN_MESSAGE);
				
				//reset accumulator variables
				cost1 = 0;
				cost2 = 0;
				cost3 = 0;
				cost4 = 0;
			
			}
			
			//if user selects the Exit button
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
		
		public void valueChanged(ListSelectionEvent e)
		{
			//This method is here to satisfy compiler, this method does nothing
			//The logic is to wait until the calculate button is clicked, then update
			//cost variables and display the costs. This is a safer way of handling the data
		}  
	}

	//main method which calls SkateBoardApp constructor
	public static void main(String args [])
	{
		
		new SkateBoardApp();
	}

}
