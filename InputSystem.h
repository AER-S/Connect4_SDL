#pragma once


class InputSystem
{
	float horizontal;
	float vertical;
	bool used;
	bool down;

public:
	bool fire;
	bool upKey;
	bool downKey;
	bool rightKey;
	bool leftKey;
	bool enter;

	InputSystem();
	void SetHorizontal(float _horizontal);
	void SetVertical(float _vertical);
	float GetHorizontal();
	float GetVertical();
	void SetDown(bool _state);
	bool GetDown();
	bool Use(bool* _trigger);
	void Trig(bool* _trigger);
};

