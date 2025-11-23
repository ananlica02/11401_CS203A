/*
   ========================================
   hash_fn.c — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/17: Refactored to use hash_fn.h

   Developer: Yu-Feng Huang <yfhuang@saturn.yzu.edu.tw>
 */

#include <stdio.h>    
#include <stdlib.h>   
#include <string.h>   
#include <ctype.h>    

int myHashInt(int key, int m) {

     // 把數字乘以10後減掉(自己+100)
     key = key * 10 - (key + 100);
     // 若最後為負數的話轉為正數
     if (key < 0)    key = -key;

     return key % m;  // division method example
}

int myHashString(const char* str, int m) {
     unsigned long hash = 0;
     int length = strlen(str);
     int i;
    
     if (str == NULL) {
        return 0; 
     }

     length = strlen(str);
     if (length == 0) {
          return 0;
     }     

    // 不分大小寫，把所有字母的數字相加
     for (i = 0; i < length; i++) {
          if (isalpha(str[i])) {
               hash += tolower(str[i]) - 'a' + 1;
          }
          // 若有非字母就以50計算
          else {
               hash += 50;
          }
     }
     return (int)(hash % m);
          
}