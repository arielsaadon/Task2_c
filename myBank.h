#ifndef MYBANK
#define MYBANK
#define Num_Of_Accounts 50

extern float accounts[Num_Of_Accounts][2];

int openAccount(float amount);
float checkBalance(int account_num);
float depositCash(int account_num, float amount);
float withdrawCash(int account_num, float amount);
int closeAccount(int account_num);
void addInterest(int interest_rate);
void print_account();
void closeAll();

#endif
