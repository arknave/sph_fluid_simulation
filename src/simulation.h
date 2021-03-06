#ifndef SIMULATION_H
#define SIMULATION_H

#include "mesh.h"
#include "parameters.h"
#include "particle.h"

#include <vector>

#include <Eigen/Core>

class Simulation {

public:
  Parameters *params;

  Simulation() : params(new Parameters()), current_time(0.0) { }

  void initialize();
  void start();
  void step();
  void reset();

  double current_time;

  // Puts the entire simulation into the two matrices (world coordinates).
  void render(Eigen::MatrixX3d &V, Eigen::MatrixX3i &F) const;

  Eigen::VectorXd getForces(const Eigen::VectorXd &c_new) const;

  void getGravityForce(const Eigen::VectorXd &c, Eigen::VectorXd &force) const;
  void getBoundaryForce(const Eigen::VectorXd &c, Eigen::VectorXd &force) const;

  ~Simulation();

private:
  std::vector<Mesh*> meshes_;
  std::vector<Particle*> particles_;

};

#endif
