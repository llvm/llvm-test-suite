int main()
{
    int v1 = -30;
    int result = 12-(v1); //ADD is invoked whether v1 is negative or not.
    if (result == 2) {
        while (1){}
    }

    return 0;
}
