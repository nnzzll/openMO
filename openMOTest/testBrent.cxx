#include <iostream>
#include <openMO/openMO>

struct Functor
{
  double operator()(double x)
  {
    return sin(x);
  }
};

int main(int argc, char** argv)
{
  Functor func;
  mo::BrentResult res = mo::brent<Functor>(func);
  std::cout << res << std::endl;

  mo::Brent<Functor> stBrent(func, 1, 3.141592653579, 2*3.141592653579);
  std::cout << stBrent.optimize(func) << std::endl;
  return 0;
}