
#ifndef OPTIMIZER_BITS_PSO_PSO_HPP
#define OPTIMIZER_BITS_PSO_PSO_HPP

#include "test_function/pso_test_function.hpp"
#define INFINITY 100000.0

using namespace optimization::testFunction;

namespace optimization
{

class PSO
{
public:
  /**
    * Constructs the PSO optimizer. The defaults here are not
    * necessarily good for the given problem, so it is
    * suggested that the values used be tailored to the task at hand.
    * 
    * @param maxIter Maximum no of iterations.
    * @param swarmSize Swarm population size.
    * @param intertia Inertia Coefficient.
    * @param inertiaDamp Damping ratio of inertia coefficient.
    * @param c1 Personal acceleration coeff.
    * @param c2 Global acceleration coeff.
    */
  PSO(const size_t maxIter = 1000,
      const size_t swarmSize = 50,
      double intertia = 1.0,
      const double inertiaDamp = 0.95,
      const double c1 = 2.0,
      const double c2 = 2.0);

  /**
    * Optimize function optimizes the given function.
    * 
    * @ function Function to optimize
    * @ iterate Iterate contains the optimized values for
    *           the function.
    */
  double Optimize(PSOTestFunction function,
                  double *iterate);

private:
  // maximum no of iterations.
  const int maxIter;

  // Swarm population size.
  const int swarmSize;

  // Inertia coeff.
  double intertia;

  // Damping ratio of inertia coeff.
  const double inertiaDamp;

  // Personal acceleration coeff.
  const double c1;

  // Global acceleration coeff.
  const double c2;
}; //class PSO

} // namespace optimization

#include "pso_impl.hpp"

#endif // OPTIMIZER_BITS_PSO_PSO_HPP