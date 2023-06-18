#include <iostream>
#include <sstream>
#include <cstdint>

#include "./state.hpp"
#include "../config.hpp"


/**
 * @brief evaluate the state
 * 
 * @return int 
 */

int State::evaluate(){
  int white = 0;
  int find_king = 0;
  for(int i=0;i<6;i++){
    for(int j=0;j<5;j++){
      int cur = this->board.board[0][i][j];
      if(cur == 6) find_king = 1;
      switch(cur){
        case 1:
        white = white + 2*i;
        break;
        case 2:
        white += 6;
        break;
        case 3:
        white += 7;
        break;
        case 4:
        white += 8;
        break;
        case 5:
        white += 20;
        break;
        case 6:
        white += 0;
        break;
        default:
        white += 0;
      }
    }
  }
  if(!find_king) white = -999999;

  int black = 0;
  find_king = 0;
  for(int i=0;i<6;i++){
    for(int j=0;j<5;j++){
      int cur = this->board.board[1][i][j];
      if(cur == 6) find_king = 1;
      switch(cur){
        case 1:
        black = black + 2*(6-i);
        break;
        case 2:
        black += 6;
        break;
        case 3:
        black += 7;
        break;
        case 4:
        black += 8;
        break;
        case 5:
        black += 20;
        break;
        case 6:
        black += 0;
        break;
        default:
        black += 0;
      }
    }
  }
  if(!find_king) black = -999999;
  if(!this->player) return white - black;
  else return black - white;
}

 /*
int wking[6][5]{
  {0, 0, 0, 0, 0},
  {0, 0,-50, 0, 0},
  {0,-50,-150,-50,0},
  {0, 0,-50, 0, 0},
  {0, 0, 0, 0, 0},
  {50,100,150,100, 50}
};

int bking[6][5]{
  {50,100,150,100, 50},
  {0, 0, 0, 0, 0},
  {0, 0,-50, 0, 0},
  {0,-50,-150,-50,0},
  {0, 0,-50, 0, 0},
  {0, 0, 0, 0, 0}
};

int wbqueen_rook[6][5]{
  {0, 0, 0, 0, 0},
  {0, 30, 50, 30, 0},
  {0, 50,150, 50, 0},
  {0, 50,150, 50, 0},
  {0, 30, 50, 30, 0},
  {0, 0, 0, 0, 0}
};

int wbbishop[6][5]{
  {100, 50, 50, 50,100},
  {100, 0, 0, 0,100},
  {100, 0, 0, 0,100},
  {100, 0, 0, 0,100},
  {100, 0, 0, 0,100},
  {100, 50, 50, 50,100}
};

int wbknight[6][5]{
  {150, 50, 0, 50,150},
  { 50, 0, 0, 0, 50},
  { 0, 0,150, 0, 0},
  { 0, 0,150, 0, 0},
  { 50, 0, 0, 0, 50},
  {150, 50, 0, 50,150}
};

int wpawn[6][5]{
  {150,150,150,150,150},
  {100,100,100,100,100},
  { 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0}
};

int bpawn[6][5]{
  { 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0},
  {100,100,100,100,100},
  {150,150,150,150,150}
};

int State::evaluate(){
  // [TODO] design your own evaluation function
  int white = 0;
  int find_king = 0;
  for(int i=0;i<6;i++){
    for(int j=0;j<5;j++){
      int cur = this->board.board[0][i][j];
      if(cur == 6) find_king = 1;
      switch(cur){
        case 1:
        white += 200;
        white += wpawn[i][j];
        break;
        case 2:
        white += 300;
        white+= wbqueen_rook[i][j];
        break;
        case 3:
        white += 300;
        white+= wbknight[i][j];
        break;
        case 4:
        white += 300;
        white+= wbbishop[i][j];
        break;
        case 5:
        white += 500;
        white+= wbqueen_rook[i][j];
        break;
        case 6:
        white += 300;
        white+= wking[i][j];
        break;
        default:
        break;
      }
    }
  }
  if(!find_king) white = -0X7FFFFFFF;
  find_king = 0;
  int black = 0;
  for(int i=0;i<6;i++){
    for(int j=0;j<5;j++){
      int cur = this->board.board[1][i][j];
      if(cur == 6) find_king = 1;
      switch(cur){
        case 1:
        black += 200;
        black += bpawn[i][j];
        break;
        case 2:
        black += 300;
        black+= wbqueen_rook[i][j];
        break;
        case 3:
        black += 300;
        black+= wbknight[i][j];
        break;
        case 4:
        black += 300;
        black+= wbbishop[i][j];
        break;
        case 5:
        black += 500;
        black+= wbqueen_rook[i][j];
        break;
        case 6:
        black += 300;
        black+= bking[i][j];
        break;
        default:
        break;
      }
    }
  }
  if(!find_king) black = -0X7FFFFFFF;
  if(!this->player) return white - black;
  else return black - white;
}
*/

