#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <stdio.h>
#include "Sprite.h"

#include <iostream>
using namespace std;

void sprite::drawSprite()
{
	if (SpinningSprite)
	{
		// Spinning sprites rotate around their center while animating.
		al_draw_rotated_bitmap(
			image[curframe],
			width / 2,
			height / 2,
			x + width / 2,
			y + height / 2,
			angle,
			0
		);
	}
	else if (BabySprite)
	{
		// Draw baby sprites using their current scale.
		al_draw_scaled_bitmap(
			image[curframe],
			0, 0,
			width, height,
			x, y,
			width * scale, height * scale,
			0
		);
	}
	else if (ScaredSprite)
	{
		// Draw scared sprites with their current tint color.
		al_draw_tinted_bitmap(image[curframe], al_map_rgba_f(red, green, blue, 1), x, y, 0);
	}
	else
	{
		al_draw_bitmap(image[curframe], x, y, 0);
	}
}

void sprite::updatesprite()
{
	if (FreezeSprite && freezeCount > 0)
	{
		// Count down while the sprite is frozen.
		freezeCount--;

		if (framecount++ > framedelay)
		{
			framecount = 0;
			curframe++;
			if (curframe >= maxframe)
				curframe = 0;
		}

		return;
	}

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

	if (SpinningSprite)
	{
		// Spinning sprites rotate as they animate.
		angle += 0.1;
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

	// Start the sprite with normal coloring.
	red = 1;
	green = 1;
	blue = 1;

	// Start the sprite at normal size.
	scale = 1.0;
	angle = 0;
	spriteDied = false;
	freezeCount = 0;
}

void sprite::collision(sprite sprites[], int size, int currentIndex, int SCREEN_W, int SCREEN_H)
{
	// Check this sprite against every other sprite.
	for (int i = 0; i < size; i++)
	{
		// Do not check a sprite against itself.
		if (i == currentIndex)
			continue;

		// Check whether the two sprite rectangles overlap.
		if (x < sprites[i].getX() + sprites[i].getWidth() &&
			x + width > sprites[i].getX() &&
			y < sprites[i].getY() + sprites[i].getHeight() &&
			y + height > sprites[i].getY())
		{
			CollisionIsTrue = true;

			if (ScaredSprite)
			{
				// Scared sprites change to a random tint after a collision.
				red = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
				green = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
				blue = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
			}

			if (BabySprite)
			{
				// Baby sprites shrink after collisions.
				scale = scale / 2;

				if (scale <= 0.05 && spriteDied == false)
				{
					cout << "The baby sprite died." << endl;
					spriteDied = true;
				}
			}

			if (FreezeSprite)
			{
				// Freeze sprites stop moving for 5 seconds after a collision.
				freezeCount = 300;
			}

			// Move the sprite to a random location after collision.
			x = rand() % (SCREEN_W - width);
			y = rand() % (SCREEN_H - height);
		}
	}
}

sprite::~sprite()
{
	for(int i = 0; i < maxframe; i++)
		al_destroy_bitmap(image[i]);
}



