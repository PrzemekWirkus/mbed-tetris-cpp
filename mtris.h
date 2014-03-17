#ifndef MBED_MTRIS_MAIN_HEADER_H
#define MBED_MTRIS_MAIN_HEADER_H

#include <string>
#include <utility>

#define LCD_W           16
#define LCD_H           24
#define BRICK_SIZE_X    4
#define BRICK_SIZE_Y    4

/* QUBE
.... .... .... ....
.##. .##. .##. .##.
.##. .##. .##. .##.
.... .... .... ....
*/
#define BRICK_QUBE_1 {0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0}
#define BRICK_QUBE_2 {0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0}
#define BRICK_QUBE_3 {0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0}
#define BRICK_QUBE_4 {0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0}

/* T-agon
    .... .... .... ....
    .#.. #... .... .#..
    ###. ##.. ###. ##..
    .... #... .#.. .#..
*/
#define BRICK_T_1 {0,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0}
#define BRICK_T_2 {0,0,0,0,1,0,0,0,1,1,0,0,1,0,0,0}
#define BRICK_T_3 {0,0,0,0,0,0,0,0,1,1,1,0,0,1,0,0}
#define BRICK_T_4 {0,0,0,0,0,1,0,0,1,1,0,0,0,1,0,0}

/* L-agon
    #... .... .... ....
    #... ###. ##.. ..#.
    ##.. #... .#.. ###.
    .... .... .#.. ....
*/
#define BRICK_L_1 {1,0,0,0,1,0,0,0,1,1,0,0,0,0,0,0}
#define BRICK_L_2 {0,0,0,0,1,1,1,0,1,0,0,0,0,0,0,0}
#define BRICK_L_3 {0,0,0,0,1,1,0,0,0,1,0,0,0,1,0,0}
#define BRICK_L_4 {0,0,0,0,0,0,1,0,1,1,1,0,0,0,0,0}

/* I-agon
    .#.. .... .#.. ....
    .#.. #### .#.. ####
    .#.. .... .#.. ....
    .#.. .... .#.. ....
*/
#define BRICK_I_1 {0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0}
#define BRICK_I_2 {0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0}
#define BRICK_I_3 {0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0}
#define BRICK_I_4 {0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0}


/* +-agon
    .#.. .#.. .#.. .#..
    ###. ###. ###. ###.
    .#.. .#.. .#.. .#..
    .... .... .... ....
*/
#define BRICK_P_1 {0,1,0,0,1,1,1,0,0,1,0,0,0,0,0,0}
#define BRICK_P_2 {0,1,0,0,1,1,1,0,0,1,0,0,0,0,0,0}
#define BRICK_P_3 {0,1,0,0,1,1,1,0,0,1,0,0,0,0,0,0}
#define BRICK_P_4 {0,1,0,0,1,1,1,0,0,1,0,0,0,0,0,0}                                     

/* *-agon
    .... .... .... ....
    .#.. .#.. .#.. .#..
    .... .... .... ....
    .... .... .... ....
*/
#define BRICK_S_1 {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0}
#define BRICK_S_2 {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0}
#define BRICK_S_3 {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0}
#define BRICK_S_4 {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0}                                           

/* 4-agon
    #... .... #... ....
    ##.. .##. ##.. .##.
    .#.. ##.. .#.. ##..
    .... .... .... ....
*/
#define BRICK_4_1 {1,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0}
#define BRICK_4_2 {0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0}
#define BRICK_4_3 {1,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0}
#define BRICK_4_4 {0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0}

#define MTRIX_BRICOK_COUNT 7

template <class T>
class MBEDtrisBrick
{
public:
    typedef T brick_pattern[BRICK_SIZE_X][BRICK_SIZE_Y];

    MBEDtrisBrick::MBEDtrisBrick()
    {
        brick_index = 0;
        brick_rotate_index = 0;
    }

    char getcell(int posx, int posy)
    {
        static T brick[MTRIX_BRICOK_COUNT][4][BRICK_SIZE_X][BRICK_SIZE_Y] = 
        {
            {BRICK_QUBE_1, BRICK_QUBE_2, BRICK_QUBE_3, BRICK_QUBE_4},
            {BRICK_T_1,    BRICK_T_2,    BRICK_T_3,    BRICK_T_4},
            {BRICK_L_1,    BRICK_L_2,    BRICK_L_3,    BRICK_L_4},
            {BRICK_I_1,    BRICK_I_2,    BRICK_I_3,    BRICK_I_4},
            {BRICK_P_1,    BRICK_P_2,    BRICK_P_3,    BRICK_P_4},
            {BRICK_S_1,    BRICK_S_2,    BRICK_S_3,    BRICK_S_4},
            {BRICK_4_1,    BRICK_4_2,    BRICK_4_3,    BRICK_4_4}
        };

        return brick[brick_index][brick_rotate_index][posx][posy];
    }

    int rotate_next() { return brick_rotate_index = (brick_rotate_index + 1) % 4; }
    int rotate_prev() { return brick_rotate_index = (brick_rotate_index == 0) ? 3 : brick_rotate_index - 1; }

    int brick_next() { return brick_index = (brick_index + 1) % MTRIX_BRICOK_COUNT; }
    int brick_prev() { return brick_index = (brick_index == 0) ? (MTRIX_BRICOK_COUNT - 1) : brick_rotate_index - 1; }

protected:
    int brick_index;
    int brick_rotate_index;
};


