int main()
{
    int v1 = 30;
    //needs to not be multiples of 2, otherwise SHL is invoked instead.
    int result = v1*11; 
    if (result == 30) {
        while (1){}
    }

    return 0;
}
