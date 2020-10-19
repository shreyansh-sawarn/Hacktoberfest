package box_stacking;

import java.util.Arrays;
import java.util.*; 

class Box implements Comparable<Box>{
    int l,w,h;
    int area;
    
    Box(int h, int w, int l)
    {
        this.h=h;
        this.w=w;
        this.l=l;
    }
    
    @Override
    public int compareTo(Box o) { 
        return o.area-this.area; 
    } 
}
public class Box_Stacking {
    
    static int max_height(Box b[], int n)
    {
        Box [] rot =new Box[n*3];  // all the rotations equals 3 times the original array
        
        for (int i = 0; i < n; i++) {
            Box box=b[i];
            rot[3*i]=new Box(box.h, Math.max(box.l, box.w),Math.min(box.l,box.w));
            rot[3*i+1]=new Box(box.w, Math.max(box.l, box.h),Math.min(box.l,box.h));
            rot[3*i+2]=new Box(box.l, Math.max(box.h, box.w),Math.min(box.h,box.w));
        }
        
        //finding area of each rotations
        for (int i = 0; i < rot.length; i++) {
            rot[i].area=rot[i].l*rot[i].w;
        }
        
        // Sorting according to area;
        Arrays.sort(rot);
        
        int count=3*n;
        int max[]=new int[count];
        
        for (int i = 0; i < count; i++) {
            max[i]=rot[i].h;
        }
        for (int i = 1; i < count; i++) {
            for (int j = 0; j < i; j++) {
                if(rot[i].l<rot[j].l && rot[i].w<rot[j].w)
                    max[i]=Math.max(max[i], max[j]+rot[i].h);
            }
        }
        
        return max[count-1];
    }
    public static void main(String[] args) {
        Box[] arr=new Box[4];
        arr[0]=new Box(4,6,7);
        arr[1]=new Box(1,2,3);
        arr[2]=new Box(4,5,6);
        arr[3]=new Box(10,12,32);
        System.out.println("The maximum height is: "+max_height(arr,4));
    }

}
