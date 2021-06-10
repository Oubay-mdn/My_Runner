/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2020
** File description:
** parallax.c
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include "../couscous.h"

int parallax(base_s *tok)
{
    parallax1(tok);
    parallax2(tok);
    parallax3(tok);
    parallax4(tok);
    parallax5(tok);
    parallax6(tok);
    display_ss(tok);
    dp_dragon(tok);
}

int parallax5(base_s *tok)
{
    tok->P5_position.x -= 7;
    sfSprite_setPosition(tok->P5_sprite, tok->P5_position);
    if (tok->P5_position.x <= -1920) {
        tok->P5_position.x = 0;
        sfSprite_setPosition(tok->P5_sprite, tok->P5_position);
    }
    if (sfClock_getElapsedTime(tok->clock5).microseconds > 50000) {
        sfClock_restart(tok->clock5);
    }
}

int parallax6(base_s *tok)
{
    tok->P6_position.x -= 5;
    sfSprite_setPosition(tok->P6_sprite, tok->P6_position);
    if (tok->P6_position.x <= -1920) {
        tok->P6_position.x = 0;
        sfSprite_setPosition(tok->P6_sprite, tok->P6_position);
    }
    if (sfClock_getElapsedTime(tok->clock6).microseconds > 50000) {
        sfClock_restart(tok->clock6);
    }
}

int parallax0(base_s *tok)
{
    tok->P0_position.x -= 20;
    sfSprite_setPosition(tok->P0_sprite, tok->P0_position);
    if (tok->P0_position.x <= -1920) {
        tok->P0_position.x = 0;
        sfSprite_setPosition(tok->P0_sprite, tok->P0_position);
    }
    if (sfClock_getElapsedTime(tok->clock0).microseconds > 50000) {
        sfClock_restart(tok->clock0);
    }
}

void my_draw(base_s *tok)
{
    is_touch(tok);
    jump(tok);
    parallax(tok);
    draw_spara(tok);
    sfRenderWindow_drawSprite(tok->window, tok->sprite_V, NULL);
    sfRenderWindow_drawSprite(tok->window, tok->sprite_D, NULL);
    score(tok);
    tok->str_life[0] = tok->nb_life + 48;
    sfText_setString(tok->life, tok->str_life);
    sfRenderWindow_drawText(tok->window, tok->text_life, NULL);
    sfRenderWindow_drawText(tok->window, tok->life, NULL);
    if (tok->nb_life == 0)
        tok->scene = 2;
}