#pragma once
#include "../state/state.hpp"


/**
 * @brief Policy class for random policy, 
 * your policy class should have get_move method
 */
class minimax{
public:
  static Move get_move(State *state, int depth);
  //static Move get_move(State *state, int depth, int maximizingPlayer);
  //static State* _minimax(State* state, int depth, int maximizingPlayer);
  static int _minimax(State* state, int depth, int maximizingPlayer);
};