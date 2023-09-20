#include <stdio.h>
#include <stdlib.h>

int main(){
    float wage, net_salary, inss, ir;

    printf("\n Welcome to salary calculation!\n");
    printf("\n================================\n");

    printf("\n Enter gross salary: ");
    scanf("%f", &wage);

    if(wage <= 1320.00) {
        inss = wage * 0.08;
    }
    else 
     if(wage >= 1320.00 && wage <= 2822.60){
            inss = wage * 0.09;
        }
     else
     if (wage >= 5220.40)
            {
                inss = wage * 0.11;
            }
    
    //Calculate the ir
    if (wage <= 2822.05)
    {
        ir = 0;
    }
    else
    if (wage >= 2822.60 && wage <= 3225.50)
    {
        ir = wage * 0.08;
    }
    else 
    if (wage >= 3225.50 && wage <= 5220.40)
    {
        ir = wage * 0.10;
    }
    else
    if (wage >= 5220.40)
    {
        ir = wage * 0.12;
    }
    //Net salry calculation
    net_salary = (wage - inss) - ir;
    //Result
    printf("\n================================\n");
    printf("\nPayroll Deduction (PRD)\n");
    printf("\nINSS: %f\n",inss);
    printf("\nIR: %f\n", ir);
    printf("\n================================\n");
    printf("\nNet salary deposited: %f\n",net_salary);
    printf("\n================================\n");
    
    return 0;    
}