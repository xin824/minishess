#pragma once
#include "../state/state.hpp"


/**
 * @brief Policy class for random policy, 
 * your policy class should have get_move method
 */
class alphabeta{
public:
  static Move get_move(State *state, int depth);
  static int _alphabeta(State* state, int depth, int alpha, int beta, int maximizingPlayer);
};