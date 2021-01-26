import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class Main extends JFrame
{
	public static void main(String args[])
	{
		new Main();
	}
	
	private JLabel label;
	
	Main()
	{
		setTitle("FRAME");
		setSize(400, 300);
		setLocation(700, 200);
		setVisible(true);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setLayout(new FlowLayout());
		getContentPane().setBackground(Color.PINK);
		
		label = new JLabel("This is a String");
		
		add(label);
	}
}