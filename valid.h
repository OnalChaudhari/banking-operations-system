#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int isValidDate(char date[]) {
  
  int intYear = 0, intMonth = 0, intDay = 0;
  
  if (strlen(date) == 10) {
    for (int i = 0; i < 2; i++) {
      if (!isdigit(date[i]))
        return 0;
    }
    if (!date[5] == '/')
      return 0;

    if (!date[2] == '/') {
      return 0;
    }

    for (int i = 3; i < 5; i++) {
      if (!isdigit(date[i]))
        return 0;
    }
    
    for (int i = 6; i < 10; i++) {
      if (!isdigit(date[i]))
        return 0;
    }
    
    for (int i = 6; i < 10; i++) {
      char year[10];
      year[0] = date[6];
      year[1] = date[7];
      year[2] = date[8];
      year[3] = date[9];
      year[4] = '\0';
      
      intYear = atoi(year);
     
    }
      if (intYear > 2023) {
        return 0;
      }

   /* 
      char month[10];
      month[0] = date[6];
      month[1] = date[7];
      month[2] = '\0';

      intMonth = atoi(month);
      if (intMonth > 12) {
        return 0;
      }

    char day[10];
    day[0] = date[0];
    day[1] = date[1];
    day[2] = '\0';

    intDay = atoi(day);
    if (intDay > 31) {
      return 0;
    }   */

    return 1;
  }
  return 0;
}

int isValidAadhar(char aadhar[]) {
  if (strlen(aadhar) == 12) {

    for (int i = 0; i < 12; i++) {
      if (!isdigit(aadhar[i]))
        return 0;
    }
    return 1;
  }
  return 0;
}
int isValidAge(int age) {

  if (age < 18) {
    return 0;
  }

  return 1;
}
int isValidPAN(char pan[]) {
  if (strlen(pan) == 10) {

    for (int i = 0; i <= 4; i++) {
      if (!isupper(pan[i]))
        return 0;
    }
    for (int i = 5; i <= 8; i++) {
      if (!isdigit(pan[i]))
        return 0;
    }
    if (!isupper(pan[9]))
      return 0;
    return 1;
  }
  return 0;
}

int isAlphaString(char str[]) {
  int i;
  for (i = 0; i < strlen(str); i++) {
    if (!isalpha(str[i])) {
      return 0;
    }
  }
  return 1;
}
