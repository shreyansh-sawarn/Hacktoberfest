package minimum_edit_distance;

import java.util.*;

public class Minimum_Edit_Distance {

    static int find_min_edit_distace(String str1, String str2)
    {
        int l1=str1.length();
        int l2=str2.length();
        int M[][]=new int[l2+1][l1+1];
        for (int i = 0; i <=l1; i++) {
            M[0][i]=i;
        }
        for (int i = 0; i <=l2; i++) {
            M[i][0]=i;
        }
        for (int i = 1; i <=l2; i++) {
            for (int j = 1; j <=l1; j++) {
                System.out.println(str1.charAt(j-1)+" "+str2.charAt(i-1));
                if(str1.charAt(j-1)==str2.charAt(i-1))
                {
                    M[i][j]=M[i-1][j-1];
                }
                else
                {
                    M[i][j]=min(M[i-1][j-1],M[i-1][j],M[i][j-1])+1;
                }
            }
        }
        
        // printing
        for (int i = 0; i < M.length; i++) {
            for (int j = 0; j < M[i].length; j++) {
                System.out.print(M[i][j]+" ");
            }
            System.out.println("");
        }
        return M[l2][l1];
    }
    static int min(int a, int b, int c)
    {
        if(a<b && a<c)
            return a;
        else if(b<a && b<c)
            return b;
        else
            return c;
    }
    public static void main(String[] args) {
        String str1="abcdef";
        String str2="azced";
        int res=find_min_edit_distace(str1,str2);
        System.out.println(res);
    }

}
