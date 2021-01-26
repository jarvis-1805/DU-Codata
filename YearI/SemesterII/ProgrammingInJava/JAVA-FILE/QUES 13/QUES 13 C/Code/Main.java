import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class Main extends JFrame implements ActionListener
{
	public static void main(String args[])
	{
		SwingUtilities.invokeLater(new Runnable()
		{
			public void run()
			{
				new Main();
			}
		});
	}
	
	private JButton b1;
	private JButton b2;
	
	Main()
	{
		setTitle("COLOR CHANGER");
		setSize(300, 300);
		setLocation(300, 100);
		setVisible(true);
		setLayout(null);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		
		init();
		
		add(b1);
		add(b2);
		
		b1.addActionListener(this);
		b2.addActionListener(this);
	}
	
	private void init()
	{
		b1 = new JButton("RED");
		b2 = new JButton("BLUE");
		
		b1.setBounds(25, 50, 250, 30);
		b2.setBounds(25, 100, 250, 30);
		
		b1.setBackground(Color.BLACK);
		b2.setBackground(Color.BLACK);
		
		b1.setForeground(Color.RED);
		b2.setForeground(Color.BLUE);
	}
	
	public void actionPerformed(ActionEvent e)
	{
		JButton b = (JButton)e.getSource();
		
		if(b == b1)
			getContentPane().setBackground(Color.RED);
		if(b == b2)
			getContentPane().setBackground(Color.BLUE);
	}
}