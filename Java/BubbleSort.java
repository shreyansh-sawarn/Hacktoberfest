public class BubbleSort {

	public static void main(String[] args) {
		
		int a[]= {2,3,5,65,-3,2,-4};
		
		int n = a.length;
		
		System.out.println("Array before bubble sort");

		for(int i=0; i<n; i++) {
			System.out.print(a[i] + "  ");
		}
		for(int i=0; i<n-1; i++) {
			
			
				for( int j=0; j<n-1; j++)
				{
					if(a[j]>a[j+1])
					{
					int temp = a[j+1];
					a[j+1]= a[j];
					a[j]= temp;
					
				}
			}
		}
		System.out.println();
		System.out.println("Array after bubble sort");
		
		for ( int item:a) {
			System.out.print(item + "  ");
		}

	}

}
