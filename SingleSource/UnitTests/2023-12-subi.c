int main()
{
    unsigned v1 = 30;
    unsigned result = 42-(v1); //ADD is invoked whether v1 is negative or not.
    if (result == 12) {
        while (1){}
    }

    return 0;
}
