#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <stdio.h>
#include "Sprite.h"

#include <iostream>
using namespace std;

void sprite::drawSprite()
{
	al_draw_bitmap(image[curframe],x,y,0);
}

void sprite::updatesprite()
{
	//update x position
	if (++xcount > xdelay)
	{
		xcount = 0;
		x += xspeed;
	}

	//update y position
	if (++ycount > ydelay)
	{
		ycount = 0;
		y += yspeed;
	}


	if (framecount++ > framedelay)
	{
		framecount = 0;
		curframe++;
		if (curframe >= maxframe)
			curframe = 0;
	}
}

void sprite::bouncesprite(int SCREEN_W, int SCREEN_H)
{
	//simple screen bouncing behavior
	if (x < 0)
	{
		x = 0;
		xspeed = rand() % 2 + 4;
		animdir *= -1;
	}

	else if (x > SCREEN_W - width)
	{
		x = SCREEN_W - width;
		xspeed = rand() % 2 - 6;
		animdir *= -1;
	}

	if (y < 0)
	{
		y = 0;
		yspeed = rand() % 2 + 4;
		animdir *= -1;
	}

	else if (y > SCREEN_H - height)
	{
		y = SCREEN_H -  height;
		yspeed = rand() % 2 - 6;
		animdir *= -1;
	}

}

void sprite::load_animated_sprite(int size)
{
	//load the animated sprite
	char s[80];
	maxframe=size;
	for (int n=0; n<size; n++)
	{
		sprintf_s(s,"Alien%d.bmp",n);
		image[n] = al_load_bitmap(s);

		al_convert_mask_to_alpha(image[n], al_map_rgb(255, 255, 255));
	}  
	width=al_get_bitmap_width(image[0]);
	height=al_get_bitmap_height(image[0]);
	curframe = 0;
	framedelay = 5;
	framecount = 0;


}

void sprite::initSprite(int SCREEN_W, int SCREEN_H)
{
	// Give each sprite a random starting position and movement speed.
	x = rand() % (SCREEN_W - width);
	y = rand() % (SCREEN_H - height);

	xspeed = rand() % 5 + 1;
	yspeed = rand() % 5 + 1;

	if (rand() % 2 == 0)
		xspeed *= -1;

	if (rand() % 2 == 0)
		yspeed *= -1;

	xdelay = 0;
	ydelay = 0;
	xcount = 0;
	ycount = 0;
	animdir = 1;
}

void sprite::assignRandomPower()
{
	// Each sprite receives one random specialty power.
	CollisionIsTrue = false;

	SpinningSprite = false;
	ScaredSprite = false;
	BabySprite = false;
	FreezeSprite = false;

	int power = rand() % 4;

	if (power == 0)
		SpinningSprite = true;
	else if (power == 1)
		ScaredSprite = true;
	else if (power == 2)
		BabySprite = true;
	else if (power == 3)
		FreezeSprite = true;
}

sprite::~sprite()
{
	for(int i = 0; i < maxframe; i++)
		al_destroy_bitmap(image[i]);
}



