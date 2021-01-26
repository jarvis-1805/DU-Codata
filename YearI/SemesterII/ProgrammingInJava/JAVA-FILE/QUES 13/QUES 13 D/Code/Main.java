import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class Main extends JFrame
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
	
	private JLabel lkey;
	
	Main()
	{
		setTitle("Key Entered");
		setSize(300, 200);
		setLocation(400, 200);
		setVisible(true);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setLayout(new FlowLayout());
		
		lkey = new JLabel();
		
		addKeyListener(new MyKeyListener(lkey));
		add(lkey);
	}
}

class MyKeyListener extends KeyAdapter
{
	private JLabel lkey;
	
	MyKeyListener(JLabel lkey)
	{
		this.lkey = lkey;
	}
	
	public void keyTyped(KeyEvent e)
	{
		char ch = e.getKeyChar();
		lkey.setText("Typed Character is : " + ch);
	}
}