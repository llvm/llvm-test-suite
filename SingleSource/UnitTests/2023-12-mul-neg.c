int main()
{
    unsigned v1 = 30;
    unsigned v2 = 11; //needs to not be multiples of 2, otherwise SHL is invoked instead.
    unsigned result = v1*v2;
    if (result == -36) {
        while (1){}
    }

    return 0;
}
