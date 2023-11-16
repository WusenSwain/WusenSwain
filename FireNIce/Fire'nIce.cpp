#include"common.h"
#include"menu.h"

#define WIDTH 925
#define HEIGHT 725

const int rows = 29;
const int cols = 37;
int rowNum, colNum;
int mapIndex[rows * cols] = {
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,
	1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,1,1,1,1,1,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,
	1,0,0,0,0,0,1,1,8,9,9,9,9,9,9,10,1,1,1,1,1,8,9,9,9,9,9,9,10,1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1, 
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,
	1,1,1,1,1,1,5,6,6,6,6,6,6,6,7,0,0,0,0,0,0,2,3,3,3,3,3,3,3,4,0,0,0,0,1,1,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,
	1,1,1,1,1,1,2,3,3,3,3,3,3,3,4,1,1,1,1,1,1,5,6,6,6,6,6,6,6,7,1,1,1,1,1,1,1
};
IMAGE im_bk, im_wall[16], im_iceMan, im_fireMan, im_lightDoor, im_menu;

class Wall {
public:
	IMAGE im_wall[16];
	int wall_x, wall_y;
	int wall_size = 25;

	void init() {
		loadimage(&im_wall[1], _T("wall1.png"));
		loadimage(&im_wall[2], _T("fire0.png"));
		loadimage(&im_wall[3], _T("fire1.png"));
		loadimage(&im_wall[4], _T("fire2.png"));
		loadimage(&im_wall[5], _T("ice0.png"));
		loadimage(&im_wall[6], _T("ice1.png"));
		loadimage(&im_wall[7], _T("ice2.png"));
		loadimage(&im_wall[8], _T("tox0.png"));
		loadimage(&im_wall[9], _T("tox1.png"));
		loadimage(&im_wall[10], _T("tox2.png"));
		loadimage(&im_wall[11], _T("mud0.png"));
		loadimage(&im_wall[12], _T("mud1.png"));
		loadimage(&im_wall[13], _T("mud2.png"));
		loadimage(&im_wall[14], _T("iceGem.png"));
		loadimage(&im_wall[15], _T("fireGem.png"));
	}

	void draw() {
		for (int i = 0;i < rows * cols;i++) {
			rowNum = i / cols;
			colNum = i % cols;
			wall_x = colNum * 25;
			wall_y = rowNum * 25;
			putimagePng(wall_x, wall_y, &im_wall[mapIndex[i]]);
		}
	}
};

class Role {
public:
	IMAGE im_iceMan, im_fireMan, im_show;
	float x, y;
	float x_left, y_bottom;
	float vx, vy;
	float g;
	float width, height;

	void drawFire() {
		putimagePng(x_left, y_bottom, &im_fireMan);
	}
	void drawIce() {
		putimagePng(25, HEIGHT - 200, &im_iceMan);
	}

	void init() {
		loadimage(&im_fireMan, _T("fireMan.png"));
		loadimage(&im_iceMan, _T("iceMan.png"));
		width = im_fireMan.getwidth();
		height = im_fireMan.getheight();
		updateXY(15, HEIGHT - 100);
		vx = 2.5;
		vy = 0;
		g = 3;
	}

	void updateXY(float mx, float my) {
		x_left = mx;
		y_bottom = my;
	}

	void runRight() {
		x_left += vx;
	}
	void runLeft() {
		x_left -= vx;
	}
	void jump() {
		vy = -30;
	}
	void updateY() {
		//vy += g;
		y_bottom += vy;
	}
	void isOnLand(Wall& wall, float ySpeed) {

	}
};

class FireMan :public Role {

};

class IceMan :public Role {

};

class Door {
public:

};

class Trigger {

};


Wall wall;
Role roleIce, roleFire;
Menu menu;

void startup() {
	loadimage(&im_menu, _T("menu.png"));
	loadimage(&im_bk, _T("background.png"));
	initgraph(WIDTH, HEIGHT);
	wall.init();
	roleFire.init();
	BeginBatchDraw();
}

void show() {
	putimage(0, 0, &im_bk);
	wall.draw();
	roleFire.drawFire();
	roleFire.drawIce();
	FlushBatchDraw();
	Sleep(10);
}

void updateWithoutInput() {
	roleFire.updateY();
}

void updateWithInput() {
	if (_kbhit())
	{
		if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D'))  // 按下D键或右方向键
		{
			roleFire.runRight();
		}
		else if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A'))// 按下A键或左方向键
		{
			roleFire.runLeft();
		}
		if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W'))     // 按下W键或上方向键
		{
			roleFire.jump();
		}
	}
}

int main() {
	startup();
	while (1) {
		show();
		updateWithoutInput();
		updateWithInput();
	}

	return 0;
}
