import java.awt.*;
import java.awt.event.*;

class Main extends Frame
{
	public static void main(String args[])
	{
		new Main();
	}
	
	private Label lkey;
	
	Main()
	{
		setTitle("Key Entered");
		setSize(300, 200);
		setLocation(400, 200);
		setVisible(true);
		setLayout(new FlowLayout());
		
		lkey = new Label();
		
		addKeyListener(new MyKeyListener(lkey));
		add(lkey);
		
		addWindowListener(new WindowAdapter()
		{
			public void windowClosing(WindowEvent we)
			{
				dispose();
			}
		});
	}
}

class MyKeyListener extends KeyAdapter
{
	private Label lkey;
	
	MyKeyListener(Label lkey)
	{
		this.lkey = lkey;
	}
	
	public void keyTyped(KeyEvent e)
	{
		char ch = e.getKeyChar();
		lkey.setText("Typed Character is : " + ch);
	}
}