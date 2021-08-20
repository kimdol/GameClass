#include <iostream>
#include <cassert>

// 기획서에서 넘어오기에 참고용으로 const 붙이기
const char gStageData[] = "\
########\n\
#..o  p#\n\
#    o #\n\
#      #\n\
########";
const int gStageWidth{ 8 };
const int gStageHeigh{ 5 };

enum Object {
	OBJ_SPACE,
	OBJ_WALL,
	OBJ_GOAL,
	OBJ_BLOCK,
	OBJ_BLOCK_ON_GOAL,
	OBJ_MAN,
	OBJ_MAN_ON_GOAL,

	OBJ_UNKNOWN // 이 이상 숫자가 나오면 비정상으로 체크용도
};

void Initialize(Object* state, int w, int h, const char* stageData);
void Draw(const Object* state, int w, int h);
bool CheckClear(const Object* state, int w, int h);
void Update(Object* state, char input, int w, int h);

int main()
{
	/*디버그 함수*/
	/*int a{ 0 };

	assert(a == 10);*/
	/* 소코반 상자 게임 */
	Object* state = new Object[gStageWidth * gStageHeigh];

	Initialize(state, gStageWidth, gStageHeigh, gStageData);

	while (true)
	{
		Draw(state, gStageWidth, gStageHeigh);
		if (CheckClear(state, gStageWidth, gStageHeigh))
		{
			std::cout << "Congraturation!! You Win!!" <<
				std::endl;
			break;
		}

		std::cout << "a:left d:right w:up s:down. Command?" 
			<< std::endl;
		char input;
		std::cin >> input;

		Update(state, input, gStageWidth, gStageHeigh);
	}

	delete[] state;
}

void Initialize(Object* state, int w, int h, const char* stageData)
{
	const char* d = stageData;
	int x = 0;
	int y = 0;

	while (*d != '\0')
	{
		Object t;

		switch (*d)
		{
			case '#':
				t = OBJ_WALL;
				break;

			case ' ':
				t = OBJ_SPACE;
				break;

			case 'o' :
				t = OBJ_BLOCK;
				break;

			case 'O':
				t = OBJ_BLOCK_ON_GOAL;
				break;

			case '.':
				t = OBJ_GOAL;
				break;

			case 'p':
				t = OBJ_MAN;
				break;

			case 'P':
				t = OBJ_MAN_ON_GOAL;
				break;

			case '\n':
				x = 0;
				++y;
				t = OBJ_UNKNOWN;
				break;

			default:
				t = OBJ_UNKNOWN;
				break;
		}

		if (t != OBJ_UNKNOWN)
		{
			state[y * w + x] = t;
			x++;
		}

		++d;
	}
}

void Draw(const Object* state, int w, int h)
{
	const char font[]{ ' ', '#', '.', 'o', 'O', 'p', 'P' };

	for (int y = 0; y < h; ++y)
	{
		for (int x = 0; x < w; ++x)
		{
			Object o = state[y * w + x];
			std::cout << font[o];
		}
		std::cout << std::endl;
	}
}

bool CheckClear(const Object* state, int w, int h)
{
	for (int i = 0; i < w * h; ++i)
	{
		if (state[i] == OBJ_BLOCK)
		{
			return false;
		}
	}
	return true;
}

void Update(Object* state, char input, int w, int h)
{
	int dx{}, dy{};

	switch (input)
	{
		case 'a':
			dx = -1;
			break;

		case 'd':
			dx = 1;
			break;

		case 'w':
			dy = -1;
			break;

		case 's':
			dy = 1;
			break;

		case 'q':
			delete[] state;
			exit(0);
			break;
	}

	// 플레이어 현재 위치 인덱스
	int i;
	for (i = 0; i < w * h; ++i)
	{
		if (state[i] == OBJ_MAN || state[i] == OBJ_MAN_ON_GOAL)
		{
			break;
		}
	}

	// 현재 위치
	int x = i % w;
	int y = i / w;

	// 이동할 위치
	int tx = x + dx;
	int ty = y + dy;

	if (tx < 0 || ty < 0 || tx >= w || ty >= h)
	{
		return;
	}

	int p = y * w + x;
	int tp = ty * w + tx;

	if (state[tp] == OBJ_SPACE || state[tp] == OBJ_GOAL)
	{
		state[p] = (state[p] == OBJ_MAN_ON_GOAL) ? OBJ_GOAL : OBJ_SPACE;
		state[tp] = (state[tp] == OBJ_GOAL) ? OBJ_MAN_ON_GOAL : OBJ_MAN;
	}
	else if (state[tp] == OBJ_BLOCK || state[tp] == OBJ_BLOCK_ON_GOAL)
	{
		int tx2 = tx + dx;
		int ty2 = ty + dy;

		if (tx2 < 0 || ty2 < 0 || tx2 >= w || ty2 >= h)
		{
			return;
		}

		int tp2 = ty2 * w + tx2;
		if (state[tp2] == OBJ_SPACE || state[tp2] == OBJ_GOAL)
		{
			state[tp2] = (state[tp2] == OBJ_GOAL) ? OBJ_BLOCK_ON_GOAL : OBJ_BLOCK;
			state[tp] = (state[tp] == OBJ_BLOCK_ON_GOAL) ? OBJ_MAN_ON_GOAL : OBJ_MAN;
			state[p] = (state[p] == OBJ_MAN_ON_GOAL) ? OBJ_GOAL : OBJ_SPACE;
		}
	}
}