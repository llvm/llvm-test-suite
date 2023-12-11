int main()
{
    unsigned v1 = 15;
    unsigned v2 = 1u;
    unsigned v3 = v1 << v2; // shift left by 1 is multiply by 2
    if (v3 == 7) {
        while (1){}
    }

    return 0;
}
