#include <iostream>

#include <internal/config.h>

int main()
{
  std::cout << "Hello, world! ";

#ifdef MY_VAR
  std::cout << "Nice to meet you ";
#endif

#ifdef MY_VALUED_VAR
  std::cout << MY_VALUED_VAR;
#endif

#ifdef MY_BIN_VAR
  std::cout << "!\n";
#else
  std::cout << ".\n";
#endif

  return 0;
}
