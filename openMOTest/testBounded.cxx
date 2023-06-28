#include <iostream>
#include <openMO/bounded>

struct Functor : mo::Function
{
  double operator()(double x) override
  {
    return 3 * x * x - x + 4;
  }
};

int main()
{
  Functor func;
  std::cout << mo::_minimize_scalar_bounded<Functor>(func, -2, 4) << std::endl;
}
