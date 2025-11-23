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

// 此程式碼為學習理解如何設計"優秀的"Hash Function，由Gemeni協助編寫

int myHashInt(int key, int m) {
    // 確保 key 是非負數
    unsigned int uKey = static_cast<unsigned int>(key);
    
    // 1. 混合運算：使用一個大質數（例如 2654435761）進行乘法，
    //    這是一種常見的雜湊技術，用於「攪拌」位元，使位元分佈更均勻。
    //    這比您的線性運算 (9*key - 100) 提供了更好的分佈性。
    uKey = uKey * 2654435761U; 
    
    // 2. 位移運算：將高位元（高位元通常包含更多分佈良好的資訊）移到低位。
    //    這進一步打破了線性關係。
    uKey = uKey ^ (uKey >> 16); 
    
    // 3. 最後的取模運算
    return static_cast<int>(uKey % m);
}

int myHashString(const std::string& str, int m) {
    // 建議使用大於字元集大小的質數，例如 31
    const int P = 31;
    // 使用 unsigned long long 來儲存中間結果，避免溢位
    unsigned long long hash_value = 0;
    unsigned long long p_pow = 1;

    // 1. 檢查空字串
    if (str.empty()) {
        return 0;
    }

    // 2. 迭代字串
    for (char c : str) {
        // 3. 將字母標準化為 1-26，非字母轉為其他值 (例如 27)
        int char_val;
        if (isalpha(c)) {
            // 轉小寫後，'a' 變為 1, 'b' 變為 2, ...
            char_val = tolower(c) - 'a' + 1;
        } else {
            // 統一處理非字母字元
            char_val = 27; 
        }

        // 4. 計算多項式雜湊： H = (H + char_val * P^i)
        // P^i 確保了每個字元的位置都被考慮進去
        hash_value = (hash_value + char_val * p_pow) % m;
        // 更新乘數 P^i
        p_pow = (p_pow * P) % m;
    }

    // 5. 返回結果
    return static_cast<int>(hash_value);
}