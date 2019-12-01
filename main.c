#include <stdio.h>
#include "myBank.h"

int main() {
  char option;
  float amount = 0;
  int interest_rate = 0;
  int account_num = 0;
  float value_return = 0;

  do{
    printf("\n****Welcame to my Bank*****\n");
    printf("\nO : for open new account and deposit cash");
    printf("\nB : for check the balance");
    printf("\nD : for deposit in account");
    printf("\nW : for withdraw cash from account");
    printf("\nC : close account");
    printf("\nI : to add interest rate for all accounts");
    printf("\nP : print all account and the balance");
    printf("\nE : to Exit from the program and close all the accounts");
    printf("\nPlease choose option:");
    scanf(" %c", &option);

    switch (option) {
      case 'O':
      printf("\nInitial deposit?: ");
      if(scanf("%f" ,&amount) != 1){
        printf("only numbers\n");
        break;
      }
      value_return = openAccount(amount);
      if (value_return > 0){
        printf("Successfully deposites!\n");
        printf("Account number: %.0f\n",value_return);
      }else
      printf("cannot open more account!\n");
      break;
      case 'B':
      printf("\nAccount number?: ");
      if(scanf(" %d" ,&account_num) != 1){
        printf("only numbers from 901 to 950!\n");
        break;
      }
      value_return = checkBalance(account_num);
      if(value_return > 0){
        printf("In account:%d, Have %.2f cash\n",account_num,value_return);
      }else
      printf("There is not number account like this\n");
      break;
      case 'D':
      printf("\nAccount number?: ");
      if(scanf(" %d" ,&account_num) != 1){
        printf("only numbers from 901 to 950!\n");
        break;
      }
      printf("\nInitial deposit?: ");
      if(scanf(" %f" ,&amount) != 1){
        printf("only numbers\n");
        break;
      }
      value_return = depositCash(account_num,amount);
      if(value_return > 0){
        printf("In account:%d, Have now:%.2f cash\n" ,account_num,value_return);
      }else
      printf("There is not number account like this\n");
      break;
      case 'W':
      printf("\nAccount number?: ");
      if(scanf(" %d" ,&account_num) != 1){
        printf("only numbers from 901 to 950!\n");
        break;
      }
      printf("\nInitial deposit?: ");
      if(scanf(" %f" ,&amount) != 1){
        printf("only numbers\n");
        break;
      }
      value_return = withdrawCash(account_num,amount);
      if(value_return > 0){
        printf("In account:%d, Have now:%.2f cash\n" ,account_num,value_return);
      }else
      printf("The account is not open OR dont have enough money to withdraw\n");
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
      printf("There is not number account like this\n");
      break;
      case 'I':
      printf("\nInterest rate?: ");
      if(scanf(" %d" ,&interest_rate) != 1){
        printf("only numbers\n");
        break;
      }
      addInterest(interest_rate);
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
