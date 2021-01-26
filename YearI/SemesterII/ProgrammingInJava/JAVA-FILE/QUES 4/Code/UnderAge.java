import java.lang.Exception;

class UnderAge extends Exception
{
	private int age;

	public UnderAge(int age)
	{
		this.age=age;
	}

	@Override
	public String getMessage()
	{
		return "UnderAge: "+age+" is less than 18";
	}
}