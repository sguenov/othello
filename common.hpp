#ifndef __COMMON_H__
#define __COMMON_H__

enum Side { 
    WHITE, BLACK
};

class Move {
   
public:
    int x, y;
    double score;
    Move(int x, int y, double score = 0) {
        this->x = x;
        this->y = y;
        this->score = score;        
    }
    ~Move() {}

    int getX() { return x; }
    int getY() { return y; }
    double getScore(){return score;}
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
    void setScore(double score){this->score = score;}
};
// class ComplexMove {
   
// public:
//     int x, y;
//     double score;
//     ComplexMove * next;
//     ComplexMove(int x, int y, double score = 0, ComplexMove * next = nullptr) {
//         this->x = x;
//         this->y = y;
//         this->score = score;
//         this->next = next;        
//     }
//     ~ComplexMove() {}

//     int getX() { return x; }
//     int getY() { return y; }
//     double getScore(){return score;}
//     ComplexMove * peek(){
//         return next;
//     }
//     void setX(int x) { this->x = x; }
//     void setY(int y) { this->y = y; }
//     void setScore(double score){this->score = score;}
//     void setNext(ComplexMove * next){this->next = next;}
//     Move * toMove(){
//         Move * mov = new Move(x,y);
//         return  mov;
//     }
// };
#endif
