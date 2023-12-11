int main()
{
    int v1 = 30;
    int v2 = -11; //needs to not be multiples of 2, otherwise SHL is invoked instead.
    int result = v1*v2;
    if (result == -36) {
        while (1){}
    }

    return 0;
}
