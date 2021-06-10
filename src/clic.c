/*
** EPITECH PROJECT, 2020
** clic.c
** File description:
** all the clic gestion
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include "../couscous.h"

void inivariableclic(base_s *tok)
{
    tok->textmouse = sfTexture_createFromFile("pic/aim.png", NULL);
    tok->smouse = sfSprite_create();
    sfSprite_setTexture(tok->smouse, tok->textmouse, sfTrue);
}

int clic(base_s *tok)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        tok->mouse = sfMouse_getPositionRenderWindow(tok->window);
    }
}

int aimtarget(base_s *tok)
{
    tok->mouse = sfMouse_getPositionRenderWindow(tok->window);
    sfRenderWindow_setMouseCursorVisible(tok->window, 0);
    sfSprite_setPosition(tok->smouse, (sfVector2f)
    {(float)tok->mouse.x - 89, tok->mouse.y - 89});
    sfRenderWindow_drawSprite(tok->window, tok->smouse, NULL);
}