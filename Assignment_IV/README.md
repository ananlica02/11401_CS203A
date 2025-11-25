# Homework Assignment IV: Hash Function Design & Observation (C/C++ Version)

This assignment focuses on the design and observation of hash functions using C/C++. 
Students are expected to implement and analyze the behavior of hash functions, 
evaluate their efficiency, and understand their applications in computer science.

Developer: 陳有安
Email: a072007221030@gmail.com  

## My Hash Function_1
### Integer Keys 
- Formula / pseudocode:
  ```text
  Key = Key * 10 - ( Key + 100 ) = Key * 9 - 100
  ```
- Rationale: 
起初我還想不到優秀的Hash Function，單純想要將某個int的Input得出Output，並盡量避免碰撞，因此透過乘法與加法的混合來試著實現

### Non-integer Keys
- Formula / pseudocode:
  ```text
  total = 不分大小寫，所有的字母順位（A1~Z26）相加，遇到非字母就+50
  result = total / 字串長度
  ```
- Rationale:
一開始在想要如何將string的Input轉成int的Output，發現把字串裡面的字母加起來可以實現這一點，最後除以字串長度以避免過多的碰撞

---
## My Hash Function_2
### Integer Keys 
- Formula / pseudocode:
  ```text
  uKey = uKey * 2654435761U;
  uKey = uKey ^ (uKey >> 16);
  ```
- Rationale: 
由AI提供更優的Hash Function，使用質數可以把Key攪拌得更分散。因為質數能消除公因數所帶來的規律性

### Non-integer Keys
- Formula / pseudocode:
  ```text
  $$H(S) = \left( \sum_{i=0}^{L-1} s_i \cdot P^i \right) \pmod{m}$$
  ```
- Rationale:
選擇質數P與上述目的相同，能將字串攪拌得更分散。

## Experimental Setup
- Table sizes tested (m): 10, 11, 37
- Test dataset:
  - Integers: 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60
  - Strings: "cat", "dog", "bat", "cow", "ant", "owl", "bee", "hen", "pig", "fox"
- Compiler: GCC and G++
- Standard: C23 and C++23

## Results
| Table Size (m) | Index Sequence         | Observation              |
|----------------|------------------------|--------------------------|
| 10             | 1, 2, 3, 4, ...        | Pattern repeats every 10 |
| 11             | 10, 0, 1, 2, ...       | More uniform             |
| 37             | 20, 21, 22, 23, ...    | Near-uniform             |

## Compilation, Build, Execution, and Output

### Compilation
- The project uses a comprehensive Makefile that builds both C and C++ versions with proper flags:
  ```bash
  # Build only C version
  "gcc .\Assignment_IV\C\hash_fn_2.c .\Assignment_IV\C\hash_fn.h .\Assignment_IV\C\main.c -o Assignment_IV_C_2.exe" 
  
  # Build only C++ version
  "g++ -g .\Assignment_IV\C\hash_fn_2.c .\Assignment_IV\C\hash_fn.h .\Assignment_IV\C\main.c -o Assignment_IV_C_2.exe"
  ```

### Manual Compilation (if needed)
- Command for C:
  ```bash
  gcc -std=c23 -Wall -Wextra -Wpedantic -g -o C/hash_function C/main.c C/hash_fn.c
  ```
- Command for C++:
  ```bash
  g++ -std=c++23 -Wall -Wextra -Wpedantic -g -o CXX/hash_function_cpp CXX/main.cpp CXX/hash_fn.cpp
  ```

### Clean Build Files
- Remove all compiled files:
  ```bash
  make clean
  ```

### Execution
- Run the compiled binary:
  .\exe_area\檔案名稱
    ^ex :^ .\exe_area\Assignment_IV_C_1.exe

