//Problem: The sensor will be sending continuous data. Record Min, Max value sent so far and average of all values sent.
//Solution: Here we can make use of circular buffer implementation, following different situations.

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

#define BUFF_SZ 5

typedef struct sensor_info_t {
    int buff[BUFF_SZ];
    int wr_ptr;
    int cnt;
    int min;
    int max;
    int total;
    float avg;
} sensor_info_t;

static sensor_info_t my_sensor_info = {
    .wr_ptr = 0,
    .cnt = 0,
    .min = INT_MAX,
    .max = INT_MIN,
    .total = 0,
    .avg = 0.0
};

void update_min(int idx)
{
    int min = INT_MAX;
    
    for (int i = 0; i < BUFF_SZ; i++)
    {
        if (my_sensor_info.buff[i] < min && i != idx)
        {
            min = my_sensor_info.buff[i];
        }
    }
    
    my_sensor_info.min = min;
}

void update_max(int idx)
{
    int max = INT_MIN;
    
    for (int i = 0; i < BUFF_SZ; i++)
    {
        if (my_sensor_info.buff[i] > max && i != idx)
        {
            max = my_sensor_info.buff[i];
        }
    }
    
    my_sensor_info.max = max;
}

void write_val(int val)
{
   //Buffer already filled.. now over witing start
    if (my_sensor_info.cnt + 1 > BUFF_SZ)
    {
        my_sensor_info.cnt = BUFF_SZ;
        
        if (val > my_sensor_info.min && my_sensor_info.min == my_sensor_info.buff[my_sensor_info.wr_ptr])
        {
          update_min(my_sensor_info.wr_ptr);
        }
        
        if (val < my_sensor_info.max && my_sensor_info.max == my_sensor_info.buff[my_sensor_info.wr_ptr])
        {
          update_max(my_sensor_info.wr_ptr);
        }
        
        my_sensor_info.total = (my_sensor_info.total - my_sensor_info.buff[my_sensor_info.wr_ptr]) + val;
        
    }
    //Buffer not filled yet
    else
    {
        //printf("val = %d\n", val);
        my_sensor_info.cnt = my_sensor_info.cnt + 1;
        //printf("%s: Before : Total = %ld\n", __func__,  my_sensor_info.total);
        my_sensor_info.total = my_sensor_info.total +  val;
        //printf("%s: After : Total = %ld\n", __func__,  my_sensor_info.total);
        
    }
    
    if (val < my_sensor_info.min)
    {
        my_sensor_info.min = val;
    }
    if (val > my_sensor_info.max)
    {
        my_sensor_info.max = val;
    }
    
    my_sensor_info.buff[my_sensor_info.wr_ptr] = val;
    my_sensor_info.wr_ptr = (my_sensor_info.wr_ptr + 1) % BUFF_SZ;
    
    my_sensor_info.avg = (float) ((float)(my_sensor_info.total) / (float)my_sensor_info.cnt);
    
}

int get_min(void)
{
    return my_sensor_info.min;
}

int get_max(void)
{
    return my_sensor_info.max;
}

float get_avg(void)
{
    return my_sensor_info.avg;
}

int get_total(void)
{
    return my_sensor_info.total;
}

int get_count(void)
{
    return my_sensor_info.cnt;
}

void print_buff(void)
{
    printf("************************************************\n");
    for (int i = 0 ; i < my_sensor_info.cnt; i++)
    {
        printf("%d  ", my_sensor_info.buff[i]);
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
