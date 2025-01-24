#include "pch.h"
#include "../LQueue/LQueue.h"
TEST(LQueue, Correct_IsEmpty) {
	LQueue<int> q1;
	EXPECT_EQ(1, q1.IsEmpty());
	q1.Push(1);
	EXPECT_EQ(0, q1.IsEmpty());
}
TEST(LQueue, Correct_Push_Pop) {
	LQueue<int> q1;
	for (int i = 0; i < 5; i++) {
		q1.Push(i);
	}
	for (size_t i = 0; i < 5; i++)
	{
		EXPECT_EQ(i, q1.Pop());
	}
}
TEST(LQueue, Correct_Peeks) {
	LQueue<int> q1;
	int head = 0;
	q1.Push(head);
	for (int i = 1; i < 5; i++) {
		q1.Push(i);
		EXPECT_EQ(head, q1.PeekHead());//голова не меняется
		EXPECT_EQ(i, q1.PeekTail());//хвост совпадает с новым добалвенным
	}
}
TEST(LQueue, Correct_Equal) {
	LQueue<int> q1, q2;
	for (size_t i = 0; i < 5; i++)
	{
		q1.Push(i);
		q2.Push(i);
	}
	EXPECT_EQ(q1, q2); //одинаковые равны
	q1.Pop();
	EXPECT_NE(q1, q2); //разные неравны
}
TEST(LQueue, Correct_Assignment) {
	LQueue<int> q1, q2;
	for (int i = 0; i < 5; i++) {
		q1.Push(i);
	}
	q2 = q1;
	EXPECT_EQ(q1, q2);//одинаковые элементы
	q1.Pop();
	EXPECT_NE(q1, q2);//скопированы не указатели
}

