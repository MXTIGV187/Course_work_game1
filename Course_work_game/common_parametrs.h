#pragma once

#define SPEED 2.0F
/*
* ��� ����� ������������ ������� ����
* ���������� ���
* ������� ����� 
* ����������
* ��������
* ����������� ������
* ������������ ��������� �������
* � ������ �����
*/

struct mainPhysics 
{
	float speed;
	float gravity;
	float XmoveLeft, XmoveRight, Ymove;
	bool onborder;

};

struct mainWindow
{
	int w, h;
	float scaleX, scaleY;
};