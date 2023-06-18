#include <cstdlib>

#include "../state/state.hpp"
#include "./minimax.hpp"
#define max(a,b) ((a)>(b))?(a):(b)
#define min(a,b) ((a)<(b))?(a):(b)

/**
 * @brief Randomly get a legal action
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 
 */

/*
Move minimax::get_move(State *state, int depth){
  if(!state->legal_actions.size())
    state->get_legal_actions();

  auto actions = state->legal_actions;
  Move ret = actions[0];
  
  int value = -0X7FFFFFFF;
  for(long unsigned int i=0;i<actions.size();i++){
    State* next = state->next_state(actions[i]);
    State* child = _minimax(next,depth-1,0);
    ret = (child->value>value)?(child->move):(ret);
    value = (child->value>value)?(child->value):(value);
  }
  
  return ret;
}
*/

Move minimax::get_move(State *state, int depth){
  if(!state->legal_actions.size())
    state->get_legal_actions();

  auto actions = state->legal_actions;
  Move ret = actions[0];
  
  int value = -0X7FFFFFFF;
  for(long unsigned int i=0;i<actions.size();i++){
    int childval = _minimax(state->next_state(actions[i]),depth-1,0);
    if(childval>value){
        value = childval;
        ret = actions[i];
    }
  }
  
  return ret;
}

int  minimax::_minimax(State* state, int depth, int maximizingPlayer){
    if(depth == 0) return state->evaluate();
    if(!state->legal_actions.size()) state->get_legal_actions();
    if(!state->legal_actions.size()) return state->evaluate();
    auto actions = state->legal_actions;

    if(maximizingPlayer){
        int value = -0X7FFFFFFF;
        for(long unsigned int i = 0;i < actions.size();i++){
            value = max(value,_minimax(state->next_state(actions[i]),depth-1,0));
        }
        return value;
    }
    else{
        int value = 0X7FFFFFFF;
        for(long unsigned int i = 0;i < actions.size();i++){
            value = min(value,_minimax(state->next_state(actions[i]),depth-1,1));
        }
        return value;
    }
}
/*
State* minimax::_minimax(State* state, int depth, int maximizingPlayer){
    if(depth == 0) return state;
    if(!state->legal_actions.size()) state->get_legal_actions();
    auto actions = state->legal_actions;
    if(!actions.size()) return state;

    if(maximizingPlayer){
        int value = -0X7FFFFFFF;
        State* ret = state;
        for(long unsigned int i = 0;i<actions.size();i++){
            State* next = state->next_state(actions[i]);
            State* child = _minimax(next,depth-1,0);
            ret = (child->value>value)?(child):(ret);
            value = (child->value>value)?(child->value):(value);
        }
        return ret;
    }
    else{
        int value = 0X7FFFFFFF;
        State* ret = state;
        for(long unsigned int i = 0;i<actions.size();i++){
            State* next = state->next_state(actions[i]);
            State* child = _minimax(next,depth-1,1);
            ret = (child->value<value)?(child):(ret);
            value = (child->value<value)?(child->value):(value);
        }
        return ret;
    }
}
*/

