#include <iostream>
#include <openMO/powell>

struct Rosen : mo::Function
{
  double operator()(const Eigen::VectorXd& x)
  {
    fcalls++;
    double sum = 0;
    for (size_t i = 0; i < x.size() - 1; i++)
    {
      sum += std::pow((x(i + 1) - x(i) * x(i)), 2) * 100.0 + (1.0 - x(i)) * (1.0 - x(i));
    }
    return sum;
  }
};

int main()
{
  Rosen func;
  Eigen::VectorXd x(5);
  x << 1.3, 0.7, 0.8, 1.9, 1.2;
  mo::Powell<Rosen> powell(5);
  std::cout << "Unbounded Powell:" << std::endl;
  std::cout << powell.optimize(func, x) << std::endl;

  Eigen::VectorXd lower_bound(5), upper_bound(5);
  lower_bound << 1.17378569, 0.54749915, 0.69897143, 1.84081221, 1.07606404;
  upper_bound << 1.42427605, 0.70480981, 0.98765271, 2.08745667, 1.39759172;
  mo::Powell<Rosen> bounded_powell(5);
  bounded_powell.SetBound(lower_bound, upper_bound);
  std::cout << "Bounded Powell:" << std::endl;
  std::cout << bounded_powell.optimize(func, x) << std::endl;
}