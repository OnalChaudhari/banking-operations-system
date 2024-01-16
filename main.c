#include "valid.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int c = 0;
#define max 50

struct BankAccount {


  char bankName[max];
  char ifscCode[max];
  char accountNo[10];

  char firstName[max];
  char middleName[max];
  char lastName[max];

  int age;
  char gender[6];
  char DOB[11];
  char address[max];
  char city[max];
  char accType[max];
  int balance;
  char pan[max];
  char aadhar[20];
}b[20];

char * generateAccountNo(char fnm[], char mnm[], char lnm[]) {
  char fname[20];
  char mname[20];
  char lname[20];
  strcpy(fname, fnm);
  strcpy(mname, mnm);
  strcpy(lname, lnm);

  char accInitials[14];

  accInitials[0] = fname[0];
  accInitials[1] = mname[0];
  accInitials[2] = lname[0];
  accInitials[3] = '\0';

  int lower = 111;
  int upper = 999;

  int rnum = (rand() % (upper - lower + 1)) + lower;
  char rnum2[10];

  sprintf(rnum2, "%d", rnum);

  return strcat(accInitials, rnum2);
}
struct BankAccount createAccount()
{
  getchar();
  struct BankAccount b;
  int age;
  char gender[max];
  int genderCh;
  char tempDate[20];
  char address[max];
  char tempPan[20];
  char city[max];
  int accTypeCh;
  char tempAadhar[20];

  // printf("\nHow many records do you want to enter : ");
  // scanf("%d", &n);
  // getchar();


    strcpy(b.bankName, "State Bank of India");
    strcpy(b.ifscCode, "SBIN007");
    b.balance = 0;


    char fname[max];
    char mname[max];
    char lname[max];

  fname:
    printf("\nEnter First Name : ");
    fgets(fname, max, stdin);
    fname[strlen(fname) - 1] = '\0';

    for(int i = 0 ; i < strlen(fname) ; i++)
      {
        fname[i]=toupper(fname[i]);
      }

    if (isAlphaString(fname)) {
      strcpy(b.firstName, fname);
    } else {
      printf("\nInvalid first Name");
      goto fname;
    }

  mname:
    printf("\nEnter Middle Name : ");
    fgets(mname, max, stdin);
    mname[strlen(mname) - 1] = '\0';
  

    if (isAlphaString(mname)) {
      for(int i = 0 ; i < strlen(mname) ; i++)
      {
        mname[i]=toupper(mname[i]);
      }
      strcpy(b.middleName, mname);
    } else {
      printf("\nInvalid Middle Name");
      goto mname;
    }

  lname:
    printf("\nEnter Last Name : ");
    fgets(lname, max, stdin);
    lname[strlen(lname) - 1] = '\0';

    
    if (isAlphaString(lname)) {
      for(int i = 0 ; i < strlen(lname) ; i++)
      {
        lname[i]=toupper(lname[i]);
      }
      strcpy(b.lastName, lname);
    } else {
      printf("\nInvalid last Name");
      goto lname;
    }

  Age:
    printf("\nEnter Age : ");
    scanf("%d", &age);
    getchar();

    if (isValidAge(age)) {
      b.age = age;
    } else {
      printf("\nInvalid Age");
      goto Age;
    }

  gender:
    printf("\nEnter Gender : \n 1: Male \n 2: Female \n 3: Others \n");
    scanf("%d", &genderCh);
    getchar();

    if (genderCh == 1) {
      strcpy(b.gender, "Male");
    } else if (genderCh == 2) {
      strcpy(b.gender, "Female");
    } else if (genderCh == 3) {
      strcpy(b.gender, "Others");
    } else {
      printf("\nInvalid Choice");
      goto gender;
    }

  date:
    printf("\nEnter Date of Birth(dd/mm/yyyy) : ");
    fgets(tempDate, max, stdin);
    tempDate[strlen(tempDate) - 1] = '\0';

    if (isValidDate(tempDate)) {
      strcpy(b.DOB, tempDate);
    } else {
      printf("\nInvalid date of birth");
      goto date;
    }

    printf("\nEnter Address : ");
    fgets(address, max, stdin);
    address[strlen(address) - 1] = '\0';
    strcpy(b.address, address);

    printf("\nEnter City : ");
    fgets(city, max, stdin);
    city[strlen(city) - 1] = '\0';
    strcpy(b.city, city);

