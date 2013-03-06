
/* Some archs (ARM) default to unsigned char
   and test results assumes signed */
typedef signed char char_t;

struct global_result
{
  char_t min;
  char_t max;
  char_t add;
  char_t mult;
};

void initarray(void);

char_t array(unsigned long i);

unsigned long getac(void);

void setac(unsigned long i);

char_t min(char_t a, char_t b);

char_t max(char_t a, char_t b);

char_t add(char_t a, char_t b);

char_t mult(char_t a, char_t b);

void loop(void (*init)(void *) , void (*step)(void *) ,void *result);

 
