int main()
{
    int v1 = 30;
    int v2 = -12; //Has to be negative, otherwise ADD will be invoked instead.
    int result = v1-v2;
    if (result == 42) {
        while (1){}
    }

    return 0;
}
