#ifndef PARAMETERS_H
#define PARAMETERS_H

class Parameters {

public:
  bool paused;                                      // animation on.
  double time_step;                                 // s? hopefully.

  double gravity;

  double boundary_penalty;
  double boundary_min;
  double boundary_max;

  int nb_particles;                                 // number particles.
  double radius;                                    // render radius.
  double mass;                                      // kg.
  double density;                                   // kg / m^3.
  double viscocity;                                 // N s / m^3.

  Parameters() {
    reset();
  }

  void reset() {
    paused = true;
    time_step = 0.01;

    gravity = -9.8;

    boundary_penalty = 1e4;
    boundary_min = 0.0;
    boundary_max = 1.0;

    nb_particles = 10;

    radius = 0.1;
    mass = 0.012;
    density = 1000.0;
    viscocity = 50.0;
  }

};

#endif
