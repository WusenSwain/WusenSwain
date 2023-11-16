#pragma once
#include"common.h"

#define WIDTH 925
#define HEIGHT 725

class Button
{
private:
	int x;
	int y;
	int width;
	int height;
	float scale;
	bool isMouseOver;
	wstring text;
	function<void()> onClick;

public:

	Button(int x, int y, int width, int height, const wstring& text, const function<void()>& onClick)
		: x(x), y(y), width(width), height(height), text(text), onClick(onClick), scale(1.0f), isMouseOver(false)
	{
	}

	void checkMouseOver(int mouseX, int mouseY)
	{
		isMouseOver = (mouseX >= x && mouseX <= x + width && mouseY >= y && mouseY <= y + height);

		if (isMouseOver) {
			scale = 0.9f;
		}
		else {
			scale = 1.0f;
		}
	}

	bool checkClick(int mouseX, int mouseY)
	{
		if (mouseX >= x && mouseX <= x + width && mouseY >= y && mouseY <= y + height)
		{
			onClick();
			isMouseOver = false;
			scale = 1.0f;
			return true;
		}
		return false;
	}

	void draw()
	{
		int scaledWidth = width * scale;
		int scaledHeight = height * scale;
		int scaledX = x + (width - scaledWidth) / 2;
		int scaledY = y + (height - scaledHeight) / 2;

		if (isMouseOver)
		{
			setlinecolor(RGB(0, 0, 0));
			setfillcolor(RGB(254, 229, 161));

		}
		else
		{
			setlinecolor(RGB(0, 0, 0));
			setfillcolor(RGB(235, 196, 9));
		}

		fillroundrect(scaledX, scaledY, scaledX + scaledWidth, scaledY + scaledHeight, 10, 10);
		settextcolor(BLACK);
		setbkmode(TRANSPARENT);
		settextstyle(40 * scale, 0, _T("黑体"));
		int textX = scaledX + (scaledWidth - textwidth(text.c_str())) / 2;
		int textY = scaledY + (scaledHeight - textheight(_T("黑体"))) / 2;
		outtextxy(textX, textY, text.c_str());
	}
};

class Menu {
private:
	int currentIndex;
	vector<IMAGE*> pages;
	vector<vector<Button*>> buttons;

	void addPage(IMAGE* page)
	{
		pages.push_back(page);
		buttons.push_back({});
	}

	void addButton(int index, Button* button)
	{
		if (index >= 0 && index < buttons.size())
		{
			buttons[index].push_back(button);
		}
	}

	void setCurrentIndex(int index)
	{
		if (index >= 0 && index < pages.size())
		{
			currentIndex = index;
		}
	}

	void mouseClick(int mouseX, int mouseY)
	{
		if (currentIndex >= 0 && currentIndex < buttons.size())
		{
			for (Button* button : buttons[currentIndex])
			{
				if (button->checkClick(mouseX, mouseY))
				{
					break;
				}
			}
		}
	}

	void mouseMove(int mouseX, int mouseY)
	{
		if (currentIndex >= 0 && currentIndex < buttons.size())
		{
			for (Button* button : buttons[currentIndex])
			{
				button->checkMouseOver(mouseX, mouseY);
			}
		}
	}

	void draw()
	{
		if (currentIndex >= 0 && currentIndex < pages.size())
		{
			putimage(0, 0, pages[currentIndex]); 

			if (currentIndex >= 0 && currentIndex < buttons.size())
			{
				for (Button* button : buttons[currentIndex])
				{
					button->draw(); 
				}
			}
		}
	}

public:
	Menu()
		:currentIndex(-1)
	{
	}
	~Menu() {}

	void init()
	{
		initgraph(WIDTH, HEIGHT);

		IMAGE menu;
		loadimage(&menu, _T("menu.png"), WIDTH, HEIGHT);

		IMAGE* page1 = new IMAGE(WIDTH, HEIGHT);
		putimage(0, 0, &menu);
		getimage(page1, 0, 0, WIDTH, HEIGHT); 

		addPage(page1);

		Button* button1_1 = new Button(363, 400, 200, 50, L"开始游戏", [&]() {
			setCurrentIndex(1); 
			});
		addButton(0, button1_1); 

		Button* button1_2 = new Button(363, 500, 200, 50, L"关卡选择", [&]() {
			setCurrentIndex(2);
			});
		addButton(0, button1_2);

		Button* button1_3 = new Button(363, 600, 200, 50, L"退  出", [&]() {
			close();
			});
		addButton(0, button1_3);

		IMAGE* page2 = new IMAGE(WIDTH, HEIGHT);
		setfillcolor(RED); 
		solidrectangle(0, 0, WIDTH, HEIGHT); 
		getimage(page2, 0, 0, WIDTH, HEIGHT); 

		addPage(page2);

		Button* button2_1 = new Button(100, 200, 200, 50, L"返回到Page 1", [&]() {
			setCurrentIndex(0); 
			});
		addButton(1, button2_1); 

		IMAGE* page3 = new IMAGE(WIDTH, HEIGHT);
		putimage(0, 0, &menu);
		getimage(page3, 0, 0, WIDTH, HEIGHT); 

		addPage(page3);

		Button* button3_1 = new Button(50, 50, 200, 50, L"返回首页", [&]() {
			setCurrentIndex(0); 
			});
		addButton(2, button3_1); 

		setCurrentIndex(0); 
	}

	void run()
	{
		ExMessage msg;

		BeginBatchDraw(); 

		while (true)
		{
			if (peekmessage(&msg))
			{
				int mouseX = msg.x;
				int mouseY = msg.y;

				switch (msg.message)
				{
				case WM_LBUTTONDOWN: 
					mouseClick(mouseX, mouseY); 
					break;
				case WM_MOUSEMOVE: 
					mouseMove(mouseX, mouseY); 
					break;
				}
			}

			draw(); 
			FlushBatchDraw();
			Sleep(10);
		}

		EndBatchDraw(); 
	}

	void close()
	{
		closegraph(); 
	}
};