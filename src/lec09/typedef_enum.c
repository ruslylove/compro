// Lecture 9: typedef with enum
#include <stdio.h>

// Combine enum definition with typedef
typedef enum {
    STATE_IDLE,
    STATE_RUNNING,
    STATE_SUSPENDED,
    STATE_FINISHED
} SystemState; // 'SystemState' is now a type alias

void print_state(SystemState state) {
    switch (state) {
        case STATE_IDLE:
            printf("Current state: Idle\n");
            break;
        case STATE_RUNNING:
            printf("Current state: Running\n");
            break;
        case STATE_SUSPENDED:
            printf("Current state: Suspended\n");
            break;
        case STATE_FINISHED:
            printf("Current state: Finished\n");
            break;
        default:
            printf("Unknown state\n");
    }
}

int main() {
    // Declare a variable using the typedef'd alias
    SystemState current_state = STATE_RUNNING;
    print_state(current_state);

    current_state = STATE_FINISHED;
    print_state(current_state);

    return 0;
}
