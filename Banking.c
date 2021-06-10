#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
int accnum=1000;
void strongPassword();
int rePassword(int);
void deposit(int);
void debit(int);
void bankBalance(int);
void moneyTransfer(int);
void accCreate();
void login();
struct customer
{
    int age;
    char name[100];
    char sex[100];
    char mobileNumber[110];
    int aadhaarNumber;
    int panNumber;
    int amount;
    char password[100];
    int status;
}accholder[10000];
void strongPassword()
{
    char temp[1000];
    int digit=0,alpha=0,char1=0;
    printf("Password must contain minimum of 8 characters with atleast 1 Upper case, 1 Special Character, 1 number\n");
    scanf(" %s",accholder[accnum-1000].password);
    strcpy(temp,accholder[accnum-1000].password);
    int l=strlen(accholder[accnum-1000].password);
    for(int i=0;i<l;i++)
    {
        if(isdigit(temp[i])!=0)
        {
            digit++;
        }
        else if(isalpha(temp[i])!=0)
        {
            if(isupper(temp[i]))
            alpha++;
        }
        else
        {
            char1++;
        }
    }
    if(!(digit>0 && alpha>0 && char1>0))
    {
        printf("Enter strong Password\n");
        strongPassword();
    }
}
int rePassword(int accnum1)
{
    char pasword[1000];
    printf("Enter your password\n");
    scanf("%s",pasword);
    if((strcmp((accholder[accnum1-1000].password),pasword))!=0)
    {
        int reenter;
        printf("Enter your correct password\nPress 1 to re-enter the password or press 0 to abord\n");
        scanf("%d",&reenter);
        if(reenter)
            rePassword(accnum1);
        else
            return 0;
    }
    else
    {
      return 1;
    }
}
void deposit(int accnum1)
{
    int amount1;
    printf("You have Rs.%d in your savings Account\n",accholder[accnum1-1000].amount);
    printf("Enter the amount to be deposit\n");
    scanf("%d",&amount1);
    accholder[accnum1-1000].amount = accholder[accnum1-1000].amount+amount1;
    printf("Now you have Rs.%d in your savings Account\n",accholder[accnum1-1000].amount);
}
void debit(int accnum1)
{
    int amount1;
    printf("You have Rs.%d in your savings Account\n",accholder[accnum1-1000].amount);
    printf("Enter the amount to be withdraw\n");
    scanf("%d",&amount1);
    accholder[accnum1-1000].amount=(accholder[accnum1-1000].amount)-amount1;
    printf("Now you have Rs.%d in your savings Account\n",accholder[accnum1-1000].amount);
}
void bankBalance(int accnum1)
{
    printf("Mr. %s\n",(accholder[accnum1-1000].name));
    printf("you have Rs.%d in your savings Account\n",(accholder[accnum1-1000].amount));
}
void moneyTransfer(int accnum2)
{
    int transferAct,number;
    int choice3,transferAmt;
    printf("Enter the Account Number to transfer Amount who have account in our bank\n");
    scanf("%d",&transferAct);
    while(transferAct < 1000 ||  transferAct > accnum || ((accholder[transferAct-1000].status)!= 1))
    {
        printf("You don't have account\n");
        printf("Press 1 to enter account Number or press 0 to abord\n");
        scanf("%d",&number);
        if(number)
        {
            printf("Enter your correct account Number\n");
            scanf("%d",&transferAct);
        }
        else
        {
            printf("your process failed\n");
            return;
        }
    }
    printf("Benifiary Name %s\n",accholder[transferAct-1000].name);
    printf("Enter the amount to be transferred\n");
    scanf("%d",&transferAmt);
    if(transferAmt > (accholder[accnum2-1000].amount) || abs(transferAmt - accholder[accnum2-1000].amount) < 5000)
    {
        printf("You don't have sufficient balance\nPress 1 to enter amount\npress 0 to go back\n");
        scanf("%d",&choice3);
        if(choice3>0)
        {
            moneyTransfer(accnum2);
        }
        else
        {
            return;
        }
    }
    else
    {
        (accholder[accnum2-1000].amount)-=transferAmt;
        (accholder[transferAct-1000].amount)+=transferAmt;
        printf("You had succesfully transferred Rs.%d to %d\n",transferAmt,transferAct);
        printf("Your current balance is %d\n",accholder[accnum2-1000].amount);
        return;
    }
}
void accCreate()
{
    printf("Enter your name:\n");
    scanf(" %[^\n]s",(accholder[accnum-1000].name));
    printf("Sex:\nMale\nFemale\nTransgender\n");
    scanf(" %s",(accholder[accnum-1000].sex));
    printf("Enter your Mobile Number\n");
    scanf(" %s",(accholder[accnum-1000].mobileNumber));
    printf("Enter your age\n");
    scanf("%d",&accholder[accnum-1000].age);
    printf("Enter your Aadhaar Number\n");
    scanf("%d",&(accholder[accnum-1000].aadhaarNumber));
    printf("Enter your PAN card Number\n");
    scanf("%d",&(accholder[accnum-1000].panNumber));
    printf("Your Minimum account balance must be greater than Rs.5000\nEnter intial amount greater than Rs.5000\n");
    scanf("%d",&(accholder[accnum-1000].amount));
    while((accholder[accnum-1000].amount)<5000)
    {
        printf("Your amount is insufficient\nEnter amount greater than Rs.5000\n");
        scanf("%d",&(accholder[accnum-1000].amount));
    }
    printf("Enter the password\n");
    strongPassword();
    accholder[accnum-1000].status=1;
    printf("\nThank you for joining in our family\n\nYour Account Number is %d\n\nYour password is %s\n",accnum,accholder[accnum-1000].password);
    printf("\nYour savings account balance is %d\n\n",accholder[accnum-1000].amount);
    accnum++;
}
void login()
{
    int accountNumber,number;
    char mobNum1[110];
    printf("Enter your mobile Number\n");
    scanf(" %s",mobNum1);
    printf("Enter your account Number\n");
    scanf("%d",&accountNumber);
    while(accountNumber < 1000 || accountNumber > accnum || ((accholder[accountNumber-1000].status)!= 1))
    {
        printf("You don't have account\n");
        printf("Press 1 to enter account Number or press 0 to abord\n");
        scanf("%d",&number);
        if(number)
        {
            printf("Enter your correct account Number\n");
            scanf("%d",&accountNumber);
        }
        else
        {
            printf("your process failed\n");
            return;
        }
    }
    if((strcmp((accholder[accountNumber-1000].mobileNumber),mobNum1))!=0)
    {
        do
        {
            printf("Your account Number does not match with your phone number\n");
            printf("Enter your Mobile Number\n");
            scanf(" %s",mobNum1);
            printf("Your Mobile Number is %s\n",mobNum1);
            printf("Enter your account Number\n");
            scanf("%d",&accountNumber);
            while(accountNumber < 1000 || accountNumber > accnum || ((accholder[accountNumber-1000].status)!= 1))
            {
              printf("You don't have account\n");
              printf("Press 1 to enter account Number or press 0 to abord\n");
              scanf("%d",&number);
              if(number)
              {
                printf("Enter your correct account Number\n");
                scanf("%d",&accountNumber);
              }
              else
              {
                printf("your process failed\n");
                return;
              }
            }
        }while((strcmp((accholder[accountNumber-1000].mobileNumber),mobNum1))!=0);

    }
    if(rePassword(accountNumber))
    {
        printf("\n                ##########  Welcome  ##########        \n");
        printf("\n             ######## Login successfully  #######      \n");
        printf("Name : %s\n",accholder[accountNumber-1000].name);
        printf("Account Number :%d\n",accountNumber);
        int choice1,num1;
        int transferAct;
        do
        {
            printf("Enter your choice\n1.Deposit\n2.Debit\n3.BankBalance\n4.Money Transfer\n5.logout\n");
            scanf("%d",&choice1);
            switch(choice1)
            {
                case 1:
                    deposit(accountNumber);
                    break;
                case 2:
                    debit(accountNumber);
                    break;
                case 3:
                    bankBalance(accountNumber);
                    break;
                case 4:
                    moneyTransfer(accountNumber);
                    break;
                 case 5:
                    printf("Logout made successfully\nThank You\n");
                    return;
                default:
                    printf("Enter a valid choice:\n");

            }
            printf("Press 1 to go Home Screen or 0 to logout\n");
            scanf("%d",&num1);
        }while(num1);
    }
    else
    {
        printf("Your Process Failed\nThank You\n");
    }
}
int main()
{
    int choice,num=1;
    printf("##########  Welcome to KVB Bank\n#######   We are here for you  ##############\n");
    do{
        printf("Enter your choice\n1.Create the account\n2.Login\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                accCreate();
                break;
            case 2:
                login();
                break;
            default:
            printf("Enter the valid choice\n");
        }
        printf("Enter 0 to abord or 1 to go Dashboard\n");
        scanf("%d",&num);
    }while(num);
    return 0;
}
