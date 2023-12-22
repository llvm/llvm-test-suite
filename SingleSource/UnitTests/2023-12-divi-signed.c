int main()
{
    int v1 = 30;
    //needs to not be multiples of 2, otherwise SHL is invoked instead.
    int result = v1/5; 
    if (result == 6) {
        while (1){}
    }

    return 0;
}
