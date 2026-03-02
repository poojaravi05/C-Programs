#include <stdio.h>
#include <stdint.h>

int32_t filter_sensor_data(int32_t sample) {
    // Static storage keeps the samples alive between function calls
    static int32_t s1 = 0, s2 = 0, s3 = 0;
    static uint8_t initialized = 0;

    if(!initialized) {
        // Handle cold start: fill all slots with the first reading
        s1 = s2 = s3 = sample;
        initialized = 1;
        return sample;
    }

    // Shift the window: s3 is oldest, s1 is newest
    s3 = s2;
    s2 = s1;
    s1 = sample;

    // Find the median of (s1, s2, s3)
    // There are only 6 possible permutations. We can find the middle in 2-3 comparisons.
    if((s1 <= s2 && s2 <= s3) || (s3 <= s2 && s2 <= s1)) {
        return s2; // s2 is the middle
    }
    else if((s2 <= s1 && s1 <= s3) || (s3 <= s1 && s1 <= s2)) {
        return s1; // s1 is the middle
    }
    else {
        return s3; // s3 is the middle
    }
}

int main() {
    uint8_t res;
    res = filter_sensor_data(47);
    res = filter_sensor_data(86);
    res = filter_sensor_data(38);
    res = filter_sensor_data(92);
    printf("Median res = %d\n", res);
    return 0;
}