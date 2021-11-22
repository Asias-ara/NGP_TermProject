#pragma once
#include "GameBitmap.h"
#include "GameObject.h"
#include "Bullet.h"

#define BLTS 5

class Player : public GameObject {
	int id;				// player id
	int hp;					// health point
	float dx, dy;		
	float px, py;			// prior position
	float spd;				// speed 
	POINT CursorPos;
	RECT collision_rect;	// collision rect
	HDC pdc;
public:
	GameObject** other = NULL; //other object
	BulletObject* bullets[BLTS];
public:
	Player(HINSTANCE g_hinst, char id, float x, float y);
	~Player();
	int getId();
	int getX();
	int getY();
	int getSpd();

	void setId(int get_id);
	void setType();
	void setX( int get_x );
	void setY( int get_y );
	void set_aim(float _x, float _y);
	//플레이어의 이전위치(이동전)로 설정
	void setPrevPos();

	//다른 객체를 가져온다.
	void setObject(GameObject** other);

	void fire();
	//키보드 방향키로 이동
	void Move(DWORD dwDirection, float frame_time);


	virtual void update(HWND m_hWnd, float fTimeElapsed);
	virtual void draw(const HDC& mem1dc);

	void send_cursor(HWND m_hWnd);
};