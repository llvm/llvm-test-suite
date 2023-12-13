int main()
{
    int v1 = 30;
    //needs to not be multiples of 2, otherwise SHL is invoked instead.
    int v2 = 5;
    int result = v1/v2; 
    if (result == 16) {
        while (1){}
    }

    return 0;
}