### Result Snapshot_1
- Example output for integers:
  ```
  === Hash Function Observation (C Version) ===

    === Table Size m = 10 ===
    Key     Index
    -----------------
    21      9
    22      8
    23      7
    24      6
    25      5
    26      4
    27      3
    28      2
    29      1
    30      0
    51      9
    52      8
    53      7
    54      6
    55      5
    56      4
    57      3
    58      2
    59      1
    60      0

    === Table Size m = 11 ===
    Key     Index
    -----------------
    21      1
    22      10
    23      8
    24      6
    25      4
    26      2
    27      0
    28      9
    29      7
    30      5
    51      7
    52      5
    53      3
    54      1
    55      10
    56      8
    57      6
    58      4
    59      2
    60      0

    === Table Size m = 37 ===
    Key     Index
    -----------------
    21      15
    22      24
    23      33
    24      5
    25      14
    26      23
    27      32
    28      4
    29      13
    30      22
    51      26
    52      35
    53      7
    54      16
    55      25
    56      34
    57      6
    58      15
    59      24
    60      33

    === String Hash (m = 10) ===
    Key     Index
    -----------------
    cat     4
    dog     6
    bat     3
    cow     1
    ant     5
    owl     0
    bee     2
    hen     7
    pig     2
    fox     5

    === String Hash (m = 11) ===
    Key     Index
    -----------------
    cat     2
    dog     4
    bat     1
    cow     8
    ant     2
    owl     6
    bee     1
    hen     5
    pig     10
    fox     1

    === String Hash (m = 37) ===
    Key     Index
    -----------------
    cat     24
    dog     26
    bat     23
    cow     4
    ant     35
    owl     13
    bee     12
    hen     27
    pig     32
    fox     8
  ```

  ---

  ### Result Snapshot_2
- Example output for integers:
  ```
  === Hash Function Observation (C++ Version) ===

    === Table Size m = 10 ===
    Key     Index
    -----------------
    21      5
    22      2
    23      4
    24      9
    25      1
    26      6
    27      8
    28      3
    29      9
    30      8
    51      6
    52      2
    53      9
    54      7
    55      0
    56      6
    57      3
    58      9
    59      6
    60      4

    === Table Size m = 11 ===
    Key     Index
    -----------------
    21      3
    22      1
    23      4
    24      7
    25      8
    26      5
    27      8
    28      7
    29      6
    30      7
    51      2
    52      10
    53      4
    54      0
    55      7
    56      3
    57      10
    58      7
    59      4
    60      1

    === Table Size m = 37 ===
    Key     Index
    -----------------
    21      29
    22      3
    23      33
    24      10
    25      2
    26      14
    27      10
    28      8
    29      6
    30      33
    51      2
    52      28
    53      27
    54      23
    55      15
    56      16
    57      7
    58      15
    59      26
    60      13

    === String Hash (m = 10) ===
    Key     Index
    -----------------
    cat     4
    dog     6
    bat     3
    cow     1
    ant     5
    owl     0
    bee     2
    hen     7
    pig     2
    fox     5

    === String Hash (m = 11) ===
    Key     Index
    -----------------
    cat     4
    dog     2
    bat     3
    cow     10
    ant     9
    owl     6
    bee     1
    hen     10
    pig     4
    fox     6

    === String Hash (m = 37) ===
    Key     Index
    -----------------
    cat     14
    dog     18
    bat     13
    cow     1
    ant     8
    owl     13
    bee     4
    hen     1
    pig     29
    fox     3
  ```

- Observations: Outputs align with the analysis, showing better distribution with prime table sizes.
- Example output for integers:
  ```
  Hash table (m=10): [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]
  Hash table (m=11): [10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
  Hash table (m=37): [20, 21, 22, 23, 24, 25, 26, 27, 28, 29, ...]
  ```
- Example output for strings:
  ```
  Hash table (m=10): ["cat", "dog", "bat", "cow", "ant", ...]
  Hash table (m=11): ["fox", "cat", "dog", "bat", "cow", ...]
  Hash table (m=37): ["bee", "hen", "pig", "fox", "cat", ...]
  ```
- Observations: Outputs align with the analysis, showing better distribution with prime table sizes.

## Analysis
- $非質數m$(10)：
  容易產生碰撞
- $質數m$(11, 37)：
  - 能分布的更散
  - 尤其$m=37$時，因Hash table的大小較大，能分布得更加散
- 為何第二個Hash function是更好的？
  - (整數)因透過乘以大質數來進行數字的攪拌，能讓數據變得更分散
  - (字串)使用權重$P^i$，使每個字元的數值能更加分散

## Reflection
- 我的設計 vs. AI的設計
  - 我的設計：
    較為簡單與單純，但很難使數據平均分布
  - AI的設計：
    利用了乘以質數、位移與權重，設計出更優秀的Hash function，使我更了解該如何使資料變得更均勻地分散
- $m$的大小造成的影響：
  - $m$愈大，能使資料分布得更加散
  - $m$必須要為質數(如11, 37)，才能消除公因數造成的規律性，將表設計為質數大小可以避免過多的碰撞
- Int與Sting的分散策略：
  經整理過後，我發現了優秀的Int與String的分散策略：
  - Int：
    混合函數，在Function 2使用的乘以大質數與位移 XOR 混合，以確保輸入整數的每一位都能影響最終的結果。
  - String：
    使用權重，在Function 2使用的多項式Hash function，將字元內容與位置信息結合起來進行計算。