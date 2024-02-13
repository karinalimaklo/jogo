#include "enemy.h"
#include "raylib.h"
#include <stdio.h>

//inicialização
const int largura = 800;
const int altura = 450;

Rectangle inimigo = { largura / 2 - 100, largura / 2 - 100, 80, 80 };
Rectangle plataforma = { 0, altura - 25, largura, 25 }; //um chão qualquer
float speed = 0.015; //velocidade dele
float gravity = 0.5; //aplicar efeito de gravidade
bool moveRight = true;

//inicialização do inimigo
void enemy_init () {
    //colocar as fotos do inimigo, etc
}


//movimentação do inimigo
void enemy_moviment (){

    //efeito de gravidade
        if (inimigo.y < plataforma.y)
        {
            inimigo.y += gravity;
        }

        //movimentação dele
        if (moveRight)
        {
            inimigo.x += speed;
            if (inimigo.x + inimigo.width >= plataforma.x + plataforma.width)
            {
                inimigo.x = plataforma.x + plataforma.width - inimigo.width;
                moveRight = false;
            }
        }
        else
        {
            inimigo.x -= speed;
            if (inimigo.x <= plataforma.x)
            {
                inimigo.x = plataforma.x;
                moveRight = true;
            }
        }
}


//desenhar o inimigo
void draw_enemy (){

    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawRectangleRec(plataforma, GREEN);
    DrawRectangleRec(inimigo, VIOLET);

    EndDrawing();

}

