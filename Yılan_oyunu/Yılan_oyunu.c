#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10
#define MAX_LENGTH (WIDTH * HEIGHT)
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

struct Snake {
    int x, y;
};

struct Fruit {
    int x, y;
};

struct Game {
    struct Snake snake[MAX_LENGTH];
    int length;
    struct Fruit fruit;
    int score;
    int speed;
    int gameOver;
    int direction;
};

void setup(struct Game *game) {
    game->length = 1;
    game->snake[0].x = WIDTH / 2;
    game->snake[0].y = HEIGHT / 2;
    game->gameOver = 0;
    game->score = 0;
    game->speed = 100; 
    
    
    int newX, newY;
    do {
        newX = rand() % (WIDTH - 2) + 1; 
        newY = rand() % (HEIGHT - 2) + 1; 
    } while (newX == game->snake[0].x && newY == game->snake[0].y);

    game->fruit.x = newX;
    game->fruit.y = newY;

    game->direction = RIGHT; 
}

void draw(struct Game *game) {
    system("cls");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1) {
                printf("#");
            } else if (i == game->fruit.y && j == game->fruit.x) {
                printf("*"); 
            } else {
                int isSnakePart = 0;
                for (int k = 0; k < game->length; k++) {
                    if (game->snake[k].x == j && game->snake[k].y == i) {
                        printf("O");
                        isSnakePart = 1;
                        break;
                    }
                }
                if (!isSnakePart) {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    printf("Skor: %d\n", game->score);
}

void input(struct Game *game) {
    if (_kbhit()) {
        char key = _getch();
        switch (key) {
            case 'w':
                if (game->direction != DOWN) {
                    game->direction = UP;
                }
                break;
            case 's':
                if (game->direction != UP) {
                    game->direction = DOWN;
                }
                break;
            case 'a':
                if (game->direction != RIGHT) {
                    game->direction = LEFT;
                }
                break;
            case 'd':
                if (game->direction != LEFT) {
                    game->direction = RIGHT;
                }
                break;
            case 'x':
                game->gameOver = 1;
                break;
        }
        Sleep(game->speed);
    }
}


void logic(struct Game *game) {
    struct Snake prev[MAX_LENGTH];
    for (int i = 0; i < game->length; i++) {
        prev[i] = game->snake[i];
    }

    int prevX = game->snake[0].x;
    int prevY = game->snake[0].y;
    int prev2X, prev2Y;

    switch (game->direction) {
        case UP:
            game->snake[0].y--;
            break;
        case DOWN:
            game->snake[0].y++;
            break;
        case LEFT:
            game->snake[0].x--;
            break;
        case RIGHT:
            game->snake[0].x++;
            break;
    }

    if (game->snake[0].x < 1) game->snake[0].x = WIDTH - 2;
    else if (game->snake[0].x >= WIDTH - 1) game->snake[0].x = 1;
    if (game->snake[0].y < 1) game->snake[0].y = HEIGHT - 2;
    else if (game->snake[0].y >= HEIGHT - 1) game->snake[0].y = 1;

if (game->snake[0].x == game->fruit.x && game->snake[0].y == game->fruit.y) {
    game->score += 10;

    game->snake[game->length].x = prevX;
    game->snake[game->length].y = prevY;
    game->length++;

    int newX, newY;
    do {
        newX = rand() % (WIDTH - 2) + 1; 
        newY = rand() % (HEIGHT - 2) + 1; 
    } while (newX == game->fruit.x && newY == game->fruit.y);

    game->fruit.x = newX;
    game->fruit.y = newY;
}



    for (int i = 1; i < game->length; i++) {
        prev2X = game->snake[i].x;
        prev2Y = game->snake[i].y;
        game->snake[i].x = prevX;
        game->snake[i].y = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    if (game->snake[0].x == 0 || game->snake[0].x == WIDTH - 1 || game->snake[0].y == 0 || game->snake[0].y == HEIGHT - 1) {
        game->gameOver = 1;
        return;
    }

    for (int i = 1; i < game->length; i++) {
        if (game->snake[0].x == game->snake[i].x && game->snake[0].y == game->snake[i].y) {
            game->gameOver = 1;
            return;
        }
    }
}

int main() {
    srand(time(NULL));
    struct Game game;
    char playAgain;

    do {
        setup(&game);
        while (!game.gameOver) {
            draw(&game);
            input(&game);
            logic(&game);
            Sleep(game.speed);
        }

        printf("Oyun bitti! Skor: %d\n", game.score);
        printf("Tekrar oynamak ister misiniz? (E/e: Evet, H/h: Hayır): ");
        scanf(" %c", &playAgain);
        fflush(stdin);
    } while (playAgain == 'E' || playAgain == 'e');

    return 0;
}