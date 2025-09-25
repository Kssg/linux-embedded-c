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

## Day 5 - Stack & Queue
>✅[time=Fri, Sep 26, 2025 12:21 AM]
*   用陣列實作 Stack (push/pop)
*   用 linked list 實作 Queue (enqueue/dequeue)

👉 練習題：  
寫一個程式，讀取一串字串，檢查括號是否正確配對（用 stack）。

- 在 C 語言裡要如何用結構體實做出 Stack?
- 不能使用變數來初始化陣列
```c
int size = 10;
int arr[size];
// 用 macro 就可以，記得 define 後面沒有分號
#define size 10
int arr[size];
```
- macro 可以計算嗎？不行：size = 10 -> 10 = 10; // 編譯錯誤
- 用 array 來實做會遇到大小不夠的問題：用 stack 就是在固定的範圍內增減，queue 會有頭尾問題
- 我把 stack 的 top 想成 queue 的 front 了
- 0 ~ capacity-1 所以是 capacity 個沒錯
- linked list 的初始化是如何？會有值嗎？寫在 malloc 裡
- enqueue dequeue 的行為我完全亂掉
- struct 內成員的初始值：在 C 語言裡 不會自動預設為 NULL，必須自己設定，例如 q->next = NULL;
- 怎麼才能真的改到外部指標？必須傳指標的位址（也就是「二重指標」）
