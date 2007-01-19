

typedef int __attribute__ ((bitwidth(33))) int33;


struct Foo {
    int33 a;
    int33 b;
    int33 c;
};

struct Bar {
    union {
        void **a;
        struct Foo b;
    }u;
};

struct Bar test = {0};

int main()
{
    if(test.u.b.a != 0)
        printf("error: a = %d\n", test.u.b.a);
    if(test.u.b.b != 0)
        printf("error: a = %d\n", test.u.b.b);
    if(test.u.b.c != 0)
        printf("error: a = %d\n", test.u.b.c);
    printf("%p\n", test.u.a);
    
    return 0;
}
