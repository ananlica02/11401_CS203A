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

/*
 * ========================================
 * hash_fn.c — implement your hash functions (C Language)
 * ========================================
 *
 * Description:
 * This file contains the hash functions for integer and string keys,
 * implemented in pure C language.
 *
 * Developer: Yu-Feng Huang <yfhuang@saturn.yzu.edu.tw>
 */

// 此程式碼為學習理解如何設計"優秀的"Hash Function，由Gemeni協助編寫

#include "hash_fn.h"
#include <string.h>
#include <ctype.h>  
#include <stdio.h>  

// myHashInt 函式 (不需要太多修改，因為它主要使用基本類型)
int myHashInt(int key, int m) {
    // 確保 key 是非負數
    unsigned int uKey = (unsigned int)key;
    
    // 1. 混合運算：使用一個大質數（例如 2654435761）進行乘法
    // 註：2654435761U 是確保它是無符號整數常數
    uKey = uKey * 2654435761U; 
    
    // 2. 位移運算
    uKey = uKey ^ (uKey >> 16); 
    
    // 3. 最後的取模運算
    return (int)(uKey % m);
}

// myHashString 函式 (從 C++ 轉換為 C 語言)
int myHashString(const char* str, int m) {
    // 建議使用大於字元集大小的質數，例如 31
    const int P = 31;
    // 使用 unsigned long long 來儲存中間結果，避免溢位
    unsigned long long hash_value = 0;
    unsigned long long p_pow = 1;

    // 1. 檢查空字串或 NULL 指標
    if (str == NULL || *str == '\0') {
        return 0;
    }

    // 2. 迭代字串 (使用指標和 while 迴圈是 C 語言的慣用法)
    const char* current_char = str;
    while (*current_char != '\0') {
        char c = *current_char;

        // 3. 將字母標準化為 1-26，非字母轉為其他值 (例如 27)
        int char_val;
        if (isalpha((unsigned char)c)) { // 使用 (unsigned char)c 以避免負值對 isalpha 的影響
            // 轉小寫後，'a' 變為 1, 'b' 變為 2, ...
            char_val = tolower((unsigned char)c) - 'a' + 1;
        } else {
            // 統一處理非字母字元
            char_val = 27; 
        }

        // 4. 計算多項式雜湊： H = (H + char_val * P^i)
        // P^i 確保了每個字元的位置都被考慮進去
        hash_value = (hash_value + char_val * p_pow) % m;
        // 更新乘數 P^i
        p_pow = (p_pow * P) % m;

        // 移動到下一個字元
        current_char++;
    }

    // 5. 返回結果
    return (int)hash_value;
}