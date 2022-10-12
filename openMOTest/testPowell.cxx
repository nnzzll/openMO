#include <iostream>
#include <openMO/openMO>
#include <Eigen/Core>

struct Functor : mo::BaseFunc
{
  double operator()(Eigen::VectorXd& x) override
  {
    fcalls++;
    return 100 * (x(1) - x(0) * x(0)) * (x(1) - x(0) * x(0)) + (1 - x(0)) * (1 - x(0));
  }
};

int main(int argc, char** argv)
{
  Functor func;
  Eigen::VectorXd x(2);
  x << 0, 0;
  mo::Powell<Functor> powell(2);
  std::cout << powell.optimize(func, x) << std::endl;
}