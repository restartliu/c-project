#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>
#include<windows.h>

typedef struct coordinate //坐标
{
    int x;
    int y;
    struct coordinate *next;
}CDNT;

typedef struct Tarray
{
    int score;
    char area[28][56];
    CDNT *SnakeHead;
    CDNT food;
    CDNT ModifyXY;
}ARRAY;

#define EAT 1
#define MOVE 0


void MAIN();
void InitArea(ARRAY*);
void InitSnakebody(ARRAY *game);
void ModifySnakebody(ARRAY *game, int arg);
void NewFood(ARRAY *game);
int eat(ARRAY *game);
int ImpactCheck(ARRAY *game);
void print(ARRAY*);

int main(int argc, char const *argv[])
{
    MAIN();
    return 0;
}


void MAIN()
{
    ARRAY *game = (ARRAY*)malloc(sizeof(ARRAY));
    InitArea(game);
    InitSnakebody(game);
    NewFood(game);
    game->ModifyXY.x = game->SnakeHead->x;
    game->ModifyXY.y = game->SnakeHead->y;
    game->score = 0;

    char ch = 'w';
    char ich = ' ';
    while (1)
    {
        if (_kbhit())
        {
            ich = getch();
            if (ich == 'w' || ich == 'a' || ich == 's' || ich =='d')
                if (ich != ch && ( (!(ch == 'w' && ich == 's') && !(ch == 's' && ich == 'w')) && (!(ch == 'a' && ich == 'd') && !(ch == 'd' && ich == 'a')) ))
                    ch = ich;
        }

        if (ch == 'w')
            game->ModifyXY.y -= 1;
        else if (ch == 's')
            game->ModifyXY.y += 1;
        else if (ch == 'a')
            game->ModifyXY.x -= 1;
        else if (ch == 'd')
            game->ModifyXY.x += 1;

        if (ImpactCheck(game) == 0)
        {
            system("cls");
            printf("game over!!!");
            Sleep(3000);
            break;
        }

        if (eat(game))
            ModifySnakebody(game, EAT);
        else
            ModifySnakebody(game, MOVE);
        
        system("cls");
        print(game);
        Sleep(100);
    }

}

void InitArea(ARRAY *game)
{
    for (int i = 0; i < 28; i++)
    {
        game->area[i][0] = '-';
        game->area[i][55] = '-';
        
        for (int j = 1; j < 55; j++)
        {
            if (i == 0 || i == 27)
                game->area[i][j] = '-';
            else
                game->area[i][j] = ' ';
        }
    }
}

void InitSnakebody(ARRAY *game)
{
    CDNT *snake = (CDNT*)malloc(sizeof(CDNT));
    snake->x = 15;
    snake->y = 15;
    game->SnakeHead = snake;
    CDNT *instead = game->SnakeHead;
    for (int i = 16; i < 18; i++)
    {
        snake = (CDNT*)malloc(sizeof(CDNT));
        snake->x = 15;
        snake->y = i;
        snake->next = NULL;
        instead->next = snake;
        instead = instead->next;
    }
}

void ModifySnakebody(ARRAY *game, int arg)
{
    CDNT *head = game->SnakeHead;
    CDNT *new = NULL;
    new = (CDNT*)malloc(sizeof(CDNT));
    new->x = game->ModifyXY.x;
    new->y = game->ModifyXY.y;
    new->next = NULL;
    game->SnakeHead = new;
    game->SnakeHead->next = head;

    head = game->SnakeHead;
    if (!arg)
    {
        while (head->next->next)
            head = head->next;

        game->area[head->next->y][head->next->x] = ' ';
        head->next = NULL;
    }    
}

void NewFood(ARRAY *game)
{
    srand(time(0));
    game->food.x = (rand()%53)+1;
    game->food.y = (rand()%25)+1;
}

int eat(ARRAY *game)
{
    if(game->food.x == game->ModifyXY.x && game->food.y == game->ModifyXY.y)
    {
        game->area[game->food.y][game->food.x] = ' ';
        game->score += 1;
        NewFood(game);
        return 1;
    }
    return 0;
}

int ImpactCheck(ARRAY *game)
{
    CDNT *instead = game->SnakeHead->next;
    if (game->area[game->ModifyXY.y][game->ModifyXY.x] == '-')
        return 0;

    while (instead)
    {
        if (instead->x == game->SnakeHead->x && instead->y == game->SnakeHead->y)
            return 0;
        
        instead = instead->next;
    }
    return 1;
}

void print(ARRAY *game)
{
    char snakebody = '0';
    char food = '#';

    CDNT *instead = game->SnakeHead;
    while (instead)
    {
        game->area[instead->y][instead->x] = snakebody;
        instead = instead->next;
    }

    game->area[game->food.y][game->food.x] = food;
    
    for (int i = 0; i < 28; i++)
    {
        for (int j = 0; j < 56; j++)
            printf("%c", game->area[i][j]);
        
        printf("\n");
    }

    printf("score: %d", game->score);
}
