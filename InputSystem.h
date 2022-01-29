#pragma once


class InputSystem
{
	float horizontal;
	float vertical;
	bool used;

public:
	bool fire;
	bool enter;
	bool* numbers;
	InputSystem();
	void SetHorizontal(float _horizontal);
	void SetVertical(float _vertical);
	float GetHorizontal();
	float GetVertical();
	bool Use(bool* _trigger);
	void Trig(bool* _trigger);
};

