class Complex
{
	
	private	int x;
	private int y;
	
	
	public Complex(int real, int imaginary)
	{
		this.x = real;
		this.y = imaginary;
	}
		
	public Complex add(Complex o)
	{
		return new Complex(this.x + o.x, this.y + o.y);
	}
	
	public Complex multiply(Complex o)
	{
		return new Complex(this.x * o.x - this.y * o.y,
                    	   this.x * o.y + o.x * this.y);
	}
	
	@Override
	public String toString()
	{
		return x + " +i " + y;
	}
}
