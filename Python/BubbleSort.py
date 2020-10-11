# Python program for implementation of Bubble Sort 

def bubbleSort(list): 
	n = len(list) 

	# Traverse through all listay elements 
	for i in range(n): 

		 
		for j in range(0, n-i-1): 

			
			# Swap if the element found is greater than the next element 
			if list[j] > list[j+1] : 
				list[j], list[j+1] = list[j+1], list[j] 
 
list = [14,6,90,11,45,7,1] 

bubbleSort(list) 

print ("Sorted listay is:") 
for i in range(len(list)): 
	print ("%d" %list[i]), 
