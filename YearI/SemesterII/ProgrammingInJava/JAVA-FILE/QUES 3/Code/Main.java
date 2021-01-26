import java.io.*;

import P1.*;
import P2.*;
import P3.*;

class Main
{
	public static void main(String args[])throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));

		int ch;
		while(true)
		{
			System.out.println("Enter shape type- 1 for Rectangle and 2 for Circle and 3 for exit: ");
			ch=Integer.parseInt(br.readLine());

			Shape sh;
		
		
			if (ch==1)
			{
				sh=new Rectangle();
				System.out.println("Area of Rectangle is: " + sh.area() + " sq. units");

			}

			else if(ch==2)
			{
				sh=new Circle();
				System.out.println("Area Circle is: " + sh.area() + " sq. units");
	
			}

			else
			{
				System.out.println("EXITING...");
				System.exit(0);
			}
		}
	}
}