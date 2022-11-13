#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "common_defs.h"

int main(int argc, char* argv[])
{
   int n;
   int i;
   int next_power_of_2;
   int shift_val;
   int coeff;
   int ret_val;
   complex* a;
   complex* b;
   
   int choice;
   do // Do while loop for printing menu
   {
      printf("Menu-\n");
      printf("1. Add 2 polynomials\n");
      printf("2. Subtract 2 polynomials\n");
      printf("3. Multiply 2 polynomials\n");
      printf("4. Differentiate a polynomial\n");
      printf("5. Integrate a polynomial\n");
      printf("6. Find roots of a polynomial\n");
      printf("0. Quit\n");
      scanf("%d", &choice);
      
      switch(choice)
      {

         case 1:
         {
            printf("Enter the highest degree of the polynomial : ");
            scanf("%d",&n);
            n++;
            next_power_of_2 = 1;
            while (next_power_of_2 < n)
               next_power_of_2 <<= 1;
            a = (complex*)malloc(2 * next_power_of_2 * sizeof(complex));
            b = (complex*)malloc(2 * next_power_of_2 * sizeof(complex));
            complex* sum = (complex*)malloc(2 * next_power_of_2 * sizeof(complex));
            get_poly(a, n); // Getting polynomial input
            get_poly(b, n);
            poly_add(sum, a, b, n);
            print_poly(sum, n);

            free(a);
            free(b);
            free(sum);
            break;
            
         }

         case 2:
         {
            printf("Enter the highest degree of the polynomial : ");
            scanf("%d",&n);
            n++;
            next_power_of_2 = 1;
            while (next_power_of_2 < n)
               next_power_of_2 <<= 1;
            a = (complex*)malloc(2 * next_power_of_2 * sizeof(complex));
            b = (complex*)malloc(2 * next_power_of_2 * sizeof(complex));
            complex*sum = (complex*)malloc(2 * next_power_of_2 * sizeof(complex));
            get_poly(a, n); // Getting input
            get_poly(b, n);
            poly_sub(sum, a, b, n);
            print_poly(sum, n);

            free(a);
            free(b);
            free(sum);
            break;
            
         }

         case 3:
         {
            printf("Enter the highest degree of the polynomial : ");
            /* Reading size of coefficient array */
            scanf("%d",&n);
            n++;
            next_power_of_2 = 1;
            while (next_power_of_2 < n)
               next_power_of_2 <<= 1;
            a = (complex*)malloc(2 * next_power_of_2 * sizeof(complex));
            b = (complex*)malloc(2 * next_power_of_2 * sizeof(complex));
            get_poly(a, n);
            get_poly(b, n);
            n = next_power_of_2; 
            /* Multipling polynomials */
            poly_mul(a, b, 2*n);
            print_poly(a, 2*n-1);
            free(a);
            free(b);
            break;
         }


         case 4:
         {
            printf("Enter the highest degree of the polynomial : ");
            scanf("%d",&n);
            n++;
            next_power_of_2 = 1;
            while (next_power_of_2 < n)
               next_power_of_2 <<= 1;
            a = (complex*)malloc(2 * next_power_of_2 * sizeof(complex));
            get_poly(a, n);
            poly_differentiate(a, n);
            print_poly(a, n);

            free(a);
            break;
            
         }


         case 5:
         {
            printf("Enter the highest degree of the polynomial : ");
            scanf("%d",&n);
            n++;
            next_power_of_2 = 1;
            while (next_power_of_2 < n)
               next_power_of_2 <<= 1;
            a = (complex*)malloc(2 * next_power_of_2 * sizeof(complex));
            get_poly(a, n);
            a[next_power_of_2].r=0;
            a[next_power_of_2].i=0;
            poly_integrate(a, n);
            print_poly(a, n+1);

            free(a);
            break;
            
         }


         case 6:
         {
            double a[100];
            int n;
            printf("Enter the highest degree of the polynomial : ");
            scanf("%d",&n);
            printf("Enter the coefficient of :\n");

            for(int i=n;i>=0;i--)
            {
               printf("x^%d : ",i);
               scanf("%lf",&a[i]);
            }

            // printf("Input - ");
            // for(int i=0;i<=n;i++)
            // if(a[n-i]>=0)
            //    printf(" +%.2lfx^%d",a[n-i],n-i);
            // else
            //    printf(" %.2lfx^%d",a[n-i],n-i);
            printf("\nThe roots of the polynomial are : ");
            roots(a, n);
            printf("\b\b\n");

         }

         case 0:
            break;
         
         default:
            printf("Invalid Input\n");
            printf("Please try aganin\n");
      }


   }while(choice);

   return 0;
}
