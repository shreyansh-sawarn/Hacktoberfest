package pkg01knapsack;

import java.util.*;
class example{
    static int max(int a, int b) 
    { 
        return (a > b) ? a : b; 
    } 
    void knapsack(int w, int val[],int wt[], int n)
    {
        int dp[][]=new int[n+1][w+1];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= w; j++) {
                if(i==0 || j==0)
                {
                    dp[i][j]=0;
                }
                else if(j<wt[i-1])
                {
                    dp[i][j]=dp[i-1][j];
                }
                else
                {
                    dp[i][j]=max(val[i-1]+dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
                }
            }
        }
        System.out.println( dp[n][w]);
    }
}
public class Main {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        example obj=new example();
        int w=sc.nextInt();
        int val[]={1,4,5,7};
        int wt[]={1,3,4,5};
        int n=val.length;
        obj.knapsack(w,val,wt,n);
    }

}