    //  char accType[max];
  AccType:
    printf("\nEnter Account Type : \n 1: Current \n 2: Saving \n 3: Joint "
           "Account \n");
    scanf("%d", &accTypeCh);
    getchar();

    if (accTypeCh == 1) {
      strcpy(b.accType, "Current");
    } else if (accTypeCh == 2) {
      strcpy(b.accType, "Saving");
    } else if (accTypeCh == 3) {
      strcpy(b.accType, "Joint Account");
    } else {
      printf("\nInvalid Account Type");
      goto AccType;
    }

  pan:

    printf("\nEnter PAN Number : ");
    fgets(tempPan, max, stdin);
    tempPan[strlen(tempPan) - 1] = '\0';

    if (isValidPAN(tempPan)) {
      strcpy(b.pan, tempPan);
    } else {
      printf("\nInvalid PAN Number");
      goto pan;
    }

  aadhar:
    printf("\nEnter Aadhar Number : ");
    fgets(tempAadhar, 20, stdin);
    tempAadhar[strlen(tempAadhar) - 1] = '\0';

    if (isValidAadhar(tempAadhar)) {
      strcpy(b.aadhar, tempAadhar);
    } else {
      printf("\nInvalid Aadhar Number");
      goto aadhar;
    }
  
    srand(time(0));

    char n[20];
    strcpy(n,generateAccountNo(b.firstName, b.middleName, b.lastName));
    strcpy(b.accountNo, n);

  printf("Details added successfully...");
  
return b;

    
  
  }


void sortRecords(struct BankAccount b[] , int c) {
  int i, j;
  struct BankAccount temp;
  for (i = 0; i < c; i++) {
    for (j = i + 1; j < c; j++) {
      if (strcmp(b[i].accountNo, b[j].accountNo) > 0) {
        temp = b[i];
        b[i] = b[j];
        b[j] = temp;
      }
    }
  }
  printf("Records sorted successfully\n");

}

void updateDetails(struct BankAccount b[], int c) {
  getchar();
  printf("\ninside update \n");

  char accNo[10];
  printf("Enter the account number whose details you want to update : ");
  fgets(accNo, 10, stdin);
  accNo[strlen(accNo) - 1] = '\0';

  int found = 0;
  for (int i = 0; i < c; i++) {
    if (strcmp(b[i].accountNo, accNo) == 0) {
      found = 1;
      printf("\n\t1. update name of account holder\n\t2. update address\n\t3. "
             "update DOB\n\t4. return to main menu\n");

      int choice;
      do {
        printf("\tEnter your choice");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
        case 1: {
          char fname[max];
          char mname[max];
          char lname[max];

        fname:
          printf("\nEnter First Name : ");
          fgets(fname, max, stdin);
          fname[strlen(fname) - 1] = '\0';
          for(int i = 0 ; i < strlen(fname) ; i++)
          {
            fname[i]=toupper(fname[i]);
          }

          if (isAlphaString(fname)) {
            strcpy(b[i].firstName, fname);
          } else {
            printf("\nInvalid first Name");
            goto fname;
          }

        mname:
          printf("\nEnter Middle Name : ");
          fgets(mname, max, stdin);
          mname[strlen(mname) - 1] = '\0';
          
          for(int i = 0 ; i < strlen(mname) ; i++)
          {
            mname[i]=toupper(mname[i]);
          }

          if (isAlphaString(mname)) {
            strcpy(b[i].middleName, mname);
          } else {
            printf("\nInvalid Middle Name");
            goto mname;
          }

        lname:
          printf("\nEnter Last Name : ");
          fgets(lname, max, stdin);
          lname[strlen(lname) - 1] = '\0';
          for(int i = 0 ; i < strlen(lname) ; i++)
          {
            lname[i]=toupper(lname[i]);
          }

          if (isAlphaString(lname)) {
            strcpy(b[i].lastName, lname);
          } else {
            printf("\nInvalid last Name");
            goto lname;
          }
          /*
                  char fname[max];
                  char mname[max];
                  char lname[max];

                  printf("\tEnter first name : ");
                  fgets(fname,max,stdin);
                  fname[strlen(fname)-1]='\0';

                  printf("\tEnter middle name : ");
                  fgets(mname,max,stdin);
                  mname[strlen(mname)-1]='\0';

                  printf("\tEnter last name : ");
                  fgets(lname,max,stdin);
                  lname[strlen(lname)-1]='\0';   */

          strcpy(b[i].firstName, fname);
          strcpy(b[i].middleName, mname);
          strcpy(b[i].lastName, lname);

          printf("Details updated successfully\n");
          break;
        }

        case 2: {
          char add[10];
          printf("Enter address : ");
          fgets(add, max, stdin);
          add[strlen(add) - 1] = '\0';

          strcpy(b[i].address, add);
          printf("Details updated successfully\n");
          break;
        }
        case 3: {
          char dob[10];
          printf("Enter DOB : ");
          fgets(dob, max, stdin);
          dob[strlen(dob) - 1] = '\0';

          if (isValidDate(dob)) {
            strcpy(b[i].DOB, dob);
          } else {
            printf("Invalid date");
          }
          printf("Details updated successfully\n");
          break;
        }
        case 4: {
          printf("Returning to main menu\n");
          break;
        }
        default: {
          printf("Invalid choice\n");
          break;
        }
        }

      } while (choice != 4);

    } // end if

  } // for loop
  if (found == 0) {
    printf("Account not found\n");
  }
  return;
}

