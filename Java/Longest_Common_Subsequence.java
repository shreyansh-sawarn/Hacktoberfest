package longest_common_subsequence;

import java.util.*;
class test{
    static int max(int a,int b)
    {
        return (a>b)?a:b;
    }
    
    void longest(String str1, int l1,String str2, int l2)
    {
        int dp[][]=new int[l1+1][l2+1];
        for (int i = 0; i <=l1; i++) {
            for (int j = 0; j <=l2; j++) {
                if(i==0 || j==0)
                    dp[i][j]=0;
                else if(str1.charAt(i-1)!=str2.charAt(j-1))
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
                else
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
            }
        }
        System.out.println(dp[l1][l2]);
    }
}
public class Longest_Common_Subsequence {

    public static void main(String[] args) {
        test obj=new test();
        String str1="bd";
        String str2="abcd";
        int l1=str1.length();
        int l2=str2.length();
        obj.longest(str1,l1,str2,l2);
        
    }

}
