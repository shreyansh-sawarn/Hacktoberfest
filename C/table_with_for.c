#include <stdio.h>

int
main ()
{
   start:
  printf ("Program for 'For loop' in c\n");

  int i, j, k;




  printf ("Enter the number to get table of it:");

  scanf ("%d", &i);
  printf ("Enter the same number again:");

  scanf ("%d", &j);
  
  if(i==j)
  {


  for (; i <= j * 10;)
    {
      printf ("%d\n", i);
      i = i + j;
      
    }

      printf ("Enter 0 to quit:");

      scanf ("%d", &k);

      if (k == 0)
	{
	  goto end;
	}
	else
	{
	    goto start;
	}
	
  }
  
  
  else
  {
  
  printf("wrong input\n");
  }
   

end:
printf("sukriya");

  return 0;
}

