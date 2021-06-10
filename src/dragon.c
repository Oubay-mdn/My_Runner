/*
** EPITECH PROJECT, 2020
** dragon.c
** File description:
** all the setup for the dragon
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include "../couscous.h"

void inivariable_dragon(base_s *tok)
{
    tok->recd.top = 0;
    tok->recd.left = 10;
    tok->recd.width = 200;
    tok->recd.height = 200;
    tok->D_position.x = 1700;
    tok->D_position.y = 780;
    tok->sprite_D = sfSprite_create();
    tok->texture_D = sfTexture_createFromFile("pic/Dragon.png", NULL);
    sfSprite_setTexture(tok->sprite_D, tok->texture_D, sfTrue);
    sfSprite_setTextureRect(tok->sprite_D, tok->rect);
    sfSprite_setPosition(tok->sprite_D, tok->D_position);
    tok->clockd = sfClock_create();
}

int dp_dragon(base_s *tok)
{
    sfVector2f d_pos = sfSprite_getPosition(tok->sprite_D);

    if (sfClock_getElapsedTime(tok->clockd).microseconds / 10000 > 10) {
        tok->recd.left += 200;
        tok->myscore += 10;
        if (d_pos.x > 0-200)
            sfSprite_move(tok->sprite_D, (sfVector2f){-80, 0});
        else
            sfSprite_setPosition(tok->sprite_D, (sfVector2f){1920, 780});
        sfSprite_setTextureRect(tok->sprite_D, tok->recd);
        if (tok->recd.left >= 200 * 3)
            tok->recd.left = 0;
        sfClock_restart(tok->clockd);
    }
    sfRenderWindow_drawSprite(tok->window, tok->sprite_V, NULL);
}