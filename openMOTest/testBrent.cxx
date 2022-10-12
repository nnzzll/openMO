#include <iostream>
#include <openMO/openMO>
#include <Eigen/Core>

struct Functor : mo::BaseFunc
{
  double operator()(double x) override
  {
    fcalls++;
    return sin(x);
  }
};

int main(int argc, char** argv)
{
  Functor func;
  mo::BrentResult res = mo::brent<Functor>(func);
  std::cout << res << std::endl;

  mo::Brent<Functor> stBrent2(func, 3.141592653579, 2 * 3.141592653579);
  std::cout << stBrent2.optimize(func) << std::endl;

  mo::Brent<Functor> stBrent3(func, 1, 3.141592653579, 2 * 3.141592653579);
  std::cout << stBrent3.optimize(func) << std::endl;
  return 0;
}