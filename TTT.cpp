#include <iostream>
#include <vector>

void draw_board(const std::vector< std::vector<char> >& vec)
{
    std::cout << "    0   1   2  \n";
    std::cout << "  +---+---+---+\n";
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << i << " " ;
        for (int j = 0; j < vec[i].size(); j++)
        {
            std::cout << "| " << vec[i][j] << " ";
        }
        std::cout << "|";
        std::cout << '\n';
        std::cout << "  +---+---+---+\n";
    }
}

void enter(unsigned int row, unsigned int col, char ch, std::vector< std::vector<char> >& vec)
{
    vec[row][col] = ch;
}

bool check(const std::vector< std::vector<char> >& vec)
{
    //to check diagonals
    if ((vec[0][0] == 'X' && vec[1][1] == 'X' && vec[2][2] == 'X')
        || (vec[0][2] == 'X' && vec[1][1] == 'X' && vec[2][0] == 'X'))
        {
            std::cout << "Player X won this game\n";
            return true;
        }
    else if ((vec[0][0] == 'O' && vec[1][1] == 'O' && vec[2][2] == 'O')
             || (vec[0][2] == 'O' && vec[1][1] == 'O' && vec[2][0] == 'O'))
             {
                std::cout << "Player O won this game\n";
                return true;
             }

    //to check horizonatal and vertical
    for (int i = 0; i < vec.size(); i++)
    {
        if ((vec[i][0] == 'X' && vec[i][1] == 'X' && vec[i][2] == 'X')
              || (vec[0][i] == 'X' && vec[1][i] == 'X' && vec[2][i] == 'X'))
              {
                  std::cout << "Player X won this game\n";
                  return true;
              }
        else if((vec[i][0] == 'O' && vec[i][1] == 'O' && vec[i][2] == 'O')
              || (vec[0][i] == 'O' && vec[1][i] == 'O' && vec[2][i] == 'O'))
              {
                  std::cout << "Player O won this game\n";
                  return true;
              }
    }
    return false;
}

void start(std::vector< std::vector<char> >& vec)
{
    unsigned int row, col;
    int res = 0;
    char ch;

    for (int i = 0; i < 9;)
    {
        if (i == 0 || i%2 == 0)
        {
            ch = 'X';
            std::cout << "Chance to enter X\n";
        }
        else
        {
            ch = 'O';
            std::cout << "Chance to enter O\n";
        }
        std::cout << "Enter row number ";
        std::cin >> row;
        std::cout << "Enter column number ";
        std::cin >> col;
        if (row < 3 && col < 3)
        {
            if (vec[row][col] == ' ' || vec[row][col] == ' ')
            {
                enter(row, col, ch, vec);
                draw_board(vec);
                if ( i >= 2)
                {
                    res = check(vec);
                    if (res == 1)
                    {
                      break;
                    }
                }
                i++;
              }
              else
              {
                  std::cerr << "This position already contains a character\n";
              }
        }
        else
        {
            std::cerr << "Enter row number and column number between 0 to 2\n";
        }

    }
    if (res == 0)
    {
        std::cout << "This game draws\n";
    }
}

int main()
{
    std::vector< std::vector<char> > board(3, std::vector<char>(3, ' '));
    draw_board(board);
    start(board);
}
