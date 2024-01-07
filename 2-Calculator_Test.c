#include "stdio.h"

int addition();
int subtract();
int multiply();
int divide();
void exit();

int main(){

    int opt;

    do
    {
        printf ("Choose an option to calculate the numbers. \n ");  
        printf ("1. Addition \t\t 2. Subtraction \t\t 3. Multiplication \n 4. Division \t\t 5. Exit the calculator \n\n");      
        scanf ("%d", &opt);

        printf("You chose option number of %d. \n", opt);  
        printf ("\n*******************************************\n"); 

        switch (opt){  
        case 1:  
            printf("This is for addition process. \n");
            addition();
            break;
              
        case 2:
            printf("This is for subtraction process. \n");  
            subtract();
            break;
              
        case 3:  
            printf("This is for multiplication process. \n");
            multiply(); 
            break; 
              
        case 4:  
            printf("This is for division process. \n");
            divide();
            break;
              
        case 5: 
            printf("The program exited. \n\n"); 
            exit(0);
            break; 
              
        default:  
            printf("Something is not right. Please Try Again!");  
            break;                        
    }  

        printf ("\n\n ########################################### \n\n");  

    } 
    while (opt != 5);
    
    return 0;
}


int addition(){
    int num1 = 0;
    int num2 = 0; 
    
    printf ("Enter the first number : ");  
    scanf("%d", &num1);
    
    printf ("Enter the second number : ");  
    scanf("%d", &num2);
    
    int sum = num1 + num2;
    printf("The numbers of %d + % d = %d", num1, num2, sum);
    return sum;
}

int subtract()  
{  
    int num1 = 0;
    int num2 = 0;

    printf ("Enter the first number : ");  
    scanf("%d", &num1);
    
    printf ("Enter the second number : ");  
    scanf("%d", &num2);

    int sub = num1 - num2;    
    printf ("The numbers of %d - %d = %d", num1, num2, sub);  

    return sub;
}  

int multiply()  
{  
    int num1 = 0;
    int num2 = 0;
 
    printf ("Enter the first number : ");  
    scanf("%d", &num1);
    
    printf ("Enter the second number : ");  
    scanf("%d", &num2); 

    int multip = num1 * num2;    
    printf ("The numbers of %d * %d = : %d", num1, num2, multip); 

    return multip; 
}  

int divide()  
{  
    int dividend = 0;
    int divisor = 0;

    printf ("Enter the first number for dividend : ");  
    scanf("%d", &dividend);
    
    printf ("Enter the second number for divisor : ");  
    scanf("%d", &divisor); 
      
    if (divisor == 0)  
    {  
        printf (" \n Divisor must not be Zero. Please enter another value! \n ");  
        scanf ("%d", &divisor);        
    }  

    int quotient = dividend / divisor;
    int remainder = dividend % divisor;

    printf("The numbers of %d / %d = %d\n", dividend, divisor, quotient);
    printf("The remainder number is %d. \n", remainder);    

    return quotient;
}  