#pragma once

#ifndef ARRAYINT_H
#define ARRAYINT_H

#include <cassert> // ��� assert()
#include <iostream>
class ArrayInt
{
private:
	int m_length;
	int* m_data;

public:
	ArrayInt() : m_length(0), m_data(nullptr)
	{ }

	ArrayInt(int length) :
		m_length(length)
	{
		assert(length >= 0);

		if (length > 0)
			m_data = new int[length];
		else
			m_data = nullptr;
	}
	void erase()
	{
		delete[] m_data;

		// ����� ��� ����� ������� m_data �������� nullptr, ����� �� ������ �� ���� �������� ���������
		m_data = nullptr;
		m_length = 0;
	}

	int getLength() { return m_length; }

	int& operator[](int index)
	{
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}

	void resize(int newLength)
	{
		// ���� ������ ��� ������ ����� � return
		if (newLength == m_length)
			return;

		// ���� ����� ������� ������ ������ � ������ ��� � ����� return
		if (newLength <= 0)
		{
			erase();
			return;
		}

		// ������ �����, ��� newLength >0
		// �������� ����� ������
		int* data = new int[newLength];

		// ����� ����� ����������� � ����������� ���������� ��������� � ����� ������
		// ����� ����������� ������� ���������, ������� �� ���� � ������� �� ��������
		if (m_length > 0)
		{
			int elementsToCopy = (newLength > m_length) ? m_length : newLength;

			// ���������� �������� ��������
			for (int index = 0; index < elementsToCopy; ++index)
				data[index] = m_data[index];
		}

		// ������� ������ ������, ��� ��� �� ��� ��� �� �����
		delete[] m_data;

		// � ���������� ������ ������� ������� �����! �������� ��������, m_data ���������
		// �� ��� �� �����, �� ������� ��������� ��� ����� ����������� ���������� ������. ���������
		// ������ ���� ����������� ���������� � ��� �� ����� ����������, ����� ������ �� ������� ���������
		m_data = data;
		m_length = newLength;
	}

	void insertBefore(int value, int index)
	{
		// �������� ������������ ������������� �������
		assert(index >= 0 && index <= m_length);

		// ������� ����� ������ �� ���� ������� ������ ������� �������
		int* data = new int[m_length + 1];

		// �������� ��� �������� �� index-�
		for (int before = 0; before < index; ++before)
			data[before] = m_data[before];

		// ��������� ����� ������� � ����� ������
		data[index] = value;

		// �������� ��� �������� ����� ������������ ��������
		for (int after = index; after < m_length; ++after)
			data[after + 1] = m_data[after];

		// ������� ������ ������ � ���������� ������ ���� ����� 
		delete[] m_data;
		m_data = data;
		++m_length;
	}

	int popBack() {
		if (m_length <= 0)
		{
			// ����� ����� ������� ��������� � ���, ��� ������ ����
			// cout << "Array empty"\n;
			return -1;
		}
		// ���� ������ �� ������
		int popValue = m_data[m_length - 1];
		int* data = new int[m_length - 1];
		for (int before = 0; before < m_length - 1; ++before)
			data[before] = m_data[before];

		delete[] m_data;
		m_data = data;
		m_length = m_length - 1;
		return popValue;
	}

	int popFront() {
		if (m_length <= 0)
		{
			// ����� ����� ������� ��������� � ���, ��� ������ ����
			// cout << "Array empty"\n;
			return -1;
		}
		// ���� ������ �� ������
		int popValue = m_data[0];
		int* data = new int[m_length - 1];
		for (int before = 0; before < m_length; ++before)
			data[before] = m_data[before + 1];

		delete[] m_data;
		m_data = data;
		m_length = m_length - 1;
		return popValue;
	}

	void push_back(int value) { insertBefore(value, m_length); }

	void sort() {
		if (m_length <= 0)
		{
			// ����� ����� ������� ��������� � ���, ��� ������ ����
			// cout << "Array empty"\n;
			return;
		}
		for (int i = 0; i < m_length; i++) {
			for (int j = 0; j < m_length - 1; j++) {
				if (this->m_data[j] > this->m_data[j + 1]) {
					int c = m_data[j];
					m_data[j] = m_data[j + 1];
					m_data[j + 1] = c;
				}
			}
		}
	}

	void print() {
		if (m_length <= 0)
		{
			std::cout << "Array empty\n";
			return;
		}
		std::cout << "Lenght: " << getLength() << "\n";
		for (size_t i = 0; i < getLength(); i++)
		{
			std::cout << "Idx" << i+1 << ": " << m_data[i] << "\n";
		}
	}
	~ArrayInt()
	{
		delete[] m_data;
	}
};



#endif
