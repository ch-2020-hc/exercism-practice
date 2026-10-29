typedef struct {
    float kp;
    float ki;
    float integrator;
    float output_limit;
} PI_Controller_t;

float PI_Update(PI_Controller_t *ctrl, float setpoint, float measured) {
    float error = setpoint - measured;
    ctrl->integrator += ctrl->ki * error;
    /* Anti-windup */
    if (ctrl->integrator >  ctrl->output_limit) ctrl->integrator =  ctrl->output_limit;
    if (ctrl->integrator < -ctrl->output_limit) ctrl->integrator = -ctrl->output_limit;
    return (ctrl->kp * error) + ctrl->integrator;
}

/*
這是一段用 C 語言實作的**比例積分控制器（PI Controller）**程式碼，常見於嵌入式系統、馬達控制、溫度控制等場合。以下拆解說明：
**使用範例（假想）**：
   ```c
   PI_Controller_t speed_ctrl = { .kp = 1.5, .ki = 0.1, .output_limit = 100.0 };
   float output = PI_Update(&speed_ctrl, 1000.0, encoder_speed);
   ```
---

## 結構體 `PI_Controller_t`

```c
typedef struct {
    float kp;           // 比例增益
    float ki;           // 積分增益
    float integrator;   // 積分器的累積值
    float output_limit; // 輸出限制值（防飽和用）
} PI_Controller_t;
```

四個成員分別代表：
- **`kp`（比例係數）**：決定對誤差的即時反應強度
- **`ki`（積分係數）**：決定對誤差歷史的累積速度
- **`integrator`（積分器）**：不斷累積誤差的變數，用來消除穩態誤差
- **`output_limit`（輸出限制）**：限制積分器與最終輸出的範圍，避免數值發散

---

## 控制更新函式 `PI_Update`

```c
float PI_Update(PI_Controller_t *ctrl, float setpoint, float measured) {
    float error = setpoint - measured;            // ① 計算誤差
    ctrl->integrator += ctrl->ki * error;          // ② 積分項累加

    // ③ Anti-windup（抗飽和）
    if (ctrl->integrator >  ctrl->output_limit)
        ctrl->integrator =  ctrl->output_limit;
    if (ctrl->integrator < -ctrl->output_limit)
        ctrl->integrator = -ctrl->output_limit;

    return (ctrl->kp * error) + ctrl->integrator;  // ④ 輸出 = P項 + I項
}
```

### 流程拆解

| 步驟 | 說明 |
|------|------|
|1| 計算**誤差** = 目標值（setpoint） − 目前值（measured） |
|2| 將**誤差 × ki** 累加到積分器中，實現積分控制 |
|3| **抗飽和（Anti-windup）**：若積分值超出 `±output_limit`，就直接截斷，避免積分項無限膨脹導致系統恢復遲緩 |
|4| 回傳 **P項 + I項**（比例項 × kp + 積分項），作為當前控制輸出 |

---

## 重點整理

1. **PI 控制公式**：  
   `輸出 = kp × 誤差 + ki × ∫誤差 dt`（此處積分用離散累加近似）

2. **積分器的作用**：  
   當純比例控制無法消除穩態誤差時，積分項會隨時間累積，持續修正直到誤差歸零。

3. **抗飽和機制**：  
   這是最實務的設計——當積分累積過大時強制截斷，避免系統從飽和狀態恢復時產生嚴重超調或震盪。

4. **使用範例（假想）**：
   ```c
   PI_Controller_t speed_ctrl = { .kp = 1.5, .ki = 0.1, .output_limit = 100.0 };
   float output = PI_Update(&speed_ctrl, 1000.0, encoder_speed);
   ```

這段程式碼結構簡潔、實用，是嵌入式控制領域非常標準的 PI 控制器寫法。
*/