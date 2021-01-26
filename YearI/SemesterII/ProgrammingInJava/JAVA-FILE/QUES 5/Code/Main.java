import java.util.*;
import java.io.*;

class stackException extends Exception
{
	final private String message;
	public stackException(String message)
	{
		this.message=message;
	}
	public String getMessage()
	{
		return this.message;
	}
}	

class Main
{
	private int arr[];
	private int top;
	private int capacity;
	
	Main(int size)
	{
		arr=new int[size];
		capacity=size;
		top=-1;
	}
	
	public void push(int x)throws stackException
	{
		if(top==capacity-1)			//is full
		{
			throw new stackException("@@@@@ Stack Overflow:Could not push "+x+" @@@@@");
		}
		else
		{			
			//System.out.println("PUSHING "+x);
			arr[++top]=x;
		}
	}
	
	public int pop()throws stackException
	{
		if(top==-1)   	//is empty
		{
			throw new stackException("@@@@@ Stack Underflow:Could not pop @@@@@");
		}
		else
		{
			System.out.println("POPPED "+arr[top]);
			return arr[top--];
		}
	}
	
	public int size()
	{
		return top+1;
	}
	
	public static void main(String args[])
	{
		int r;
		Main stack=new Main(10);
		Random ran=new Random();
		System.out.println("Stack created of size 10");
		
		System.out.println("PUSHING elements in stack");
		while(true)
		{
			r=ran.nextInt(100);
			System.out.println("PUSHING "+r);
			try
			{
				stack.push(r);
				System.out.println("Elements in stack "+stack.size());
			}
			catch(stackException e)
			{
				System.err.println(e.getMessage());
				break;
			}
		}
		
		System.out.println("POPPING elements from stack");
		while(true)
		{
			System.out.println("Elemnts in stack "+stack.size());
			try
			{
				stack.pop();
			}
			catch(stackException e)
			{
				System.err.println(e.getMessage());
				break;
			}
		}
	}
}