/**
 * @brief return next state after the move
 * 
 * @param move 
 * @return State* 
 */
State* State::next_state(Move move){
  Board next = this->board;
  Point from = move.first, to = move.second;
  
  int8_t moved = next.board[this->player][from.first][from.second];
  //promotion for pawn
  if(moved == 1 && (to.first==BOARD_H-1 || to.first==0)){
    moved = 5;
  }
  if(next.board[1-this->player][to.first][to.second]){
    next.board[1-this->player][to.first][to.second] = 0;
  }
  
  next.board[this->player][from.first][from.second] = 0;
  next.board[this->player][to.first][to.second] = moved;
  
  State* next_state = new State(next, 1-this->player);
  
  if(this->game_state != WIN)
    next_state->get_legal_actions();
  return next_state;
}


static const int move_table_rook_bishop[8][7][2] = {
  {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, {0, 7}},
  {{0, -1}, {0, -2}, {0, -3}, {0, -4}, {0, -5}, {0, -6}, {0, -7}},
  {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}},
  {{-1, 0}, {-2, 0}, {-3, 0}, {-4, 0}, {-5, 0}, {-6, 0}, {-7, 0}},
  {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}, {7, 7}},
  {{1, -1}, {2, -2}, {3, -3}, {4, -4}, {5, -5}, {6, -6}, {7, -7}},
  {{-1, 1}, {-2, 2}, {-3, 3}, {-4, 4}, {-5, 5}, {-6, 6}, {-7, 7}},
  {{-1, -1}, {-2, -2}, {-3, -3}, {-4, -4}, {-5, -5}, {-6, -6}, {-7, -7}},
};
static const int move_table_knight[8][2] = {
  {1, 2}, {1, -2},
  {-1, 2}, {-1, -2},
  {2, 1}, {2, -1},
  {-2, 1}, {-2, -1},
};
static const int move_table_king[8][2] = {
  {1, 0}, {0, 1}, {-1, 0}, {0, -1}, 
  {1, 1}, {1, -1}, {-1, 1}, {-1, -1},
};


/**
 * @brief get all legal actions of now state
 * 
 */
