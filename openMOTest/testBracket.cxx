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
  mo::BracketResult res = mo::bracket<Functor>(func, 0.0, 2 * 3.141592653579);
  std::cout << res << std::endl;
  return 0;
}