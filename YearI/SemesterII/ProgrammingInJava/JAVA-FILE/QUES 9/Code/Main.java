import java.awt.*;
import java.awt.event.*;

class Main extends Frame 
{
	public static void main(String args[])
	{
		Main frm = new Main();
		frm.addWindowListener(new MyWindowListener());
	}
	
	public Main()
	{
		setTitle("AWT Pink");
		setSize(250, 100);
		setLocation(100, 200);
		setVisible(true);
		setBackground(Color.PINK);
		setLayout(new FlowLayout(FlowLayout.CENTER));
		add(new Label("This is a String!!!"));
	}
}

class MyWindowListener extends WindowAdapter
{
	public void windowClosing(WindowEvent ev)
	{
		ev.getWindow().dispose();
	}
}