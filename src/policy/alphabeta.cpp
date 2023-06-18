#include <cstdlib>

#include "../state/state.hpp"
#include "./alphabeta.hpp"
#define max(a,b) ((a)>(b))?(a):(b)
#define min(a,b) ((a)<(b))?(a):(b)

/**
 * @brief Randomly get a legal action
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 
 */

Move alphabeta::get_move(State *state, int depth){
  if(!state->legal_actions.size())
    state->get_legal_actions();

  auto actions = state->legal_actions;
  Move ret = actions[0];
  
  int value = -0X7FFFFFFF;
  for(long unsigned int i=0;i<actions.size();i++){
    int childval = _alphabeta(state->next_state(actions[i]),depth-1,-0X7FFFFFFF,0X7FFFFFFF,0);
    if(childval>value){
        value = childval;
        ret = actions[i];
    }
  }
  
  return ret;
}

int alphabeta::_alphabeta(State* state, int depth, int alpha, int beta, int maximizingPlayer){
    if(depth == 0) return state->evaluate();
    if(!state->legal_actions.size()) state->get_legal_actions();
    if(!state->legal_actions.size()) return state->evaluate();
    auto actions = state->legal_actions;

    if(maximizingPlayer){
        int value = -0X7FFFFFFF;
        for(long unsigned int i = 0;i < actions.size();i++){
            value = max(value,_alphabeta(state->next_state(actions[i]),depth-1,alpha,beta,0));
            alpha = max(alpha, value);
            if(alpha>=beta) break;
        }
        return value;
    }
    else{
        int value = 0X7FFFFFFF;
        for(long unsigned int i = 0;i < actions.size();i++){
            value = min(value,_alphabeta(state->next_state(actions[i]),depth-1,alpha,beta,1));
            beta = min(beta,value);
            if(beta<=alpha) break;
        }
        return value;
    }
}

