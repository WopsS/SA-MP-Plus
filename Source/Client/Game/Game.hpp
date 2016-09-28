#pragma once

class Game : public Singleton<Game>
{
public:

private:

	friend class Singleton<Game>;

	Game();
	~Game();
};