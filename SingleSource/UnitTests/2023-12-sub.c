int main()
{
    unsigned v1 = 30;
    unsigned v2 = 12; //Has to be negative, otherwise ADD will be invoked instead.
    unsigned result = v1-v2;
    if (result == 18) {
        while (1){}
    }

    return 0;
}
