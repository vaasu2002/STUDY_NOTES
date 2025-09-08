#include <iostream>
#include <string>
#include <vector>

struct Position{
    int row;
    int col;
};
enum Color{
  BLACK,
  WHITE
};
class Piece; // forward decalation
class Cell{
    Position position; // fixed
    Color color; // fixed
    Piece* piece = nullptr;
    public:
    Cell(Position position,Color color):position(position),color(color){}
    bool empty(){return !piece;} 
    Piece* getPiece(){return piece;}
    Color getColor(){return color;}
    void setPiece(Piece* piece){
        this->piece = piece;
    }
};

class Board{
    size_t size; // Square board with one size = number of cells
    std::vector<std::vector<Cell*>> board;
    void setColorOnBoard(){
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if((i+j)%2==0){
                    board[i][j] = new Cell({i,j},Color::BLACK);
                }
                else{
                    board[i][j] = new Cell({i,j},Color::WHITE);
                }
            }
        }
    }
    void initBoard(){
        board.assign(size,std::vector<Cell*>(size,nullptr));
        setColorOnBoard();
        setPeiceRow();
        setPawnsRow();
        // row 0 -> white peice
        // row 1 -> white pawns
        // row 6 -> black pawns
        // row 7 -> white pawns
    }
    public:
    Board(size_t size):size(size){
        board
    }
};
