#include <iostream.h>
#include <conio.h>
#include <stdio.h>

#define N 1000


struct Stack{
	int list[N];
	int top;
};

void Initialize (Stack &s)
{
	s.top = -1;
}

int Empty(Stack s)
{	
	if (s.top == -1)
		return 1; // stack r?ng
	else
		return 0;
}

int isFull(Stack s)
{		
	if (s.top>= N - 1) return 1;
	else 		
		return 0;		
}

void Push (Stack &s, int x)
{	
	if (!isFull(s)) // stack chua day 
	{	
		s.top++;
		s.list[s.top]=x;
	}
}

int Pop(Stack &s)
{	 
	int x;
	if (!Empty(s)) // stack khác rong
	{
		x = s.list[s.top];
		s.top--;		
	}
	return x;
}

