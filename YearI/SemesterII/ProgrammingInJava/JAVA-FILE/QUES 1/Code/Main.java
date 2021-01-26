public class Main
{
	public static void main(String args[])
	{
		Complex c1 = new Complex(1, 2);
		Complex c2 = new Complex(3, 4);
		System.out.println("Complex 1: " + c1);
		System.out.println("Complex 2: " + c2);
		System.out.println("Sum: " + c1.add(c2));
		System.out.println("Product: " + c1.multiply(c2));
	}
}