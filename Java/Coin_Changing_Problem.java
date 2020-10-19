package coin_changing_problem;
public class Coin_Changing_Problem {
    static findmincoins(int inp[],int tot)
    {
        int len=inp.length;
        int dp[][]=new int [len+1][tot+1];
        for (int i = 0; i <= len; i++) {
            dp[i][0]=1;
        }
        for (int i = 1; i <=tot; i++) {
            if(i<inp[0])
            {
                dp[0][i]=0;
            }
            else
            {
                if(i%inp[0]==0)
                {
                    dp[0][i]=i/inp[0];
                }
                else
                    dp[0][i]=0;
            }
        }
        for (int i = 1; i <= len; i++) {
            for (int j = 1; j <= tot; j++) {
                if(inp[i-1]>j)
                {
                    dp[i][j]=dp[i-1][j];
                }
                else
                {
                    dp[i][j]=Math.min(dp[i][j-inp[i-1]]+1, dp[i-1][j]);
                }
            }
        }
        
                // Loop through all rows 
        for (int i = 0; i <=dp.length; i++) {
  
            // Loop through all elements of current row 
            for (int j = 0; j < dp[i].length; j++) 
                System.out.print(dp[i][j] + " "); 
            System.out.println("");
        }
        
        System.out.println(dp[len][tot]);
        
    }
    public static void main(String[] args) {
        int inp[]={1,5,6,8};
        int tot=11;
        findmincoins(inp,tot);
    }

}
