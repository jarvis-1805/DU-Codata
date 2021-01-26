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
	
	private JLabel l = new JLabel();
	
	Main()
	{
		setSize(300, 200);
		setLocation(100, 100);
		setTitle("Mouse Tester");
		setVisible(true);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setLayout(new FlowLayout());
		
		add(l);
		
		addComponentListener(new ComponentAdapter()
		{
			public void componentResized(ComponentEvent ce)
			{
				addMouseListener(new MouseAdapter()
				{
					public void mouseEntered(MouseEvent e)
					{
						l.setText("Mouse Entered. Resized to 3x.");
						setSize(900, 600);
					}
					
					public void mouseClicked(MouseEvent e)
					{
						l.setText("Mouse Clicked. Regained to original size.");
						setSize(250, 200);
					}
					
					public void mouseExited(MouseEvent e)
					{
						l.setText("Mouse Exited. Closing window.");
						dispose();
					}
				});
			}
		});
	}
}