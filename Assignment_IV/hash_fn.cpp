/*
   ========================================
   hash_fn.cpp — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/17: Refactored to use hash_fn.hpp

   Developer: Yu-Feng Huang <yfhuang@saturn.yzu.edu.tw>
 */
#include "hash_fn.hpp"
#include <string>
#include <cctype>

int myHashInt(int key, int m) {
    
    // 把數字乘以10後減掉(自己+100)
    key = key * 10 - (key + 100);
    // 若最後為負數的話轉為正數
    if( key < 0 )   key *= -1;

    return key % m;  // basic division method
}

int myHashString(const std::string& str, int m) {
    unsigned long hash = 0;
    
    // 不分大小寫，把所有字母的數字相加
    for( int i = 0; i < str.length(); i++ ){
        if( isalpha(str[i]) )  hash += tolower(str[i]) - 'a' + 1;
        // 若有非字母就以50計算
        else hash += 50;
    }

    // 將得出的數字除以字串長度
    hash /= str.length();

    // 最後mod size
    return static_cast<int>(hash % m);  // basic division method
}