import java.awt.*;
import java.awt.event.*;

class Main extends Frame
{
	public static void main(String args[])
	{
		new Main();
	}
	
	private Label l = new Label();
	
	Main()
	{
		setSize(300, 200);
		setLocation(100, 100);
		setTitle("Mouse Tester");
		setVisible(true);
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