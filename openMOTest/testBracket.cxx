#include <iostream>
#include <openMO/bracket>

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
  mo::BracketResult res = mo::bracket<Functor>(func, 0.0, 2 * 3.141592653579);
  std::cout << res << std::endl;
}
