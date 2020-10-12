import java.util.Scanner;

public class PronicNumber
{
    public static void main(String[] args)
    {
        int n;
        boolean flag=false;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number=");
        n = sc.nextInt();
        for(int i=0; i < n; i++)
        {
            if(i*(i+1) == n)
            {
                flag =true;
                break;
            }
        }
        if(flag)
        {
            System.out.println("Pronic Number");
        }
        else
        {
            System.out.println("Not Pronic Number");
        }        
    }
}
