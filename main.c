
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
    
    if(!(fpIn = fopen("account.txt", "r"))) {
        printf("account.txt could not be opened for input.");
        exit(1);
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
       void outputHeaders(void){
           //print out the transaction, deposit and check, and balance headers on page 230
           
       }
       
       void initialBalance(double amount, double *balance, double *service, double *openBalance){
           
       }
       
       void deposit(double amount, double *balance, double *service, int *numDeposit, double *amtDeposit){
           
       }
       
       void check(double amount, double *balance, double *service, int *numCheck, double *amtCheck){
           
       }
       
       void outputSummary(int numDeposit, double amtDeposit, int numCheck, double amtCheck, double openBalance, double service, double closeBalance){
           
       }
