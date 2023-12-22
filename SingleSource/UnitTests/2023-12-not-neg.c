int main()
{
    int v1 = 9;
    int v2 = ~v1;
    // ~1001 = 0110
    if (v2 == -1) {
        while (1){}
    }

    return 0;
}
