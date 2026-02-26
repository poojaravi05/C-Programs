#include <stdio.h>
#include <limits.h>

#define BUFF_SIZE 4
#define MASK (BUFF_SIZE - 1)

typedef struct sensor_info {
    int buffer[BUFF_SIZE];
    int wr_ptr;
    int cnt;
    int min;
    int max;
    int total;
    int avg;
}sensor_info;

sensor_info my_info = {
    .wr_ptr = 0,
    .cnt = 0,
    .min = INT_MAX,
    .max = INT_MIN,
    .total = 0,
    .avg = 0
};

int update_min(int index) {
    int min = INT_MAX;
    for(int i = 0; i < BUFF_SIZE; i++) {
        if((i != index) && (my_info.buffer[i] < min)) {
            min = my_info.buffer[i];
        }
    }
    my_info.min = min;
    return my_info.min;
}

int update_max(int index) {
    int max = INT_MIN;
    for(int i = 0; i < BUFF_SIZE; i++) {
        if((i != index) && (my_info.buffer[i] > max)) {
            max = my_info.buffer[i];
        }
    }
    my_info.max = max;
    return my_info.max;
}

void write_val(int val) {
    if((my_info.cnt + 1) > BUFF_SIZE) {
        //overwrite
        my_info.cnt = BUFF_SIZE;

        if(my_info.min == my_info.buffer[my_info.wr_ptr] && val > my_info.min) {
            update_min(my_info.wr_ptr);
        }

        if(my_info.max == my_info.buffer[my_info.wr_ptr] && val < my_info.max) {
            update_max(my_info.wr_ptr);
        }

        my_info.total = (my_info.total - my_info.buffer[my_info.wr_ptr] + val);
    }
    else {
        my_info.cnt++;
        my_info.total += val;
    }

    if(val > my_info.max) {
        my_info.max = val;
    }
    if(val < my_info.min) {
        my_info.min = val;
    }
    
    my_info.buffer[my_info.wr_ptr] = val;
    my_info.wr_ptr = (my_info.wr_ptr + 1) & MASK;

    my_info.avg = my_info.total >> 2;
}

int get_min(void)
{
    return my_info.min;
}

int get_max(void)
{
    return my_info.max;
}

float get_avg(void)
{
    return my_info.avg;
}

int get_total(void)
{
    return my_info.total;
}

int get_count(void)
{
    return my_info.cnt;
}

void print_buff(void)
{
    printf("************************************************\n");
    for (int i = 0 ; i < my_info.cnt; i++)
    {
        printf("%d  ", my_info.buffer[i]);
    }
    printf("\n************************************************\n");
}

int main()
{
   write_val(11);
   write_val(12);
   write_val(13);
   write_val(14);
   
   print_buff();
   
   printf("Min: %d\n", get_min());
   printf("Max: %d\n", get_max());
   printf("Current Cnt: %d\n", get_count());
   printf("Total: %d\n", get_total());
   printf("Avg: %f\n", get_avg());
   
   write_val(15);
   
   print_buff();
   
   printf("Min: %d\n", get_min());
   printf("Max: %d\n", get_max());
   printf("Current Cnt: %d\n", get_count());
   printf("Total: %d\n", get_total());
   printf("Avg: %f\n", get_avg());
   
   
   write_val(16);
   print_buff();
   
   printf("Min: %d\n", get_min());
   printf("Max: %d\n", get_max());
   printf("Current Cnt: %d\n", get_count());
   printf("Total: %d\n", get_total());
   printf("Avg: %f\n", get_avg());
   
   write_val(1);
   print_buff();
   
   printf("Min: %d\n", get_min());
   printf("Max: %d\n", get_max());
   printf("Current Cnt: %d\n", get_count());
   printf("Total: %d\n", get_total());
   printf("Avg: %f\n", get_avg());
   
   
   write_val(100);
   print_buff();
   
   printf("Min: %d\n", get_min());
   printf("Max: %d\n", get_max());
   printf("Current Cnt: %d\n", get_count());
   printf("Total: %d\n", get_total());
   printf("Avg: %f\n", get_avg());

    return 0;
}