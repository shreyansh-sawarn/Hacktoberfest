package weighted_job_scheduling;

class jobs{
    int start;
    int end;
    int profit;
    
    jobs(int start, int end,int profit)
    {
        this.start=start;
        this.end=end;
        this.profit=profit;
    }
}

public class Weighted_Job_Scheduling {

    static int find_max_profit(int n,jobs job[])
    {
        int arr[]=new int[n];
        int max=0;
        for (int i = 0; i < n; i++) {
            arr[i]=job[i].profit;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if(!check_overlap(job,i,j))
                {
                    arr[i]=Math.max(arr[i],arr[j]+job[i].profit);
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i]+" ");
        }
        for (int i = 0; i < n; i++) {
            if(arr[i]>max)
                max=arr[i];
        }
        return max;
    }
    
    static boolean check_overlap(jobs job[],int i,int j)
    {
        if(job[i].start>=job[j].end)
            return false;
        else
            return true;
    }
    public static void main(String[] args) {
        jobs job[]=new jobs[5];
        job[0]=new jobs(1,3,20);
        job[1]=new jobs(2,5,20);
        job[2]=new jobs(3,10,100);
        job[3]=new jobs(4,6,70);
        job[4]=new jobs(6,9,60);
        System.out.println("The maximum profit obtained is: "+find_max_profit(5,job));
    }

}
