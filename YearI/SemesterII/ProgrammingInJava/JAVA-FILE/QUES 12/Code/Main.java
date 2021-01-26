import java.awt.*;
import java.awt.event.*;

class Main extends Frame implements ActionListener
{
	public static void main(String args[])
	{
		Main frm = new Main();
		frm.addWindowListener(new MyActionListener());
	}
	
	private Button A;
	private Button B;
	
	Main()
	{
		setTitle("Student Details");
		setSize(500, 350);
		setLocation(500, 220);
		setVisible(true);
		setLayout(null);
		setBackground(Color.MAGENTA);
		
		A = new Button("A");
		B = new Button("B");
		
		A.setBounds(50, 100, 400, 50);
		B.setBounds(50, 200, 400, 50);
		
		A.setBackground(Color.BLACK);
		B.setBackground(Color.BLACK);
		
		A.setForeground(Color.GRAY);
		B.setForeground(Color.GRAY);
		
		add(A);
		add(B);
		
		A.addActionListener(this);
		B.addActionListener(this);
	}
	
	public void actionPerformed(ActionEvent e)
	{
		Button b = (Button)e.getSource();
		
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

class information extends Frame
{
	private Label lName;
	private Label lCourse;
	private Label lRollNo;
	private Label lCollege;
	private Button close;
	private TextField tname;
	private TextField tcourse;
	private TextField trollno;
	private TextField tcollege;
	
	information(String name, String course, String rollNo, String college)
	{
		setTitle("Personal Information");
		setSize(350, 250);
		setLocation(570, 280);
		setVisible(true);
		setLayout(null);
		setBackground(Color.BLUE);
		
		lName = new Label("Name:");
		lCourse = new Label("Course:");
		lRollNo = new Label("RollNo.:");
		lCollege = new Label("College:");
		close = new Button("Close");
		tname = new TextField(name);
		tcourse = new TextField(course);
		trollno = new TextField(rollNo);
		tcollege = new TextField(college);
		
		tname.setEditable(false);
		tcourse.setEditable(false);
		trollno.setEditable(false);
		tcollege.setEditable(false);
		
		lName.setBounds(25, 40, 50, 20);
		lCourse.setBounds(25, 80, 50, 20);
		lRollNo.setBounds(25, 120, 50, 20);
		lCollege.setBounds(25, 160, 50, 20);
		close.setBounds(150, 200, 70, 30);
		tname.setBounds(100, 40, 200, 20);
		tcourse.setBounds(100, 80, 200, 20);
		trollno.setBounds(100, 120, 200, 20);
		tcollege.setBounds(100, 160, 200, 20);
		
		close.setBackground(Color.BLACK);
		
		close.setForeground(Color.GRAY);
		
		add(lName);
		add(tname);
		add(lCourse);
		add(tcourse);
		add(lRollNo);
		add(trollno);
		add(lCollege);
		add(tcollege);
		add(close);
		
		addWindowListener(new MyActionListener());
		close.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
			{
				dispose();
			}
		});
	}
}

class CGPA extends Frame
{
	private Label lcgpa;
	private Button close;
	
	CGPA(String cgpa)
	{
		setTitle("Previous Year CGPA");
		setSize(300, 150);
		setLocation(600, 320);
		setVisible(true);
		setLayout(null);
		setBackground(Color.ORANGE);
		
		lcgpa = new Label(cgpa);
		close = new Button("Close");
		
		lcgpa.setBounds(100, 35, 300, 50);
		close.setBounds(120, 90, 70, 30);
		
		close.setBackground(Color.BLACK);
		
		close.setForeground(Color.GRAY);
		
		add(lcgpa);
		add(close);
		
		addWindowListener(new MyActionListener());
		close.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
			{
				dispose();
			}
		});
	}
}

class MyActionListener extends WindowAdapter
{
	public void windowClosing(WindowEvent we)
	{
		we.getWindow().dispose();
	}
}