template <class T>
class MBEDtrisTheGame
{
public:
    MBEDtrisTheGame::MBEDtrisTheGame()
    {
        fill_matrix(0);
    }

    void set_new_brick_pos()
    {
        int g_brick_pos_x = (LCD_W) / 2;
        int g_brick_pos_y = 0;
    }

    void fill_matrix(char pattern)
    {
        for (int x = 0; x < LCD_W; x++)
        {
            for (int y = 0; y < LCD_H; y++)
            {
                lcd_matrix[x][y] = pattern;
            }
        }
    }

public:
    bool detect_brick_bottom_collision(int offset_x, int offset_y);
    bool detect_brick_collision(int offset_x, int offset_y);
    bool detect_brick_side_collision(int offset_x, int offset_y);
    bool append_brick_to_matrix();

    bool try_move_left();
    bool try_move_right();
    bool try_move_down();
    bool try_rotate();

    void move_brick_left(int offset = 1)    { g_brick_pos_x -= offset; }
    void move_brick_right(int offset = 1)   { g_brick_pos_x += offset; }
    void move_brick_up(int offset = 1)      { g_brick_pos_y -= offset; }
    void move_brick_down(int offset = 1)    { try_move_down(); }

    T get_matrix_cell(int pos_x, int pos_y) { return lcd_matrix[pos_x][pos_y]; }
    T get_brick_cell(int pos_x, int pos_y)  { return brick.getcell(pos_x, pos_y); }
    std::pair<int, int> get_brick_pos()     { return std::make_pair(g_brick_pos_x, g_brick_pos_y); }

protected:
    // Brick in use
    MBEDtrisBrick<T> brick;

    // Display with solid elements
    T lcd_matrix[LCD_W][LCD_H];

    // Curent brick screen posiotion
    int g_brick_pos_x;
    int g_brick_pos_y;
};

#endif

template <class T>
bool MBEDtrisTheGame<T>::detect_brick_bottom_collision(int offset_x, int offset_y)
{
    for (int x = 0; x < BRICK_SIZE_X; x++)
    {
        for (int y = 0; y < BRICK_SIZE_Y; y++)
        {
            if (brick.getcell(x, y) && (g_brick_pos_y + offset_y + y >= LCD_H))
            {
                return true;
            }
        }
    }
    return false;
}

template <class T>
bool MBEDtrisTheGame<T>::detect_brick_collision(int offset_x, int offset_y)
{
    for (int x = 0; x < BRICK_SIZE_X; x++)
    {
        for (int y = 0; y < BRICK_SIZE_Y; y++)
        {
            if (brick.getcell(x, y) && lcd_matrix[g_brick_pos_x + offset_x + x][g_brick_pos_y + offset_y + y])
            {
                return true;
            }
        }
    }
    return false;
}

template <class T>
bool MBEDtrisTheGame<T>::detect_brick_side_collision(int offset_x, int offset_y)
{
    for (int x = 0; x < BRICK_SIZE_X; x++)
    {
        for (int y = 0; y < BRICK_SIZE_Y; y++)
        {
            if (brick.getcell(x, y) && g_brick_pos_x + offset_x + x < 0)
            {
                return true;
            }
            if (brick.getcell(x, y) && (g_brick_pos_x + offset_x + x >= LCD_W))
            {
                return true;
            }
        }
    }
    return false;
}

template <class T>
bool MBEDtrisTheGame<T>::append_brick_to_matrix()
{
    for (int x = 0; x < BRICK_SIZE_X; x++)
    {
        for (int y = 0; y < BRICK_SIZE_Y; y++)
        {
            if (brick.getcell(x, y))
            {
                lcd_matrix[g_brick_pos_x + x][g_brick_pos_y + y] = brick.getcell(x, y);
            }
        }
    }
    return true;
}

template <class T>
bool MBEDtrisTheGame<T>::try_move_left()
{
    bool collision_size = detect_brick_side_collision(-1, 0);
    bool collision_brick = detect_brick_collision(-1, 0);
    if (!collision_size && !collision_brick)
    {
        g_brick_pos_x--;
        return true;
    }
    return false;
}

template <class T>
bool MBEDtrisTheGame<T>::try_move_right()
{
    bool collision_size = detect_brick_side_collision(1, 0);
    bool collision_brick = detect_brick_collision(1, 0);
    if (!collision_size && !collision_brick)
    {
        g_brick_pos_x++;
        return true;
    }
    return false;
}

template <class T>
bool MBEDtrisTheGame<T>::try_move_down()
{
    bool brick_collision = detect_brick_collision(0, 1);
    bool brick_bottom_collision = detect_brick_bottom_collision(0, 1);

    if (brick_collision || brick_bottom_collision)
    {
        append_brick_to_matrix();
        // Create new brick
        brick.brick_next();
        g_brick_pos_x = (LCD_W - BRICK_SIZE_X) / 2;
        g_brick_pos_y = 0;
        return false;
    }
    g_brick_pos_y++;
    return true;
}

template <class T>
bool MBEDtrisTheGame<T>::try_rotate()
{
    brick.rotate_next();
    bool brick_collision = detect_brick_collision(0, 1);
    bool brick_bottom_collision = detect_brick_bottom_collision(0, 1);
    bool brick_side_collision = detect_brick_side_collision(0, 0);

    if (brick_collision || brick_bottom_collision || brick_side_collision)
    {
        brick.rotate_prev();
        return false;
    }
    return true;
}
