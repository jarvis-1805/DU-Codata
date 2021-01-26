import java.util.Scanner;

public class Main extends exceptionDemo
{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);

		System.out.println("Enter the age: ");
		int age=sc.nextInt();

		try
		{
			test(age);
			System.out.println("Test successful");
		}

		catch(UnderAge e)
		{
			System.out.println("Test unsuccessful");
			System.out.println(e.getMessage());
	 	}

		finally
		{
			sc.close();
		}
	}
}