void State::get_legal_actions(){
  // [Optional]
  // This method is not very efficient
  // You can redesign it
  this->game_state = NONE;
  std::vector<Move> all_actions;
  auto self_board = this->board.board[this->player];
  auto oppn_board = this->board.board[1 - this->player];
  
  int now_piece, oppn_piece;
  for(int i=0; i<BOARD_H; i+=1){
    for(int j=0; j<BOARD_W; j+=1){
      if((now_piece=self_board[i][j])){
        // std::cout << this->player << "," << now_piece << ' ';
        switch (now_piece){
          case 1: //pawn
            if(this->player && i<BOARD_H-1){
              //black
              if(!oppn_board[i+1][j] && !self_board[i+1][j])
                all_actions.push_back(Move(Point(i, j), Point(i+1, j)));
              if(j<BOARD_W-1 && (oppn_piece=oppn_board[i+1][j+1])>0){
                all_actions.push_back(Move(Point(i, j), Point(i+1, j+1)));
                if(oppn_piece==6){
                  this->game_state = WIN;
                  this->legal_actions = all_actions;
                  return;
                }
              }
              if(j>0 && (oppn_piece=oppn_board[i+1][j-1])>0){
                all_actions.push_back(Move(Point(i, j), Point(i+1, j-1)));
                if(oppn_piece==6){
                  this->game_state = WIN;
                  this->legal_actions = all_actions;
                  return;
                }
              }
            }else if(!this->player && i>0){
              //white
              if(!oppn_board[i-1][j] && !self_board[i-1][j])
                all_actions.push_back(Move(Point(i, j), Point(i-1, j)));
              if(j<BOARD_W-1 && (oppn_piece=oppn_board[i-1][j+1])>0){
                all_actions.push_back(Move(Point(i, j), Point(i-1, j+1)));
                if(oppn_piece==6){
                  this->game_state = WIN;
                  this->legal_actions = all_actions;
                  return;
                }
              }
              if(j>0 && (oppn_piece=oppn_board[i-1][j-1])>0){
                all_actions.push_back(Move(Point(i, j), Point(i-1, j-1)));
                if(oppn_piece==6){
                  this->game_state = WIN;
                  this->legal_actions = all_actions;
                  return;
                }
              }
            }
            break;
          
          case 2: //rook
          case 4: //bishop
          case 5: //queen
            int st, end;
            switch (now_piece){
              case 2: st=0; end=4; break; //rook
              case 4: st=4; end=8; break; //bishop
              case 5: st=0; end=8; break; //queen
              default: st=0; end=-1;
            }
            for(int part=st; part<end; part+=1){
              auto move_list = move_table_rook_bishop[part];
              for(int k=0; k<std::max(BOARD_H, BOARD_W); k+=1){
                int p[2] = {move_list[k][0] + i, move_list[k][1] + j};
                
                if(p[0]>=BOARD_H || p[0]<0 || p[1]>=BOARD_W || p[1]<0) break;
                now_piece = self_board[p[0]][p[1]];
                if(now_piece) break;
                
                all_actions.push_back(Move(Point(i, j), Point(p[0], p[1])));
                
                oppn_piece = oppn_board[p[0]][p[1]];
                if(oppn_piece){
                  if(oppn_piece==6){
                    this->game_state = WIN;
                    this->legal_actions = all_actions;
                    return;
                  }else
                    break;
                };
              }
            }
            break;
          
          case 3: //knight
            for(auto move: move_table_knight){
              int x = move[0] + i;
              int y = move[1] + j;
              
              if(x>=BOARD_H || x<0 || y>=BOARD_W || y<0) continue;
              now_piece = self_board[x][y];
              if(now_piece) continue;
              all_actions.push_back(Move(Point(i, j), Point(x, y)));
              
              oppn_piece = oppn_board[x][y];
              if(oppn_piece==6){
                this->game_state = WIN;
                this->legal_actions = all_actions;
                return;
              }
            }
            break;
          
          case 6: //king
            for(auto move: move_table_king){
              int p[2] = {move[0] + i, move[1] + j};
              
              if(p[0]>=BOARD_H || p[0]<0 || p[1]>=BOARD_W || p[1]<0) continue;
              now_piece = self_board[p[0]][p[1]];
              if(now_piece) continue;
              
              all_actions.push_back(Move(Point(i, j), Point(p[0], p[1])));
              
              oppn_piece = oppn_board[p[0]][p[1]];
              if(oppn_piece==6){
                this->game_state = WIN;
                this->legal_actions = all_actions;
                return;
              }
            }
            break;
        }
      }
    }
  }
  std::cout << "\n";
  this->legal_actions = all_actions;
}


const char piece_table[2][7][5] = {
  {" ", "♙", "♖", "♘", "♗", "♕", "♔"},
  {" ", "♟", "♜", "♞", "♝", "♛", "♚"}
};
/**
 * @brief encode the output for command line output
 * 
 * @return std::string 
 */
std::string State::encode_output(){
  std::stringstream ss;
  int now_piece;
  for(int i=0; i<BOARD_H; i+=1){
    for(int j=0; j<BOARD_W; j+=1){
      if((now_piece = this->board.board[0][i][j])){
        ss << std::string(piece_table[0][now_piece]);
      }else if((now_piece = this->board.board[1][i][j])){
        ss << std::string(piece_table[1][now_piece]);
      }else{
        ss << " ";
      }
      ss << " ";
    }
    ss << "\n";
  }
  return ss.str();
}


/**
 * @brief encode the state to the format for player
 * 
 * @return std::string 
 */
std::string State::encode_state(){
  std::stringstream ss;
  ss << this->player;
  ss << "\n";
  for(int pl=0; pl<2; pl+=1){
    for(int i=0; i<BOARD_H; i+=1){
      for(int j=0; j<BOARD_W; j+=1){
        ss << int(this->board.board[pl][i][j]);
        ss << " ";
      }
      ss << "\n";
    }
    ss << "\n";
  }
  return ss.str();
}