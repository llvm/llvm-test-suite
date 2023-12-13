int main()
{
    unsigned v1 = 30;
    //needs to not be multiples of 2, otherwise SHL is invoked instead.
    int result = v1/5u; 
    if (result == 6u) {
        while (1){}
    }

    return 0;
}
