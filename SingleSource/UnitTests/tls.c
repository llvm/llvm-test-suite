#include <stdio.h>
#include <pthread.h>

void *f(void *a){
  static __thread int i = 1;
  i++;
  return (void *)i;
}

int main() {
  pthread_t t;
  int ret;
  pthread_create(&t, NULL, f, NULL);
  pthread_join(t, (void **) &ret);
  printf("Thread 1: %d\n",ret);
  pthread_create(&t, NULL, f, NULL);
  pthread_join(t, (void **) &ret);
  printf("Thread 2: %d\n",ret);
  return 0;
}
