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
	
	private JButton A;
	private JButton B;
	
	Main()
	{
		setTitle("Student Details");
		setSize(500, 350);
		setLocation(500, 220);
		setVisible(true);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setLayout(null);
		getContentPane().setBackground(Color.MAGENTA);
		
		A = new JButton("A");
		B = new JButton("B");
		
		A.setBounds(50, 100, 400, 50);
		B.setBounds(50, 200, 400, 50);
		
		A.setBackground(Color.BLACK);
		B.setBackground(Color.BLACK);
		
		A.setForeground(Color.WHITE);
		B.setForeground(Color.WHITE);
		
		add(A);
		add(B);
		
		A.addActionListener(this);
		B.addActionListener(this);
	}
	
	public void actionPerformed(ActionEvent e)
	{
		JButton b = (JButton)e.getSource();
		
		if(b == A)
		{
			new information("Shubhang Gupta", "BSc. (Hons) Computer Science", "19/78098", "ARSD College");
		}
		if(b == B)
		{
			new CGPA("Your CGPA was 9.18");
		}
	}
}

class information extends JFrame
{
	private JLabel lName;
	private JLabel lCourse;
	private JLabel lRollNo;
	private JLabel lCollege;
	private JButton close;
	private JTextField tname;
	private JTextField tcourse;
	private JTextField trollno;
	private JTextField tcollege;
	
	information(String name, String course, String rollNo, String college)
	{
		setTitle("Personal Information");
		setSize(350, 250);
		setLocation(570, 280);
		setVisible(true);
		setDefaultCloseOperation(DISPOSE_ON_CLOSE);
		setLayout(null);
		getContentPane().setBackground(Color.BLUE);
		
		lName = new JLabel("Name:");
		lCourse = new JLabel("Course:");
		lRollNo = new JLabel("RollNo.:");
		lCollege = new JLabel("College:");
		close = new JButton("Close");
		tname = new JTextField(name);
		tcourse = new JTextField(course);
		trollno = new JTextField(rollNo);
		tcollege = new JTextField(college);
		
		tname.setEditable(false);
		tcourse.setEditable(false);
		trollno.setEditable(false);
		tcollege.setEditable(false);
		
		lName.setBounds(25, 30, 50, 20);
		lCourse.setBounds(25, 60, 50, 20);
		lRollNo.setBounds(25, 90, 50, 20);
		lCollege.setBounds(25, 120, 50, 20);
		close.setBounds(130, 160, 70, 30);
		tname.setBounds(100, 30, 200, 20);
		tcourse.setBounds(100, 60, 200, 20);
		trollno.setBounds(100, 90, 200, 20);
		tcollege.setBounds(100, 120, 200, 20);
		
		close.setBackground(Color.BLACK);
		
		close.setForeground(Color.WHITE);
		
		add(lName);
		add(tname);
		add(lCourse);
		add(tcourse);
		add(lRollNo);
		add(trollno);
		add(lCollege);
		add(tcollege);
		add(close);
		
		close.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
			{
				dispose();
			}
		});
	}
}

class CGPA extends JFrame
{
	private JLabel lcgpa;
	private JButton close;
	
	CGPA(String cgpa)
	{
		setTitle("Previous Year CGPA");
		setSize(300, 150);
		setLocation(600, 320);
		setVisible(true);
		setDefaultCloseOperation(DISPOSE_ON_CLOSE);
		setLayout(null);
		getContentPane().setBackground(Color.ORANGE);
		
		lcgpa = new JLabel(cgpa);
		close = new JButton("Close");
		
		lcgpa.setBounds(90, 15, 300, 50);
		close.setBounds(110, 60, 70, 30);
		
		close.setBackground(Color.BLACK);
		
		close.setForeground(Color.WHITE);
		
		add(lcgpa);
		add(close);
		
		close.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
			{
				dispose();
			}
		});
	}
}