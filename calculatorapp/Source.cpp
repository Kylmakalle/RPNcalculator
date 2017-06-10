#include <iostream>
#include <string>
using namespace std;

void calculating(char* OPZSTR, int len)
{
	string answer;
	float stack[100];
	// sp = индекс €чейки, куда будет push-итьс€ очередное число
	int sp = 0;      // (sp-1) = индекс €чейки, €вл€ющейс€ вершиной стека
	for (int j = 0; j <= len; j++) {
		char c = OPZSTR[j];
		if (c == 'x')
			break;
		else if (c == ' ' || c == '\n' || c == NULL)
			continue;

		else if (c == '+') {
			stack[sp - 2] = stack[sp - 2] + stack[sp - 1];
			sp--;
			continue;
		}
		else if (c == '-') {
			stack[sp - 2] = stack[sp - 2] - stack[sp - 1];
			sp--;
			continue;
		}
		else if (c == '*') {
			stack[sp - 2] = stack[sp - 1] * stack[sp - 2];
			sp--;
			continue;
		}
		else if (c == '/') {
			stack[sp - 2] = stack[sp - 2] / stack[sp - 1];
			sp--;
			continue;
		}

		else {
			for (int y = j; y < len; y++) { //просматриваем текущую строку начина€ j
				if (isdigit(OPZSTR[y]) || OPZSTR[y] == ',') {//если элемент строки число или зап€та€
					answer += OPZSTR[y]; //вносим элемент строки в выходную строку
				}
				else {
					j = y; //иначе заканчиваем просмотр строки
					break;
				}
			}
			stack[sp] = stof(answer); //в стэк ответов заносим нашу выходную строку переведЄнную в тип float
			sp++;
			answer.clear();// очищаем выходную строку
		}
	}

	cout << endl;
	cout << "Result= " << stack[sp - 1] << endl;
}

void main(void)
{

	setlocale(LC_ALL, "Russian");
	int i = 0, s = 0, e = 0;
	char vr[100], stek[100], exit[100];

	cin >> vr;
	for (i = 0; vr[i] != '\0'; i++)
		switch (vr[i])
		{
		case '+':
			while ((s != 0) && (stek[s - 1] != '('))
			{
				exit[e] = stek[s - 1]; //на выход 
				e++;
				s--;
			}
			stek[s] = '+'; //в стек 
			s++;
			break;

		case '-':
			while ((s != 0) && (stek[s - 1] != '('))
			{
				exit[e] = stek[s - 1];
				e++;
				s--;
			}
			stek[s] = '-';
			s++;
			break;
		case '*':

			while ((s != 0) && (stek[s - 1] != '(') && (stek[s - 1] != '+') && (stek[s - 1] != '-'))
			{
				exit[e] = stek[s - 1];
				e++;
				s--;
			}
			stek[s] = '*';
			s++;
			break;
		case '/':

			while ((s != 0) && (stek[s - 1] != '(') && (stek[s - 1] != '+') && (stek[s - 1] != '-'))
			{
				exit[e] = stek[s - 1];
				e++;
				s--;
			}
			stek[s] = '/';
			s++;

			break;
		case '(':
		{
			stek[s] = '(';
			s++;
			break; }
		case ')':

			while ((stek[s - 1] != '(') && (s != 0))
			{
				exit[e] = stek[s - 1];
				e++;
				s--;
			}
			stek[s - 1] = ' ';
			s--;
			break;


		default:

		{
			exit[e] = vr[i];
			e++;
			if ((vr[i + 1] == '+') ||
				(vr[i + 1] == '-') ||
				(vr[i + 1] == '*') ||
				(vr[i + 1] == '/') ||
				(vr[i + 1] == '(') ||
				(vr[i + 1] == ')'))
			{
				exit[e] = ' ';
				e++;
			}
		}
		}

	exit[e] = ' ';
	e++;

	while (s != 0)
	{
		exit[e] = stek[s - 1];
		e++;
		s--;
	}
	cout << "ќѕ«: ";
	exit[e] = 'x';
	for (i = 0; i < e; i++)
	{
		cout << exit[i];
	}
	calculating(exit, i); // считаем

}