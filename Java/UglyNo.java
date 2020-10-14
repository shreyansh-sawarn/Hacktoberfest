import java.util.Scanner;

public class UglyNumber
{
    public static void main(String[] args)
    {
        int n;
        boolean flag=true;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number=");
        n = sc.nextInt();
        while (n != 1)
        {
            if (n % 5 == 0)
            {
                n /= 5;
            }
            else if (n % 3 == 0)
            {
                n /= 3;
            }
            else if (n % 2 == 0)
            {
                n /= 2;
            }
            else
            {
                flag=false;
                break;
            }
        }
        if (flag)
        {
            System.out.println("Ugly number.");
        }
        else
        {
            System.out.println("Not Ugly number.");
        }
    }
}
