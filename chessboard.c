#define KING 'k'
#define QUEEN 'q'

void main()
{
     char chessboard[8][8];
     chessboard[2][3] = QUEEN;
     if (chessboard[4][7] == KING)
     check_mate();
}