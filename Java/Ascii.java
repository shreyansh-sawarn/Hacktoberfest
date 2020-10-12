import java.util.Scanner;  
class Ascii 
{  
public static void main(String args[])  
{
char ch;
System.out.print("Enter a character: ");  
Scanner sc = new Scanner(System.in);  
ch = sc.next().charAt(0);  
int Value = ch;  
System.out.println("ASCII value of "+ch+" is: "+ Value);  
}  
}