//void createAccount(struct BankAccount b[], int n) {}

void checkBalance(struct BankAccount b[], int c) {
  getchar();
  char accNo[10];
  printf("Enter the account number to check balance: ");
  fgets(accNo, 10, stdin);
  accNo[strlen(accNo) - 1] = '\0';
  int found = 0;
  for (int i = 0; i < c; i++) {
    if (strcmp(b[i].accountNo, accNo) == 0) {
      found = 1;
      printf("Balance : %d ", b[i].balance);
    }
  }
  if (found == 0) {
    printf("Account not found\n");
  }
}

void transferFunds(struct BankAccount b[], int c) {
  getchar();
 // printf("\nInside transferFunds");

  printf("\nEnter the account number from which to transfer funds: ");
  char accNo[10];
  fgets(accNo, 10, stdin);
  accNo[strlen(accNo) - 1] = '\0';

  printf("\nEnter the amount: ");
  int amount;
  scanf("%d", &amount);
  getchar();

  if (amount == 0 || amount < 0) {
    printf("Invalid amount\n");
    return;
  }

  int isPresentS = 0;
  int sufBal = 0;
  int senderIndex = 0;
  int balance;

  for (int i = 0; i < c; i++) {
    if (strcmp(b[i].accountNo, accNo) == 0) {
      isPresentS = 1;
      senderIndex = i;
      if (b[i].balance >= amount) {
        sufBal = 1;
        //  break;
      }
    }
  }
  if (isPresentS == 0) {
    printf("Sender account not found");
    return;
  } else if (balance == 0) {
    printf("No balance in the sender's account");
    return;
  } else if (sufBal == 0) {
    printf("Insufficient balance");
    return;
  }

  printf("Enter the account number to which to transfer funds: ");
  char accNo1[10];
  fgets(accNo1, 10, stdin);
  accNo1[strlen(accNo1) - 1] = '\0';

  int isPresentR = 0;
  int recIndex = 0;
  for (int i = 0; i < c; i++) {
    if (strcmp(b[i].accountNo, accNo1) == 0) {
      isPresentR = 1;
      recIndex = i;
      break;
    }
  }
  if (isPresentR == 0) {
    printf("Receiver account not found");
    return;
  }
  // if(isPresentS==1 && isPresentR==1 && sufBal==1 && senderIndex != recIndex
  // && amount>0 && amount<=b[senderIndex].balance)
  // {
  b[senderIndex].balance -= amount;
  b[recIndex].balance += amount;
  printf("Transfer successful");

  // printf("%d ",isPresentS);
  // printf("%d ",isPresentR);
  //   printf("%d ",sufBal);
  //   printf("%d ",senderIndex);
  //   printf("%d ",recIndex);
  //   printf("%d ",amount);
  //   printf("%d ",b[senderIndex].balance);

  return;
  // }
}

// for(int i=0;i<n;i++){
//   if(strcmp(b[i].accountNo,accNo) == 0)
//   {
//     if(b[i].balance >= amount)
//     {
//       b[i].balance -= amount;
//       flag=1;
//     }
//     else{
//       printf("Insufficient balance");
//       return;
//     }
//   }
// }
// if(flag == 1)
// {

//   for(int i=0;i<n;i++)
//     {
//       if(strcmp(b[i].accountNo,accNo1) == 0)
//       {
//         b[i].balance += amount;
//         printf("Amount transfered from %s account to %s
//         account",accNo,accNo1);
//       }

//     }
// }
// else{
//   printf("Insufficient balance");
// }

