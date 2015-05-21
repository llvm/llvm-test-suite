#if defined(_LITTLE_ENDIAN) && defined(__PPC64__)
#include <thread>

int main()
{
   std::thread t([](){});
   t.join();
   return 0;
}
#else
int main()
{
  return 0;
}
#endif
