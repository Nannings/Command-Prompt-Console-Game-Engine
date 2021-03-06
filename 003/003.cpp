
#include "stdafx.h";
#include "olcConsoleGameEngine.h";
using namespace std;
//#include <Windows.h>
class Demo : public olcConsoleGameEngine
{
public:
	Demo()
	{

	}
protected:
	virtual bool OnUserCreate() {
		m_fPlayerX = 10.0f;
		m_fPlayerY = 10.0f;
		return true;
	}
	virtual bool OnUserUpdate(float fElapsedTime) {

		float speed = 40;

		if (m_keys[VK_LEFT].bHeld)
			m_fPlayerX -= speed * fElapsedTime;
		if (m_keys[VK_RIGHT].bHeld)
			m_fPlayerX += speed * fElapsedTime;
		if (m_keys[VK_UP].bHeld)
			m_fPlayerY -= speed * fElapsedTime;
		if (m_keys[VK_DOWN].bHeld)
			m_fPlayerY += speed * fElapsedTime;

		Fill(0, 0, m_nScreenWidth, m_nScreenHeight, L' ', 0);
		Fill((int)m_fPlayerX, (int)m_fPlayerY, (int)m_fPlayerX + 5, (int)m_fPlayerY + 5, PIXEL_SOLID, rand() % 16);

		//for (int x = 0; x < m_nScreenWidth; x++)
		//{
		//	for (int y = 0; y < m_nScreenHeight; y++)
		//	{
		//		Draw(x, y, L'#', rand() % 16);
		//	}

		//}

		return true;
	}

private:
	float m_fPlayerX;
	float m_fPlayerY;
};

int main() {

	Demo game;
	game.ConstructConsole(160, 100, 8, 8);
	game.Start();

	return 0;
}