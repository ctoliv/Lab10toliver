class sprite
{
public: 
	~sprite();
	void updatesprite();
	void bouncesprite(int SCREEN_W, int SCREEN_H);
	void load_animated_sprite(int size);
	void drawSprite();
	void initSprite(int SCREEN_W, int SCREEN_H);
	void assignRandomPower();
	void collision(sprite sprites[], int size, int currentIndex, int SCREEN_W, int SCREEN_H);
	int getX(){return x;}
	int getY(){return y;}
	int getWidth() { return width; }
	int getHeight() { return height; }

private:
	int x,y;
	int width,height;
	int xspeed,yspeed;
	int xdelay,ydelay;
	int xcount,ycount;
	int curframe,maxframe,animdir;
	int framecount,framedelay;
	bool CollisionIsTrue;
	bool SpinningSprite;
	bool ScaredSprite;
	bool BabySprite;
	bool FreezeSprite;
	float red;
	float green;
	float blue;
	float scale;
	float angle;
	bool spriteDied;
	ALLEGRO_BITMAP *image[9];
};