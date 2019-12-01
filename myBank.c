#include <stdio.h>
#include "myBank.h"
#define Num_Of_Accounts 50
#define account_number 0
#define account_cash 1
#define first_account 901

float accounts[Num_Of_Accounts][2] = {0};
float number_account = 0;
float balance_account = 0;

float towDigit(float x){
  return x = (100*x)/100;
}

int openAccount(float amount){
  if(amount > 0){
    amount = towDigit(amount);
    for(int i = 0; i < Num_Of_Accounts; i++){
      if(accounts[i][account_number] == 0){
        accounts[i][account_number] = i + first_account;
        accounts[i][account_cash] = amount;
        number_account = accounts[i][account_number];
        return i + first_account;
      }
    }
  }
  return 0;
}

float checkBalance(int account_num){
  for(int i = 0; i < Num_Of_Accounts; i++){
    if (accounts[i][account_number] == account_num){
      balance_account = accounts[i][account_cash];
      return balance_account;
    }
  }
  return -1;
}
float depositCash(int account_num, float amount){
  if(amount > 0){
    amount = towDigit(amount);
    for(int i = 0; i < Num_Of_Accounts; i++){
      if (accounts[i][account_number] == account_num){
        accounts[i][account_cash] += amount;
        balance_account = accounts[i][account_cash];
        return balance_account;
      }
    }
  }
  return 0;
}
float withdrawCash(int account_num, float amount){
  if(amount > 0){
    amount = towDigit(amount);
    for(int i = 0; i < Num_Of_Accounts; i++){
      if((accounts[i][account_number] == account_num) && (accounts[i][account_cash] >= amount)){
        accounts[i][account_cash] -= amount;
        balance_account = accounts[i][account_cash];
        return balance_account;
      }
    }
  }
  return -1;
}
int closeAccount(int account_num){
  for (int i = 0; i < Num_Of_Accounts; i++) {
    if(accounts[i][account_number] == account_num){
      accounts[i][account_number] = 0;
      accounts[i][account_cash] = 0;
      return 1;
    }
  }
  return 0;
}
void addInterest(int interest_rate){
  float sum = 0;
  for(int i = 0; i < Num_Of_Accounts; i++){
    if(accounts[i][account_number] != 0){
      sum = (accounts[i][account_cash]*interest_rate)/100;
      accounts[i][account_cash] += sum;
    }
    sum = 0;
  }
}
void print_account(){
  for(int i = 0; i < Num_Of_Accounts; i++){
    if(accounts[i][account_number] != 0){
      printf("Account number:%.0f, balance:%.2f\n",accounts[i][account_number],accounts[i][account_cash]);
    }
  }
}
void closeAll(){
  for (int i = 0; i < Num_Of_Accounts; i++) {
    for (int j = 0; j < 1; j++) {
      accounts[i][j] = 0;
    }
  }
}
