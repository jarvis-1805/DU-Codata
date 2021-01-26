package P2;

import java.io.*;

import P1.*;

public class Rectangle extends Shape
{
	private double length;
	private double breadth;

	protected void getData()throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));

		System.out.println("Enter the length: ");
		length=Double.parseDouble(br.readLine());

		System.out.println("Enter the breadth: ");
		breadth=Double.parseDouble(br.readLine());
	}

	public double area()throws IOException
	{
		getData();
		return length*breadth;
	}
}
