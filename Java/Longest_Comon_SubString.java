package longest_comon_substring;
public class Longest_Comon_SubString {

    static int find_lcs(String str1,String str2)
    {
        int l1=str1.length();
        int l2=str2.length();
        int max=0;
        int max_i=0;
        int max_j=0;
        String res="";
        int T[][]=new int[l1+1][l2+2];
        for (int i = 0; i <= l1; i++) {
            for (int j = 0; j <= l2; j++) {
                if(i==0 || j==0)
                    T[i][j]=0;
                else
                {
                    if(str1.charAt(i-1)==str2.charAt(j-1))
                        T[i][j]=T[i-1][j-1]+1;
                    else
                        T[i][j]=0;
                }
            }
        }
        for (int i = 0; i <=l1; i++) {
            for (int j = 0; j <=l2; j++) {
                if(T[i][j]>max)
                {
                    max=T[i][j];
                    max_i=i;
                    max_j=j;
                }
            }
        }
        //Traceback
        
        while(T[max_i][max_j]!=0)
        {
            res=str1.charAt(max_i-1)+res;
            max_i=max_i-1;
            max_j=max_j-1;
        }
        System.out.println("Longest Common Substring is : "+res);
        return max;
    }
    
    public static void main(String[] args) {
        String str1="abcdaf";
        String str2="zbcdf";
        System.out.println("Length of longest common substring is: "+find_lcs(str1,str2));
    }

}
