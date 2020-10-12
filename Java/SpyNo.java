import java.util.Scanner;

public class SpyNumber
{
    public static void main(String[] args)
    {
        // TODO code application logic here
        int r, n, num, mul = 1, sum = 0;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number=");
        n = sc.nextInt();
        num = n;
        while (num > 0)
        {
            r = num % 10;
            sum = sum + r;
            mul = mul * r;
            num = num / 10;
        }
        if (mul == sum)
        {
            System.out.println("Spy Number");
        }
        else
        {
            System.out.println("Not Spy Number");
        }
    }
}
