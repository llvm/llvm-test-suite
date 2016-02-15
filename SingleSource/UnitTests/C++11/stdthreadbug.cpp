#include <thread>

int main()
{
   std::thread t([](){});
   t.join();
   return 0;
}
