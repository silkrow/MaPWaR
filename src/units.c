#include <SDL2/SDL.h>
#include <stdio.h>
#include <string.h>

#include "con.h"
#include "extern.h"
#include "extern_game.h"
#include "units.h"

int new_unit(Player * p, int x, int y, char* s, int walkable, int sight,
		float d1, float d2, float speed){
	
	Unit * u = malloc(sizeof(Unit));

	u->x = x;
	u->y = y;
	u->to_x = -1;
	u->to_y = 0;

	u->grid.x = x - x%GRID;
	u->grid.y = y - y%GRID;
	u->grid.w = GRID;
	u->grid.h = GRID;

	u->box.x = x - GRID/2;
	u->box.y = y - GRID/2;
	u->box.w = GRID;
	u->box.h = GRID;

	u->last_h = land[u->grid.y/GRID][u->grid.x/GRID].h;

	u->armytype = p->armytype;
	u->backward = p->Army;
	u->name = malloc(50*sizeof(char));
	strcpy(u->name, s);
	u->walkable = walkable;
	u->walking = FALSE;
	u->n_png = 1;
	u->sight = sight;
	u->d1 = d1;
	u->d2 = d2;
	u->speed = speed;
	
	p->army_num++;
	if (p->Army->forward != NULL){
		u->forward = p->Army->forward;
		p->Army->forward->backward = u;
	}
	else u->forward = NULL;

	p->Army->forward = u;

	return TRUE;
}
