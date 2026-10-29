typedef enum { STATE_IDLE, STATE_RUNNING, STATE_FAULT } MotorState_t;

void FSM_Update(MotorState_t *state, uint8_t start_cmd, uint8_t fault_detected) {
    switch (*state) {
        case STATE_IDLE:
            if (start_cmd) *state = STATE_RUNNING;
            break;
        case STATE_RUNNING:
            if (fault_detected) *state = STATE_FAULT;
            break;
        case STATE_FAULT:
            /* Require explicit reset to leave fault state */
            break;
        default:
            *state = STATE_FAULT;
            break;
    }
}

/*
## 程式碼解說

這段程式碼是馬達控制的**有限狀態機 (FSM, Finite State Machine)** 實作，用 C 語言撰寫，主要包含兩部分。
e.g. call function
MotorState_t motor_state = STATE_IDLE;  // 宣告一個 MotorState_t 變數

while(1) {
    FSM_Update(&motor_state, read_start_btn(), read_fault_sensor());
    //          ^^^^^^^^^^^^
    //          傳入 motor_state 的「位址」
}
*state 做了什麼
state = motor_state 的地址（例如 0x1000）
*state = 把 0x1000 這個地址的內容「解參考」(dereference)，取得實際的 MotorState_t 數值（例如 STATE_IDLE)

!!為什麼用指標而非直接傳值？!
// ❌ 傳值 — 改的是副本，原變數不變
void FSM_Update(MotorState_t state, ...) {
    state = STATE_RUNNING;  // 只改了區域變數
}

// ✅ 傳指標 — 直接修改原變數
void FSM_Update(MotorState_t *state, ...) {
    *state = STATE_RUNNING;  // 改到原本的 motor_state
}

### 1. 狀態列舉 `MotorState_t`

```c
typedef enum { STATE_IDLE, STATE_RUNNING, STATE_FAULT } MotorState_t;
```

定義了三種馬達狀態：

| 狀態 | 意義 |
|---|---|
| `STATE_IDLE` | 待機／閒置，馬達未運轉 |
| `STATE_RUNNING` | 運轉中 |
| `STATE_FAULT` | 故障狀態 |

### 2. 狀態更新函式 `FSM_Update`

```c
void FSM_Update(MotorState_t *state, uint8_t start_cmd, uint8_t fault_detected)
```

**參數說明：**
- `state` — 指向目前狀態的指標，函式會直接修改它
- `start_cmd` — 啟動訊號（非零表示收到啟動指令）
- `fault_detected` — 故障訊號（非零表示偵測到異常）

**狀態轉換邏輯：**

```
          start_cmd != 0          fault_detected != 0
  IDLE ──────────────────> RUNNING ──────────────────> FAULT
   ^                                                      │
   │                     需手動重置                         │
   └──────────────────────────────────────────────────────┘
```

- **IDLE → RUNNING**：收到啟動指令時切換
- **RUNNING → FAULT**：偵測到故障時切換
- **FAULT → (其他)**：代碼中沒有定義離開 FAULT 的條件，註解說明需要**外部顯式重置**（例如斷電重啟或發送重置命令），這是刻意設計的安全機制——故障狀態無法透過一般訊號自動脫離。
- **default**：若狀態值異常（例如記憶體被破壞），強制進入 FAULT 狀態，確保系統安全。

### 核心設計概念

這是一個**防衛性設計**的狀態機：

- 狀態轉換路徑少而明確，不易出錯
- 故障狀態鎖住，防止自動復位導致危險
- `default` 分支作為安全網，處理未預期的狀態值
- 專為硬體控制這類**安全至上**的場景設計
*/