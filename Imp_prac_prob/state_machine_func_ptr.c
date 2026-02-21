// Implement Traffic Light Controller

#include <stdio.h>

typedef enum states {
    RED,
    YELLOW,
    GREEN
}states;

typedef enum events {
    TIMER,
    EMERGENCY
}events;

typedef states (*states_handler)(events);

states red_handler(events e) {
    if(e == TIMER) {
        return GREEN;
    }
    if(e == EMERGENCY) {
        return YELLOW;
    }
    return RED;
}

states green_handler(events e) {
    if(e == TIMER) {
        return YELLOW;
    }
    if(e == EMERGENCY) {
        return RED;
    }
    return GREEN;
}

states yellow_handler(events e) {
    if(e == TIMER) {
        return RED;
    }
    if(e == EMERGENCY) {
        return GREEN;
    }
    return YELLOW;
}

states_handler states_update[3] = {
    red_handler,
    yellow_handler,
    green_handler
};

int main() {
    states current = RED;
    
    current = states_update[current](TIMER);
    printf("Current state = %d\n", current);
    
    current = states_update[current](TIMER);
    printf("Current state = %d\n", current);
    
    return 0;
}