// printf("Enter account number to which you want to transfer funds: ");

// int amount;
// printf("Enter the amount to transfer: ");
// scanf("%d",&amount);
// for(int i=0;i<n;i++)
//   {
//     if(strcmp(b[i].accountNo,accNo) == 0)

void withdraw(struct BankAccount b[], int c) {
  getchar();
 // printf("Inside Withdraw");
  char accNo[10];

  printf("Enter the account number : ");
  fgets(accNo, 10, stdin);
  accNo[strlen(accNo) - 1] = '\0';

  int found = 0;
  for (int i = 0; i < c; i++) {
    if (strcmp(b[i].accountNo, accNo) == 0) {
      found = 1;
      if (b[i].balance == 0) {
        printf("Balance is 0...Please deposit some amount");
      } else if (b[i].balance > 0) {
        int amount;
        printf("Enter the amount to withdraw: \n");
        scanf("%d", &amount);
        getchar();

        if (amount <= b[i].balance) {
          b[i].balance -= amount;
          printf("Amount Withdrawn Seccessfully...\n");
        }

        else
          printf("Insufficient balance");
      }
    }
  }
  if (found == 0) {
    printf("Account not found");
  }
}

void deposit(struct BankAccount b[], int c) {
  getchar();
 // printf("Inside Deposit");

  int found = 0;
  char accNo[10];
  printf("Enter the account number: ");
  fgets(accNo, 10, stdin);
  accNo[strlen(accNo) - 1] = '\0';


  for (int i = 0; i < c; i++) {
    if (strcmp(b[i].accountNo, accNo) == 0) 
    {
      found = 1;
      int amount;
      printf("Enter the amount to deposit: \n");
      scanf("%d", &amount);
      getchar();

      if (amount == 0 || amount < 0) {
        printf("Invalid amount");
        return;
      }
      b[i].balance += amount;
      printf("Amount Deposited Seccessfully...\n");
    }
  }
  if (found == 0) {
    printf("Account not found");
  }
}

void search(struct BankAccount b[], int c) {

  printf("Choose search method : \n");
  printf("\t1. Search by Account Number\n");
  printf("\t2. Search by Name\n");
  printf("\t3. Search by Account Type\n");
  printf("\t4. Return to main menu\n");

  int choice;
  printf("Enter your choice : ");
  scanf("%d", &choice);
  getchar();

  switch (choice) {
  case 1: {
    char accNo[10];
    printf("Enter the account number to be searched: ");
    fgets(accNo, 10, stdin);
    accNo[strlen(accNo) - 1] = '\0';

    for (int i = 0; i < c; i++) {
      if (strcmp(b[i].accountNo, accNo) == 0) {
        printf("Account found\n");
        printf("Account Number: %s\n", b[i].accountNo);
        printf("Name: %s %s %s\n", b[i].firstName, b[i].middleName,
               b[i].lastName);
        printf("Age: %d\n", b[i].age);
        printf("Gender: %s\n", b[i].gender);
        printf("Date of Birth: %s\n", b[i].DOB);
        printf("Address: %s\n", b[i].address);
        printf("City: %s\n", b[i].city);
        printf("Account Type: %s\n", b[i].accType);
        printf("Balance: %d\n", b[i].balance);
        printf("PAN: %s\n", b[i].pan);
        printf("Aadhar: %s\n", b[i].aadhar);
        return;
      }
    }
    printf("Account not found\n");
  } break;

  case 2: {

    char fname[max];
    char mname[max];
    char lname[max];

  fname:
    printf("\nEnter First Name : ");
    fgets(fname, max, stdin);
    fname[strlen(fname) - 1] = '\0';

    if (!isAlphaString(fname)) {
      // strcpy(b[i].firstName,fname);
      printf("\nInvalid first Name");
      goto fname;
    }

  mname:
    printf("\nEnter Middle Name : ");
    fgets(mname, max, stdin);
    mname[strlen(mname) - 1] = '\0';

    if (!isAlphaString(mname)) {
      // strcpy(b[i].firstName,fname);
      printf("\nInvalid middle Name");
      goto mname;
    }

  lname:
    printf("\nEnter Last Name : ");
    fgets(lname, max, stdin);
    lname[strlen(lname) - 1] = '\0';

    if (!isAlphaString(lname)) {
      // strcpy(b[i].firstName,fname);
      printf("\nInvalid last Name");
      goto lname;
    }
    /*    char fname[max],lname[max],mname[max];


        printf("Enter the first name : ");
        fgets(fname,max,stdin);
        fname[strlen(fname)-1] = '\0';

        printf("Enter the middle name : ");
        fgets(mname,max,stdin);
        mname[strlen(mname)-1] = '\0';

        printf("Enter the last name : ");
        fgets(lname,max,stdin);
        lname[strlen(lname)-1] = '\0';   */

    int accountFound = 0;
    for (int i = 0; i < c; i++) {
      if (strcmp(b[i].firstName, fname) == 0 &&
          strcmp(b[i].middleName, mname) == 0 &&
          strcmp(b[i].lastName, lname) == 0) 
      {
        accountFound = 1;
        printf("Account found\n");
      } 
    }
    if (accountFound == 0) { // If flag is not set, account is not found
      printf("%s %s %s not found\n", fname, mname, lname);
    }
  } 
  break;

  case 3: {
    char accType[max], found = 0;
    printf("Enter the account type to be searched: ");
    fgets(accType, max, stdin);
    accType[strlen(accType) - 1] = '\0';

    for (int i = 0; i < c; i++) {
      int c = 1;
      if (strcmp(b[i].accType, accType) == 0) {
        found = 1;
        printf("Account %d with Account Type %s \n", c++, b[i].accType);
        printf("Account Number: %s\n", b[i].accountNo);
        printf("Name: %s %s %s\n", b[i].firstName, b[i].middleName,
               b[i].lastName);
        printf("Age: %d\n", b[i].age);
        printf("Gender: %s\n", b[i].gender);
        printf("Date of Birth: %s\n", b[i].DOB);
        printf("Address: %s\n", b[i].address);
        printf("City: %s\n", b[i].city);
        printf("Account Type: %s\n", b[i].accType);
        printf("Balance: %d\n", b[i].balance);
        printf("PAN: %s\n", b[i].pan);
        printf("Aadhar: %s\n", b[i].aadhar);
      }
    }
    if (found == 0) {
      printf("No Account with Account Type %s found\n", accType);
      return;
    } else {
      return;
    }

  } break;
  case 4: {
    printf("Returning to main menu\n");
    break;
  }
  default: {
    printf("Invalid choice\n");
    break;
  }
  }

  return;
}


