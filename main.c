#include <stdio.h>
#include "myBank.h"

int main() {
  char option;
  float amount = 0;
  int account_num = 0;
  float value_return = 0;
  int interest_rate = 0;

  do{
    printf("\n****Welcame to my Bank*****\n");
    printf("\nO : Opening a new account and depositing money");
    printf("\nB : Balance check");
    printf("\nD : Deposit into account");
    printf("\nW : Withdraw from account");
    printf("\nC : Close account");
    printf("\nI : Adding interest rate for all accounts");
    printf("\nP : Print accounts number and the balance");
    printf("\nE : Exit from the program and close the accounts");
    printf("\nPlease choose option:");
    scanf(" %c", &option);

    switch (option) {
      case 'O':
      printf("\nInitial deposit?:");
      if(scanf("%f" ,&amount) != 1){
        printf("only positive numbers!\n");
        break;
      }
      value_return = openAccount(amount);
      if (value_return > 0){
        printf("\nAccount created successfully!\n");
        printf("Account number: %.0f\n",value_return);
      }else
      printf("could not open more account OR worng value\n");
      break;
      case 'B':
      printf("\nAccount number?: ");
      if(scanf(" %d" ,&account_num) != 1){
        printf("only numbers from 901 to 950!\n");
        break;
      }
      value_return = checkBalance(account_num);
      if(value_return >= 0){
        printf("In account:%d, Have %.2f cash\n",account_num,value_return);
      }else
      printf("There is no account number like you entered\n");
      break;
      case 'D':
      printf("\nAccount number?: ");
      if(scanf(" %d" ,&account_num) != 1){
        printf("only numbers from 901 to 950!\n");
        break;
      }
      printf("\nInitial deposit?: ");
      if(scanf(" %f" ,&amount) != 1){
        printf("only positive numbers!\n");
        break;
      }
      value_return = depositCash(account_num,amount);
      if(value_return > 0){
        printf("In account:%d, Have now:%.2f cash\n" ,account_num,value_return);
      }else
      printf("There is no account number like you entered\n");
      break;
      case 'W':
      printf("\nAccount number?: ");
      if(scanf(" %d" ,&account_num) != 1){
        printf("only numbers from 901 to 950!\n");
        break;
      }
      printf("\nInitial deposit?: ");
      if(scanf(" %f" ,&amount) != 1){
        printf("only positive numbers\n");
        break;
      }
      value_return = withdrawCash(account_num,amount);
      if(value_return >= 0){
        printf("In account:%d, Have now:%.2f cash\n" ,account_num,value_return);
      }else
      printf("There is no account number like you entered OR dont have enough money to withdraw\n");
      break;
      case 'C':
      printf("\nAccount number?: ");
      if(scanf(" %d" ,&account_num) != 1){
        printf("only numbers from 901 to 950!\n");
        break;
      }
      value_return = closeAccount(account_num);
      if(value_return == 1){
        printf("The account is closed\n");
      }else
      printf("There is no account number like you entered\n");
      break;
      case 'I':
      printf("\nInterest rate?: ");
      if(scanf(" %d" ,&interest_rate) != 1){
        printf("only positive numbers\n");
        break;
      }
      if(interest_rate > 0){
        addInterest(interest_rate);
        printf("Added successfully\n");
      }else
      printf("only positive numbers\n");
      break;
      case 'P':
      print_account();
      break;
      case 'E':
      closeAll();
      printf("Goodbye\n");
      break;
      default:
      printf("\nPlease choose only from the options\n");
    }
  }
  while(option != 'E');

  return 0;
}
