#include <SDL2/SDL.h>
#include <stdio.h>
#include <string.h>

#include "con.h"
#include "extern.h"
#include "units.h"

int new_unit(Player * p, int x, int y, char* s, int walking, int sight,
		float d1, float d2, float speed){
	
	Unit * u = malloc(sizeof(Unit));

	u->x = x;
	u->y = y;

	u->grid.x = x - x%GRID;
	u->grid.y = y - y%GRID;
	u->grid.w = GRID;
	u->grid.h = GRID;

	u->box.x = x - GRID/2;
	u->box.y = y - GRID/2;
	u->box.w = GRID;
	u->box.h = GRID;

	u->playertype = p->playertype;
	u->backward = p->Army;
	u->name = malloc(50*sizeof(char));
	strcpy(u->name, s);
	u->walking = walking;
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
