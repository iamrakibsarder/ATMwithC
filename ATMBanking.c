#include <stdio.h>
#include <windows.h>
#include <time.h>

int main(){

    system("color 3F");

    int pin =1234, option, enteredPin, count=0, amount = 1;
    float balance = 5000;
    int continueTransaction = 1;


    time_t t = time(NULL);
    printf("\t\t\t\t Current date and time is : %s", ctime(&t));

    printf("\n\n");

    printf("\n\t\t\t\t =======================ATM Banking=================== \n\n");

    while(pin != enteredPin){
        printf("Enter your Pin : \n");
        scanf("%d", &enteredPin);

        if( enteredPin != pin ){
            Beep(800,600);
            printf("Invalid Pin \n\n");
        }

        count++;

        if(count == 3 & enteredPin != pin){

            printf("You tried the Maximum time!\n");
            exit(0);

        }
    }


    while(continueTransaction != 0){
        printf("\n\t\t\t\t ===================Available Withdrawals=============== \n\n");
    printf("\n\n \t 1. Withdrawals");
    printf("\n\n \t 2. Deposite");
    printf("\n\n \t 3. Check Balance");

    printf("\n\n \t Please select the option: ");
    scanf("%d", &option);

    switch(option){
    case 1:
        while(amount % 500 != 0){
            printf("\n\n \t Enter the Amount : ");

            scanf("%d", &amount);

            if(amount % 500 != 0){
                printf("\n\n \t Amount should be multiple of 500 ");
            }
        }

        if(balance < amount){
            printf("\n\n \t Sorry insufficient Balance!");
            amount = 1;
            break;
        }else{
            balance -= amount;
            printf("\n\n \t You've Withdrawn Tk %d. You current Balance is : %.2f", amount, balance);
            printf("\n\n\n\t\t\t\t ===================Thank you for Banking=============== \n\n");
            amount = 1;
            break;
        }

    case 2:
        printf("\n\n \t Enter the Amount : ");
        scanf("%d", &amount);
        balance += amount;

        printf("\n\n \t You've Deposited Tk %d. Your Current Balance is : %.2f", amount, balance);
        printf("\n\n\n\t\t\t\t ===================Thank you for Banking=============== \n\n");
        amount = 1;
        break;

        case 3:
        printf("\n\n \t Your balance is %.2f", balance);
        break;

        default:
        Beep(800,600);
        printf("\n\n \t Please choose a valid option !!!");

    }




        printf("\n\n \t Do you like to Transaction again? Press 1 for [Yes] and 0 for [No] ");
        scanf("%d", &continueTransaction);
    }



    return 0;
}
