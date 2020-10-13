package Arrays;

public class SelectionSort {

	public static void main(String[] args) {
     int a[]= {2,3,5,65,-3,2,-4};
		
		int n = a.length;
		
		System.out.println("Array before selection sort");

		for(int i=0; i<n; i++) {
			System.out.print(a[i] + "  ");
		}

		for(int i=0; i<n-1; i++) {
			
			int minIndex= i;
			for(int j=i; j<n; j++) {
			
			if(a[j]<a[minIndex]) {
				 minIndex= j;
			}
			}	
			int temp = a[i];
					a[i]= a[minIndex];
					a[minIndex]= temp;
					
			}
		
		System.out.println();
		System.out.println("Array after selection sort");
		
			for ( int item:a) {
				System.out.print(item + "  ");
			}
				
		

	}

}
