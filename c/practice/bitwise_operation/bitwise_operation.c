#define SET_BIT(reg, bit)    ((reg) |=  (1U << (bit)))
#define CLEAR_BIT(reg, bit)  ((reg) &= ~(1U << (bit)))
#define TOGGLE_BIT(reg, bit) ((reg) ^=  (1U << (bit)))
#define READ_BIT(reg, bit)   (((reg) >> (bit)) & 1U)

/*
這四行是 C 語言中常見的**位元操作巨集（bit manipulation macros）**，常用於嵌入式系統或底層硬體控制。

## 使用範例

```c
uint8_t status = 0b00000000;

SET_BIT(status, 3);    // status = 0b00001000  (設定位元 3)
CLEAR_BIT(status, 3);  // status = 0b00000000  (清除位元 3)
TOGGLE_BIT(status, 2); // status = 0b00000100  (翻轉位元 2)

if (READ_BIT(status, 2)) {
    // 如果位元 2 是 1，執行這裡
}
```
---

## 各巨集說明

```c
#define SET_BIT(reg, bit)    ((reg) |=  (1U << (bit)))
```

**功能**：將 `reg` 的第 `bit` 位設為 **1**。  
**原理**：`1U << (bit)` 產生一個遮罩（只有第 `bit` 位是 1），再用 `|=` 把該位強制設為 1，不影響其他位。

---

```c
#define CLEAR_BIT(reg, bit)  ((reg) &= ~(1U << (bit)))
```

**功能**：將 `reg` 的第 `bit` 位設為 **0**（清除）。  
**原理**：`~(1U << (bit))` 產生一個只有第 `bit` 位是 0、其餘都是 1 的遮罩(先將第 `bit` 位是 1，然後用negation翻過來)，再用 `&=` 強制清除該位。

---

```c
#define TOGGLE_BIT(reg, bit) ((reg) ^=  (1U << (bit)))
```

**功能**：將 `reg` 的第 `bit` 位**翻轉**（1 變 0、0 變 1）。  
**原理**：^ = XOR（互斥或）運算的特性 ── 0 與 1 XOR 會翻轉該位，0 與 0 XOR 則保持不變。

---

```c
#define READ_BIT(reg, bit)   (((reg) >> (bit)) & 1U)
```

**功能**：讀取 `reg` 第 `bit` 位的值，回傳 **0 或 1**。  
**原理**：先右移 `bit` 個位置，等同於將目標位移到最低位(bit 0)，再與 `1U` 做 AND，只保留該位。

---
Operator	Name	Description
&	        AND	    Sets each bit to 1 if both bits are 1
|	        OR	    Sets each bit to 1 if at least one of the bits is 1
^	        XOR	    Sets each bit to 1 if only one of the bits is 1, A 或 B 成立，但不能同時成立  E.g.: 0 ^ 0 = 0; 1 ^ 0 = 1; 0 ^ 1 = 1; 1 ^ 1 = 0
~	        NOT	    Inverts all the bits
<<	        Left    Shift	Shifts bits to the left (multiplies by powers of 2)
>>	        Right   Shift	Shifts bits to the right (divides by powers of 2)

## 常見應用場景

| 場景 | 說明 |
|------|------|
| **GPIO 控制** | 設定或清除 I/O 腳位的輸出電位 |
| **暫存器操作** | 修改微控制器中特定控制暫存器的某個位元 |
| **旗標管理** | 讀取或切換狀態旗標（如中斷旗標、錯誤旗標） |
| **權限控制** | 用位元表示多個開關狀態，節省記憶體 |

## 注意事項

- `1U` 後綴的 `U` 表示**unsigned int**，避免在有號數右移時產生未定義行為。
- 參數 `reg` 被小括號包住（如 `(reg)`），這是**預防巨集展開時的運算子優先級問題**。
- 這些巨集是**直接修改原始變數**（SET/CLEAR/TOGGLE 有副作用），使用時需留意。
*/