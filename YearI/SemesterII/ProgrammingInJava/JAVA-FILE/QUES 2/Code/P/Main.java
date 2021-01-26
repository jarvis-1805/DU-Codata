package P;

import P1.*;
import P2.*;

public class Main
{
    public static void main(String args[])
    {
        TwoDim td=new TwoDim(3,5);
        System.out.println(td);

        td=new ThreeDim(3,5,8);
        System.out.println(td);
    }
}