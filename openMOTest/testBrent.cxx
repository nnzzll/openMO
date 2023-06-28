#include <iostream>
#include <openMO/brent>

struct Functor : public mo::Function
{
  double operator()(double x) override
  {
    fcalls++;
    return sin(x);
  }
};

int main()
{
  Functor func;
  mo::BrentResult res = mo::brent<Functor>(func);
  std::cout << res << std::endl;
}