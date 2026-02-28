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
