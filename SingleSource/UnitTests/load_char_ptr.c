static char STR[4] = "1234";

int main() {
	char *str = STR;
	__builtin_delendum_write(str[1]);
	return 0;
}