
//  Name this file: check.c
//  CheckingAccountLab
//
//  Student Name: Melanie Summers;
//  Student id: 012090935;
//  Name of the assignment: Checking Account Lab;
//  Date: 10/12/18;
//  Name and version of the C Compiler: Xcode v. 9.4.1;
//  Name of Operating System: Mac OS High Sierra v. 10.13.6;
//

#include <stdio.h>
#include <stdlib.h>

FILE *fp, *fpIn, *fpOut;
int main(void);
void outputHeaders(void);
void initialBalance(double amount, double *balance, double *service, double *openBalance);
void deposit(double amount, double *balance, double *service, int *numDeposit, double *amtDeposit);
void check(double amount, double *balance, double *service, int *numCheck, double *amtCheck);
void outputSummary(int numDeposit, double amtDeposit, int numCheck, double amtCheck, double openBalance, double service, double closeBalance);

int main(void) {
    char code;
    double amount, service, balance;
    double amtCheck, amtDeposit, openBalance, closeBalance;
    int numCheck, numDeposit;
    
    if(!(fpIn = fopen("/Users/melanie/Desktop/CSCI 112/CheckingAccountLab/CheckingAccountLab/CheckingAccountLab/account.txt", "r"))) {
        printf("account.txt could not be opened for input.");
        exit(1);
        //remember to change the above before submitting to professor
    }
    if(!(fpOut = fopen("csis.txt", "w"))) {
        printf("csis.txt could not be opened for output.");
        exit(1);
    }
    
    amount          = 0.0;
    service         = 0.0;
    balance         = 0.0;
    amtCheck        = 0.0;
    amtDeposit      = 0.0;
    openBalance     = 0.0;
    closeBalance    = 0.0;
    numCheck        = 0;
    numDeposit      = 0;
    
    outputHeaders();
    
    while(!feof(fpIn)) {
        fscanf(fpIn, "%c %lf\n", &code, &amount);
        if (code == 'I'){
            initialBalance(amount, &balance, &service, &openBalance);
        } else if (code == 'D') {
            deposit(amount, &balance, &service, &numDeposit, &amtDeposit);
        } else {
            check(amount, &balance, &service, &numCheck, &amtCheck);
        }
    }
    
    closeBalance = balance - service;
    outputSummary(numDeposit, amtDeposit, numCheck, amtCheck, openBalance, service, closeBalance);
    
    
    fclose(fpIn);
    fclose(fpOut);
    return 0;
}
       void outputHeaders(){

               printf(     "%11s %14s %14s %14s \n", "TRANSACTION", "DEPOSIT", "CHECK", "BALANCE");
               fprintf(fpOut, "%11s %14s %14s %14s \n", "TRANSACTION", "DEPOSIT", "CHECK", "BALANCE");
               
               printf(     "%11s %14s %14s %14s \n", "-----------", "-------", "-----", "-------");
               fprintf(fpOut, "%11s %14s %14s %14s \n", "-----------", "-------", "-----", "-------");
       }
       
       void initialBalance(double amount, double *balance, double *service, double *openBalance){
           *openBalance = amount;
               printf(          "%15s %40.2lf \n", "Initial Balance", *openBalance);
               fprintf(fpOut,   "%15s %40.2lf \n", "Initial Balance", *openBalance);
           
           *balance = *openBalance;
           //??? *service = 3; //the monthly service charge is 3 dollars... is this ok to put here and appropriate?
       }
       
       void deposit(double amount, double *balance, double *service, int *numDeposit, double *amtDeposit){
           
           *balance += amount;
           *amtDeposit += amount;
           (*numDeposit)++;
            *service += .03;
           
           printf(          "%7s %18.2lf %29.2lf \n", "Deposit", amount, *balance);
           fprintf(fpOut,   "%7s %18.2lf %29.2lf \n", "Deposit", amount, *balance);
       }
       
       void check(double amount, double *balance, double *service, int *numCheck, double *amtCheck){
           *balance -= amount;
           
           *amtCheck += amount;
           (*numCheck)++;
           *service += .06;
           
           printf(          "%7s %33.2lf %14.2lf \n", "Check", amount, *balance);
           fprintf(fpOut,   "%7s %33.2lf %14.2lf \n", "Check", amount, *balance);
           
           //Question: is this correct and ok below???
           if(*balance < 0){
               *service += 5.00;
           }
       }
       
       void outputSummary(int numDeposit, double amtDeposit, int numCheck, double amtCheck, double openBalance, double service, double closeBalance){
           
           //how do I ge the closing balance?
           closeBalance = *balance;
           printf(          "%22s %5d \n", "Total number deposits: ", numDeposit);
           fprintf(fpOut,   "%22s %5d \n", "Total number deposits: ", numDeposit);
           
           printf(          "%22s %5.2lf \n", "Total amount deposits: ", amtDeposit);
           fprintf(fpOut,   "%22s %5.2lf \n", "Total amount deposits: ", amtDeposit);
           
           printf(          "%22s %5.2lf \n", "Total service charge: ", service);
           fprintf(fpOut,   "%22s %5.2lf \n", "Total service charge: ", service);
           
           printf(          "%22s %5.2lf \n", "Opening Balance: ", openBalance);
           fprintf(fpOut,   "%22s %5.2lf \n", "Opening Balance: ", openBalance);
           
           printf(          "%22s %5.2lf \n", "Closing Balance: ", closeBalance);
           fprintf(fpOut,   "%22s %5.2lf \n", "Closing Balance: ", closeBalance);
           
       }