void display(struct BankAccount b[], int c) {
  for (int i = 0; i < c; i++) {
    printf("\n-----------------Details for Account %d-----------------\n",
           i + 1);
    printf("\nBank Name : %s", b[i].bankName);
    printf("\nIFSC Code : %s", b[i].ifscCode);
    printf("\nAccount No : %s", b[i].accountNo);
    printf("\nBalance : %d", b[i].balance);

    printf("\nFirst Name : %s", b[i].firstName);
    printf("\nMiddle Name : %s", b[i].middleName);
    printf("\nLast Name : %s", b[i].lastName);

    printf("\nAge : %d", b[i].age);
    printf("\nGender : %s", b[i].gender);
    printf("\nDate of Birth : %s", b[i].DOB);
    printf("\nAddress : %s", b[i].address);
    printf("\nCity : %s", b[i].city);
    printf("\nAccount Type : %s", b[i].accType);
    printf("\nPAN number : %s", b[i].pan);
    printf("\nAadhar : %s", b[i].aadhar);
  }
}

int main() {

  // int n;
  // printf("\nHow many records do you want to enter : ");
  // scanf("%d", &n);
  // getchar();

  int choice;

  do {
    printf("\n---------------------------Menu---------------------------\n");
    printf("\n1. Create account\n2. Update Account Details\n3. "
           "Deposit\n4. Withdraw\n5. Funds Transfer\n6. Search Details Of "
           "Account Holder\n7. Balance Enquiry\n8. Sort Records\n9. Display all accounts\n10. Exit\n");

    printf("\nEnter your choice : ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      b[c++] = createAccount( ) ;
      break;
    case 2:
      updateDetails(b, c);
      break;
    case 3:
      deposit(b, c);
      break;
    case 4:
      withdraw(b, c);
      break;
    case 5:
      transferFunds(b, c);
      break;
    case 6:
      search(b, c);
      break;
    case 7:
      checkBalance(b, c);
      break;
    case 8:
      sortRecords(b, c);
      break;
    case 9:
      display(b, c);
      break;

    case 10:
    printf("\nThank You");
    break;


    default:
      printf("\nInvalid Choice");
      break;
    }

  } while(choice!=10);

  return 0;
}