#pragma once
#ifndef queue
#define queue

#include<iosfwd>
#include<stdint.h>
#include<memory>



struct Queue{

private:
	//������������ ������� � �����������
	struct knot {
	private:

		int data = 0;
		std::unique_ptr<Queue::knot> next;
		int key = 0;

	public:

		std::unique_ptr<knot>& get_ptr();
		int get_key();
		knot(const int& data, const int& key, std::unique_ptr<knot>& next);
		~knot();
		//std::unique_ptr<knot> make_unique(knot new_knot);
		
	};

	//����
	std::unique_ptr<knot> head;
	bool isEmpty = true;

public:

	//������
	void push(const int& T);
	void pop();
	const int front() const;
	bool is_empty() const;

	//������������/�����������
	Queue();
	Queue(Queue& copy);
	~Queue() = default;

	//���������� ����������
	Queue& operator= (Queue&);
	friend struct knot;
};

#endif