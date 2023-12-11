int main()
{
    unsigned v1 = 1u;
    unsigned v2 = 15 << v1; // shift left by 1 is multiply by 2
    if (v2 == 3) {
        while (1){}
    }

    return 0;
}
