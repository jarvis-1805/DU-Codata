import java.io.*;
class Main
{
	public static void main(String args[])throws Exception
	{
		File infile=new File(args[0]);
		File ofile=new File(args[1]);
		FileReader fr=null;
		FileWriter fw=null;
		try
		{
			fr=new FileReader(infile);
			fw=new FileWriter(ofile);
			int ch;
			while((ch=fr.read())!=-1)
			{
				fw.write((char)ch);
			}
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
		finally
		{
			fr.close();
			fw.close();
			System.out.println("Copied contents of "+args[0]+" file to "+args[1]+" file.");
		}
	}
}
