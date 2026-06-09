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
	int getX(){return x;}
	int getY(){return y;}


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
	ALLEGRO_BITMAP *image[9];
};