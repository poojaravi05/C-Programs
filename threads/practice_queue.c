#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SZ 2

typedef struct student_info {
    int msg_id;
    int src_id;
    int num;
} std_info;

typedef struct queue {
    std_info info_queue[MAX_SZ];
    int wr_ind;
    int rd_ind;
    int num_entries;
} queue;

queue my_queue;

void init_queue() {
    memset(my_queue.info_queue, 0, sizeof(std_info) * MAX_SZ);
    my_queue.wr_ind = 0;
    my_queue.rd_ind = 0;
    my_queue.num_entries = 0;
}

void write_data(std_info *info_queue) {
    if (my_queue.num_entries == MAX_SZ) {
        printf("Queue full.\n");
        return;
    }
    memcpy(&my_queue.info_queue[my_queue.wr_ind], info_queue, sizeof(std_info));
    my_queue.wr_ind = (my_queue.wr_ind + 1) % MAX_SZ;
    my_queue.num_entries++;
}

int read_data(std_info *info_queue) {
    if (my_queue.num_entries == 0) {
        printf("Empty queue.\n");
        return 1;
    }
    memcpy(info_queue, &my_queue.info_queue[my_queue.rd_ind], sizeof(std_info));
    my_queue.rd_ind = (my_queue.rd_ind + 1) % MAX_SZ;
    my_queue.num_entries--;
    
    return 0;
}

void reset_queue() {
    init_queue();
}

void print_info(std_info *info_queue) {
    printf("Message ID = %d\n", info_queue->msg_id);
    printf("Source ID = %d\n", info_queue->src_id);
    printf("Number = %d\n", info_queue->num);
}

int main() {
    init_queue();
    std_info info[3] = {
        { .msg_id = 1, .src_id = 1, .num = 10 },
        { .msg_id = 2, .src_id = 2, .num = 20 },
        { .msg_id = 3, .src_id = 3, .num = 30 }
    };

    std_info new_info;

    for (int i = 0; i < 3; i++) {
        write_data(&info[i]);
        print_info(&info[i]);
    }
    
    printf("==================\n");
    
    for (int i = 0; i < 3; i++) {
        if (read_data(&new_info) == 0) {
            print_info(&new_info);
        }
    }
    
    std_info add_info = info[2];
    write_data(&add_info); 
    
    printf("==================\n");
    
   
    if (read_data(&new_info) == 0) {
        print_info(&new_info);
    }
    reset_queue();

    return 0;
}
