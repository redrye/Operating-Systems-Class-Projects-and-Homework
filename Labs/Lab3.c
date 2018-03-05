/*Coded by Ryan Boudreaux */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>


pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void* print_i(void *ptr)
{ 
    /*Lock function until completion*/
    pthread_mutex_lock(&lock);
    printf("1: I am \n");
    sleep(1);
    printf("in i\n");
    /*Unlock function upon completion*/
    pthread_mutex_unlock(&lock);
}
void* print_j(void *ptr)
{ 
    /*Lock function until completion*/
    pthread_mutex_lock(&lock);
    printf("2: I am \n"); 
    sleep(1);
    printf("in j\n");
    /*Unlock function upon completion*/
    pthread_mutex_unlock(&lock);
}
int main()
{
    pthread_t t1,t2;
    pthread_create(&t1, NULL, print_i, NULL);
    pthread_create(&t2, NULL, print_j, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}
