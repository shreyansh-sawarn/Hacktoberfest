import java.util.Scanner;
class Automorphic
{
  public static void main(String args[]){
  Scanner in = new Scanner(System.in);
  System.out.print("Enter a number ");
  int n = in.nextInt();
  int foo=0, sqr = n*n;
  int temp =n;
  while(temp>0)
   {
     foo++;
     temp=temp/10;
   }
  int last_Digit = (int)(sqr%(Math.pow(10,foo)));
  if(n==last_Digit)
  System.out.println("True");
  else
  System.out.println("False");
}
}
