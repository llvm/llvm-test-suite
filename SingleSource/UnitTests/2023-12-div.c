int main()
{
    unsigned v1 = 30;
    //needs to not be multiples of 2, otherwise SHL is invoked instead.
    unsigned v2 = 5;
    unsigned result = v1/v2; 
    if (result == 6) {
        while (1){}
    }

    return 0;
}
