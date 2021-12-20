#include <ctime>
#include "Deque.h"

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "ru");

	cout << "Вас приветствует программа по работе с двухсторонней очередью!" << endl << endl;
	cout << "Заполняем очередь случайными числами..." << endl;
	for (int i = 0; i < 30; i++)
	{
		cout << ".";
	}
	cout << endl;

	Deque<int>* deque = new Deque<int>();
	for (int i = 0; i < 5; i++)
	{
		deque->push_back(1 + rand() % 50);
	}

	cout << "Получили очередь" << endl;

	Deque<int>::iterator it = deque->begin();
	while (it != deque->end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	it = deque->begin();

	char command;
	do
	{
		cout << "Выберите следующее действие:" << endl;
		cout << "1 - Добавить элемент в конец" << endl;
		cout << "2 - Добавить элемент в начало" << endl;
		cout << "3 - Удалить последний элемент" << endl;
		cout << "4 - Удалить первый элемент" << endl;
		cout << "5 - Очистить очередь" << endl;
		cout << "6 - Обменять очереди местами (ещё одна очередь введётся автоматически)" << endl;
		cout << "0 - Выход" << endl;

		cin >> command;

		switch (command)
		{
		case '1': {
			cout << "Введите число" << endl;
			int n = 0;
			cin >> n;
			deque->push_back(n);
			it = deque->begin();
			cout << "Результат:" << endl;
			while (it != deque->end())
			{
				cout << *it << " ";
				it++;
			}
			cout << endl;
			it = deque->begin();
			break;
		}
		case '2': {
			cout << "Введите число" << endl;
			int n = 0;
			cin >> n;
			deque->push_front(n);
			it = deque->begin();
			cout << "Результат:" << endl;
			while (it != deque->end())
			{
				cout << *it << " ";
				it++;
			}
			cout << endl;
			it = deque->begin();
			break;
		}
		case '3': {
			deque->pop_back();
			it = deque->begin();
			cout << "Результат:" << endl;
			while (it != deque->end())
			{
				cout << *it << " ";
				it++;
			}
			cout << endl;
			it = deque->begin();
			break;
		}
		case '4': {
			deque->pop_front();
			it = deque->begin();
			cout << "Результат:" << endl;
			while (it != deque->end())
			{
				cout << *it << " ";
				it++;
			}
			cout << endl;
			it = deque->begin();
			break;
		}
		case '5': {
			deque->clear();
			it = deque->begin();
			break;
		}
		case '6': {
			cout << "Заполняем очередь случайными числами..." << endl;
			for (int i = 0; i < 30; i++)
			{
				cout << ".";
			}
			cout << endl;

			Deque<int>* deque2 = new Deque<int>();
			for (int i = 0; i < 5; i++)
			{
				deque2->push_back(1 + rand() % 50);
			}

			cout << "Получили очередь" << endl;

			Deque<int>::iterator it2 = deque2->begin();
			while (it2 != deque2->end())
			{
				cout << *it2 << " ";
				it2++;
			}
			cout << endl;
			it2 = deque2->begin();

			cout << "Вызываем метод swap()" << endl;
			deque2->swap(*deque);

			it = deque->begin();
			it2 = deque2->begin();
			cout << "Результат:" << endl;
			cout << "1-я очередь" << endl;
			while (it != deque->end())
			{
				cout << *it << " ";
				it++;
			}
			cout << endl;
			it = deque->begin();

			cout << "2-я очередь" << endl;
			while (it2 != deque2->end())
			{
				cout << *it2 << " ";
				it2++;
			}
			cout << endl;
			it2 = deque2->begin();

			delete deque2;
			break;
		}
		default:
			break;
		}
	} while (command != '0');

	delete deque;
}