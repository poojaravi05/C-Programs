#include <stdio.h>
#include <stdint.h>

// Temperatures are scaled by 1000 (e.g., 25500 = 25.5C)
typedef struct {
    int32_t Kp, Ki, Kd;
    int32_t integral;
    int32_t prev_error;
} PIDController;

int32_t update_pid(PIDController *pid, int32_t setpoint, int32_t current) {
    int32_t error = setpoint - current;
    
    // Proportional
    int32_t p_term = pid->Kp * error;
    
    // Integral with basic clamping (Anti-Windup)
    pid->integral += error;
    if (pid->integral > 10000) pid->integral = 10000;
    if (pid->integral < -10000) pid->integral = -10000;
    int32_t i_term = pid->Ki * pid->integral;
    
    // Derivative
    int32_t d_term = pid->Kd * (error - pid->prev_error);
    pid->prev_error = error;
    
    // Scale down results if K-gains were pre-scaled
    return (p_term + i_term + d_term) / 1000;
}

int main() {
    PIDController my_pid = {1500, 100, 50, 0, 0}; // Kp=1.5, Ki=0.1, Kd=0.05
    printf("Control Output: %d\n", update_pid(&my_pid, 40000, 38500));
    return 0;
}
