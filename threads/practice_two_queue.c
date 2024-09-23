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

typedef struct two_queue {
    queue queue1;
    queue queue2;
}two_queue;

two_queue my_queue;

void init_queue() {
    memset(my_queue.queue1.info_queue, 0, sizeof(std_info) * MAX_SZ);
    my_queue.queue1.wr_ind = 0;
    my_queue.queue1.rd_ind = 0;
    my_queue.queue1.num_entries = 0;
    memset(my_queue.queue2.info_queue, 0, sizeof(std_info) * MAX_SZ);
    my_queue.queue2.wr_ind = 0;
    my_queue.queue2.rd_ind = 0;
    my_queue.queue2.num_entries = 0;
}

void write_data(int queue_id, std_info *info_queue) {
    queue *select_queue;
    if(queue_id == 1) {
        select_queue = &my_queue.queue1;
    }
    else {
        select_queue = &my_queue.queue2;
    }
    if (select_queue->num_entries == MAX_SZ) {
        printf("Queue full.\n");
        return;
    }
    memcpy(&select_queue->info_queue[select_queue->wr_ind], info_queue, sizeof(std_info));
    select_queue->wr_ind = (select_queue->wr_ind + 1) % MAX_SZ;
    select_queue->num_entries++;
}

int read_data(int queue_id, std_info *info_queue) {
    queue *select_queue;
    if(queue_id == 1) {
        select_queue = &my_queue.queue1;
    }
    else {
        select_queue = &my_queue.queue2;
    }
    if (select_queue->num_entries == 0) {
        printf("Empty queue.\n");
        return 1;
    }
    memcpy(info_queue, &select_queue->info_queue[select_queue->rd_ind], sizeof(std_info));
    select_queue->rd_ind = (select_queue->rd_ind + 1) % MAX_SZ;
    select_queue->num_entries--;
    
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
    std_info info[4] = {
        { .msg_id = 1, .src_id = 1, .num = 10 },
        { .msg_id = 2, .src_id = 2, .num = 20 },
        { .msg_id = 3, .src_id = 3, .num = 30 },
        { .msg_id = 4, .src_id = 4, .num = 40 }
    };

    std_info new_info;

    for (int i = 0; i < 2; i++) {
        write_data(1, &info[i]);
        print_info(&info[i]);
    }
    
    printf("==================\n");

    for (int i = 2; i < 4; i++) {
        write_data(2, &info[i]);
        print_info(&info[i]);
    }

    printf("==================\n");

    for (int i = 0; i < 2; i++) {
        if (read_data(1, &new_info) == 0) {
            print_info(&new_info);
        }
    }
    
    printf("==================\n");

    for (int i = 0; i < 2; i++) {
        if (read_data(2, &new_info) == 0) {
            print_info(&new_info);
        }
    }
    
    reset_queue();

    return 0;

}
