package wildcard_matching;
public class WildCard_Matching {

    static boolean check_wildcard_match(String str,String pattern)
    {
        int r=str.length();
        int c=pattern.length();
        boolean M[][]=new boolean[r+1][c+1];
        for (int i = 0; i <= r; i++) {
            for (int j = 0; j <= c; j++) {
                if(i==0)
                {
                    if(j==0)
                        M[i][j]=true;
                    else if(j==1 && pattern.charAt(j-1)=='*')
                    {
                        M[i][j]=true;
                    }
                    else
                        M[i][j]=false;
                }
                else if(j==0)
                {
                    M[i][j]=false;
                }
                else
                {
                    if((str.charAt(i-1)==pattern.charAt(j-1)) || (pattern.charAt(j-1)=='?'))
                    {
                        M[i][j]=M[i-1][j-1];
                    }
                    else if(pattern.charAt(j-1)=='*')
                    {
                        M[i][j]=M[i-1][j] || M[i][j-1]; 
                    }
                    else
                        M[i][j]=false;
                }
            }
        }
        return M[r][c];
    }
    public static void main(String[] args) {
        String str="xaylmz";
        String pattern="x?y*z";
        System.out.println("The wild card matching is: "+check_wildcard_match(str,pattern));
    }

}
