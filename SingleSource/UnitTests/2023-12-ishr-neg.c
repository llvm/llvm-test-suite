int main()
{
    unsigned v1 = 1u;
    unsigned v2 = 15 >> v1; // shift right by 1 is floor of divide by 2
    if (v2 == 8) {
        while (1){}
    }

    return 0;
}
