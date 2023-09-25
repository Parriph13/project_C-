#include <stdio.h>
#include <stdlib.h>

int main(){
    int day;

    printf("\nRestaurant Brazilian menu");
    printf("\n===============================\n");
    printf("\nHello, everything is fine?\n");
    printf("We will show you the options\nof the days on the menu.\n");
    printf("\n===============================\n");
    printf("\nFor each day, you must choose\nto enter a number according\nto what you want, then you will\nbe shown the option and tour\ndesired price.\n");
    printf("\n(1)Sunday: Macarrão na chapa\t");
    printf("\t(2)Monday: Frango com quiabo\t");
    printf("\n(3)Tuesday: Arroz temperado\t");
    printf("\t(4)Wednesday: Frango frito\t");
    printf("\n(5)Thursday: Arroz e acarajé\t");
    printf("\t(6)Friday: Feijoada\t");
    printf("\n(7)Saturday: Churrasco\t");
    printf("\nOption: ");
    scanf("%d", &day);

    switch (day)
    {
    case 1:
        printf("Macarrão na chapa:\nPrice: 18.80");
        break;
    case 2:
        printf("Frango com quiabo:\nPrice: 15.80");
        break;
    case 3:
        printf("Arroz temperado(addition option):\nPrice: 15.80");
        break;
    case 4:
        printf("Frango frito(addition option):\nPrice: 19.80");
        break;
    case 5:
        printf("Arroz e acarajé(addition option):\nPrice: 18.80");
        break;
    case 6:
        printf("Feijoada:\nPrice: 17.80");
        break;
    case 7:
        printf("Churrasco(addition option):\nPrice Kg: 18.80");
        break;        
    default:
        printf("Sorry, we didn't find this type of option :(");
        break;
    }
    
    
    return 0;
}
