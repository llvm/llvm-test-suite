extern const char *__crashreporter_info__;

int main() {
   __crashreporter_info__ = "foo";
   return 0;
}
