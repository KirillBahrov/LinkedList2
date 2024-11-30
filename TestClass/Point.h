#include <iostream>
namespace rut::miit::pentagon
{
	/**
	* @brief структура точка
	*/
	struct Point {
		/**
		*@brief абсцисса
		*/
		double x;

		/**
		*@brief ордината
		*/
		double y;

		/**
		* @brief конструктор класса
		* @param x - абсцисса
		* @param y - ордината
		*/
		Point(double x, double y);
		/**
		* @brief оператор вывода
		* @param out - выходящий поток
		* @return выходящий поток
		*/
		friend std::ostream& operator«(std::ostream& out, const Point& p);
		/**
		* @brief оператор ввода
		* @param in - входящий поток
		* @return входящий поток
		*/
		friend std::istream& operator»(std::istream& in, Point& p);
		/**
		* @brief оператор сравнения
		* @param p1 - точка
		* @param p2 - точка
		* @return return true - точки равны, return false - точки неравны
		*/
		bool operator==(const Point& p2) const;
		/**
		* @brief оператор неравенства
		* @param p1 - точка
		* @param p2 - точка
		* @return return true - точки неравны, return false - точки равны
		* @return return true - точки неравны, return false - точки равны
		*/
		bool operator!=(const Point& p2) const;
	};
}