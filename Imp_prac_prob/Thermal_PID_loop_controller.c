#include <stdint.h>

typedef struct {
    int32_t Kp, Ki, Kd;
    int32_t setpoint;
    int32_t integral;
    int32_t last_error;
} PID_Controller;

// This runs every 10ms in a hardware timer
int32_t calculate_thermal_response(PID_Controller *pid, int32_t current_temp) {
    int32_t error = pid->setpoint - current_temp;

    // P - Present
    int32_t p_term = pid->Kp * error;

    // I - Past (with simple Anti-Windup)
    pid->integral += error;
    if (pid->integral > 5000) pid->integral = 5000; // Saturation
    int32_t i_term = pid->Ki * pid->integral;

    // D - Future (Rate of change)
    int32_t d_term = pid->Kd * (error - pid->last_error);
    pid->last_error = error;

    // Final Output (e.g., Fan PWM or CPU Frequency Offset)
    return (p_term + i_term + d_term) / 1000; 
}

//=====================================================================

/*
#include <stdio.h>
#include <stdint.h>

typedef struct {
    int32_t Kp, Ki, Kd;
    int32_t prev_error;
    int32_t integral;
} PID_t;

// Returns PWM output (0-100) using milli-degree inputs (scaling factor 1000)
int32_t update_pid(PID_t *pid, int32_t target, int32_t current) {
    int32_t error = target - current;
    pid->integral += error;
    
    // Anti-windup (Clamping)
    if (pid->integral > 10000) pid->integral = 10000;
    if (pid->integral < -10000) pid->integral = -10000;

    int32_t derivative = error - pid->prev_error;
    pid->prev_error = error;

    // Results are divided by 1000 to return to base units
    return (pid->Kp * error + pid->Ki * pid->integral + pid->Kd * derivative) / 1000;
}

int main() {
    PID_t thermal_pid = {1500, 10, 100, 0, 0}; // Kp = 1.5
    printf("PID Output: %d\n", update_pid(&thermal_pid, 45000, 42000));
    return 0;
}
*/
