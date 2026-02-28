#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

// --- 1. HARDWARE LAYER (Simulated) ---
// In reality, these are specific physical memory addresses (MMIO)
uint32_t TEMP_SENSOR_REG = 35000; // Represents 35.000°C in milli-Celsius

// --- 2. FIRMWARE / DRIVER LAYER ---
// Responsibility: Talk to the hardware and provide a clean integer to the OS.
int32_t read_temperature_mC(void) {
    // In a real Apple Watch, this would involve I2C or SPI communication
    // and applying a calibration offset stored in the device's EEPROM.
    return (int32_t)TEMP_SENSOR_REG; 
}

// --- 3. KERNEL / COREOS LAYER ---
// Responsibility: Running the PID logic and making "Throttling" decisions.
typedef enum { THERMAL_STATE_NORMAL, THERMAL_STATE_THROTTLED } thermal_state_t;

thermal_state_t monitor_system_health(void) {
    int32_t current_temp = read_temperature_mC();
    const int32_t CRITICAL_THRESHOLD = 85000; // 85°C

    if (current_temp > CRITICAL_THRESHOLD) {
        printf("[Kernel] CRITICAL TEMP: %d mC. Engaging CPU Throttle.\n", current_temp);
        return THERMAL_STATE_THROTTLED;
    }
    return THERMAL_STATE_NORMAL;
}

// --- 4. MIDDLEWARE / FRAMEWORK LAYER ---
// Responsibility: Providing an API so the App doesn't have to check sensors.
bool is_system_thermal_limited(void) {
    // This abstracts the Kernel logic into a simple boolean for Apps
    return (monitor_system_health() == THERMAL_STATE_THROTTLED);
}

// --- 5. APPLICATION LAYER (The "High-Intensity Game") ---
// Responsibility: Adjusting the user experience based on system constraints.
void run_game_loop(void) {
    if (is_system_thermal_limited()) {
        // Drop from 120 FPS to 60 FPS to reduce GPU heat
        printf("[App] Thermal pressure detected. Capping Frame Rate to 60fps.\n");
    } else {
        printf("[App] System cool. Running at Max Performance (120fps).\n");
    }
}

// --- SIMULATION EXECUTION ---
int main() {
    // Scenario 1: Normal Operation
    printf("--- Scenario: Normal Gaming ---\n");
    TEMP_SENSOR_REG = 40000; // 40°C
    run_game_loop();

    printf("\n--- Scenario: Heavy Thermal Load ---\n");
    // Scenario 2: Hardware heats up significantly
    TEMP_SENSOR_REG = 90000; // 90°C
    run_game_loop();

    return 0;
}
