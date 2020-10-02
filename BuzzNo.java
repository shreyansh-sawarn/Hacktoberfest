import java.util.Scanner;
public class BuzzNumber
{
    public static void main(String[] args)
    {
        int n;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter n=");
        n = sc.nextInt();
        if (n % 10 == 7 || n % 7 == 0)
        {
            System.out.println("Buzz number");
        }
        else
        {
            System.out.println("Not Buzz number");
        }
    }
}
