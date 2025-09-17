# 練習紀錄

## Day 1 – 環境準備 & C 基礎
>✅[time=Mon, Sep 1, 2025 12:06 AM]
- 確認環境（Ubuntu / WSL / VM）
- 安裝工具：`gcc`, `gdb`, `make`, `valgrind`
- 寫第一個程式：Hello World + 簡單計算（加減乘除）

練習題：輸入兩個數字，輸出最大值。
思考：為什麼把「找最大值」寫成函式比 Day 1 版本好？
- 這就是軟體工程師要練的「模組化思維」，嵌入式程式通常需要很多小模組組合。

---

## Day 2 – 指標與陣列
>✅[time=Wed, Sep 3, 2025 8:03 PM]
- C 語言中的指標基礎：`int *p`、指標運算、陣列 vs. 指標
- 練習 malloc/free 配合陣列
- 用 `gdb` trace 指標的內容

練習題：  
寫一個函式 `reverse_array(int *arr, int n)`，反轉整數陣列。

---

## Day 3 – 結構體與函式
>✅[time=Fri, Sep 12, 2025 9:24 PM]
- `struct` 與 `typedef` 的使用
- 函式呼叫時傳遞 pointer / struct
- 簡單的鏈結串列節點定義：

```c
typedef struct Node {
    int data;
    struct Node *next;
} Node;
```

練習題：  
實作 `insert_front()`，能在 linked list 前端插入節點。

問題：
- 為何要用：`Node **head` 而不是 `Node *head`？
因為我要修改的就是 `*head` 本身，C 是 call by value，所以要傳的是 `*head` 的位址，所以是 `&head`，他的型別就是 `**head`。

---

## Day 4 – 動態記憶體管理
>✅[time=Fri, Sep 12, 2025 10:13 PM]
- `malloc`, `calloc`, `realloc`, `free`
- 記憶體洩漏檢查：用 `valgrind --leak-check=full ./a.out`
- 把 Day 3 的 linked list 改成用 malloc 動態配置。

練習題：  
先用 malloc 配置一個可以放 5 個整數的陣列。
輸入 5 個數字。
然後用 realloc 把陣列擴展到 10 個整數，再輸入 5 個數字。
最後把 10 個數字都印出來。

---
