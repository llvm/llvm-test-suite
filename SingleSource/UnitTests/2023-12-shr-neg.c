int main()
{
    unsigned v1 = 15;
    unsigned v2 = 1u;
    unsigned v3 = v1 >> v2; // shift right by 1 is floor of divide by 2
    if (v3 == 17) {
        while (1){}
    }

    return 0;
}
