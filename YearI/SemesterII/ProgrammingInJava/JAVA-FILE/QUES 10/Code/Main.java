import java.awt.*;
import java.awt.event.*;

class Main extends Frame implements ActionListener
{
	public static void main(String args[])
	{
		Main frm = new Main();
		frm.addWindowListener(new MyWindowListener());
	}
	
	private Button b1;
	private Button b2;
	
	public Main()
	{
		setTitle("COLOR CHANGER");
		setSize(300, 300);
		setLocation(300, 100);
		setVisible(true);
		setLayout(null);
		
		init();
		
		add(b1);
		add(b2);
		
		b1.addActionListener(this);
		b2.addActionListener(this);
	}
	
	private void init()
	{
		b1 = new Button("RED");
		b2 = new Button("BLUE");
		
		b1.setBounds(25, 50, 250, 30);
		b2.setBounds(25, 100, 250, 30);
		
		b1.setBackground(Color.BLACK);
		b2.setBackground(Color.BLACK);
		
		b1.setForeground(Color.RED);
		b2.setForeground(Color.BLUE);
	}
	
	public void actionPerformed(ActionEvent e)
	{
		Button b = (Button)e.getSource();
		
		if(b == b1)
			setBackground(Color.RED);
		if(b == b2)
			setBackground(Color.BLUE);
	}
}

class MyWindowListener extends WindowAdapter
{
	public void windowClosing(WindowEvent we)
	{
		we.getWindow().dispose();
	}
}