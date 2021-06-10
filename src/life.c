/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-oubay.moudden
** File description:
** life
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include "../couscous.h"

void is_touch(base_s *tok)
{
    sfVector2f d_pos = sfSprite_getPosition(tok->sprite_D);
    sfVector2f v_pos = sfSprite_getPosition(tok->sprite_V);

    if (((d_pos.x + 100) >= (v_pos.x + 91) && d_pos.x <= (v_pos.x + 91))
    || (v_pos.x <= (d_pos.x + 100) && d_pos.x <= v_pos.x) || (v_pos.x < d_pos.x
    && d_pos.x + 100 < v_pos.x + 91)) {
        if (((v_pos.y + 115) <= (d_pos.y + 150) && d_pos.y <= (v_pos.y + 115))
        || (v_pos.y <= d_pos.y + 200 && d_pos.y <= v_pos.y) ||
        (v_pos.y < d_pos.y && d_pos.y + 150 < v_pos.y + 115)) {
            sfSprite_setPosition(tok->sprite_D, (sfVector2f){-200, -200});
            tok->nb_life -= 1;
            sfSound_play(tok->touchsound);
        }
    }
}

void jump(base_s *tok)
{
    if (sfSprite_getPosition(tok->sprite_V).x > 10 && tok->is_jumping == 0)
        sfSprite_move(tok->sprite_V, (sfVector2f){-1, 0});
    if (sfKeyboard_isKeyPressed(sfKeySpace) && tok->is_jumping == 0) {
        tok->air = -25;
        sfSound_play(tok->jsound);
    }
    if (tok->air < 0) {
        sfSprite_move(tok->sprite_V, (sfVector2f){8, -20});
        tok->air++;
    }
    if (sfSprite_getPosition(tok->sprite_V).y < 835) {
        tok->is_jumping++;
        sfSprite_move(tok->sprite_V, (sfVector2f){0, 5});
    }
    if (sfSprite_getPosition(tok->sprite_V).y == 835) {
        tok->is_jumping = 0;
        tok->air = 0;
    }
}

void init_soundj(base_s *tok)
{
    tok->buffsound = sfSoundBuffer_createFromFile("music/jump.ogg");
    tok->jsound = sfSound_create();
    sfSound_setBuffer(tok->jsound, tok->buffsound);
    sfSound_setVolume(tok->jsound, 20);
    tok->buffertouchs = sfSoundBuffer_createFromFile("music/hit.ogg");
    tok->touchsound = sfSound_create();
    sfSound_setBuffer(tok->touchsound, tok->buffertouchs);
    sfSound_setVolume(tok->touchsound, 800);
    tok->bufflol = sfSoundBuffer_createFromFile("music/play.ogg");
    tok->lolsound = sfSound_create();
    sfSound_setBuffer(tok->lolsound, tok->bufflol);
    sfSound_setVolume(tok->lolsound, 1000);
}