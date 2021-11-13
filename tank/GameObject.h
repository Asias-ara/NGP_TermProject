#pragma once
#include "GameBitmap.h"


class GameObject {
protected:
	float x, y;
	GameBitmap* bitmap = NULL;
public:
	GameObject(HINSTANCE g_hinst, char* filename,  float x, float y);
	virtual void update() {};
	virtual void draw(const HDC& hdc, const RECT rect);
	
	bool collide(const RECT& rect1, const RECT& rect2);
	virtual void get_BoundingRect(RECT& rect);
	virtual void draw_BoundingRect(const HDC hdc, const RECT rect);
};