#include <iostream>
#include <string>
#include <exception>

class MyExcept : public std::exception
{
	std::string s_error;
public:
	MyExcept() {}
	MyExcept(std::string s) : s_error(s) {}
	virtual std::string get_error() const
	{
		return s_error;
	}
};

class Figuries
{
public:
	int sides_count;
	std::string Figure_Name;

	Figuries()
	{
		sides_count = 0;
		Figure_Name = "Фигура";
	}
	Figuries(int sides_count_FC, std::string Figure_Name_FC) : sides_count(sides_count_FC), Figure_Name(Figure_Name_FC) {}

	int get_sides_count()
	{
		return sides_count;
	}
	std::string get_figura_name()
	{
		return Figure_Name;
	}

	virtual void print_sides_dim()
	{
		std::cout << "no sides" << std::endl;
	}

	virtual void print_engels_dim()
	{
		std::cout << "no engels" << std::endl;
	}

	virtual int Engels_Summ()
	{
		return 0;
	}

	virtual bool sides_compare()
	{
		return 0;
	}

	virtual bool engels_compare()
	{
		return 0;
	}
};

class Triangele : public Figuries, public MyExcept
{
public:
	// a,b,c - стороны/ A,B,C - углы
	int aT, bT, cT, AT, BT, CT;
	Triangele(int sides_count_T = 3, std::string Figura_Name_T = "Треугольник") : Figuries(sides_count_T, Figura_Name_T), aT(10), bT(20), cT(30), AT(50), BT(60), CT(70){}
			
	int get_CT()
	{
		return CT;
	}

	int get_AT()
	{
		return AT;
	}

	int Engels_Summ() override
	{
		return AT + BT + CT;
	}

	void print_sides_dim() override
	{
		std::cout << "стороны " << aT << ", " << bT << ", " << cT<< ", ";
	}

	void print_engels_dim() override
	{
		std::cout << "углы " << AT << ", " << BT << ", " << CT << ") создан " << std::endl;
	}

	~Triangele() 
	{}
};

class Right_Triangele : public Triangele
{
public:
	int CRT;
	Right_Triangele(int sides_count_RT = 3, std::string Figura_Name_RT = "Прямоугольный треугольник") : Triangele(sides_count_RT, Figura_Name_RT), CRT(90) {}

	void print_sides_dim() override
	{
		std::cout << "стороны " << aT << ", " << bT << ", " << cT << ", ";
	}

	void print_engels_dim() override
	{
		std::cout << "углы " << AT << ", " << BT << ", " << CRT << ") создан " << std::endl;
	}

	~Right_Triangele()
	{}
};

class Isosceles_Triangele : public Triangele
{
public:
	int aIT, cIT, AIT, CIT;
	Isosceles_Triangele(int sides_count_IT = 3, std::string Figura_Name_IT = "Равнобедренный треугольник") : Triangele(sides_count_IT, Figura_Name_IT), aIT(10), cIT(10), AIT(45), CIT(45) {}

	void print_sides_dim() override
	{
		std::cout << "стороны " << aIT << ", " << bT << ", " << cIT << "; ";
	}

	void print_engels_dim() override
	{
		std::cout << "углы " << AIT << ", " << BT << ", " << CIT << ") создан " << std::endl;
	}

	~Isosceles_Triangele()
	{}

};

class Equilateral_Triangele : public Triangele
{
public:
	int aET, bET, cET, AET, BET, CET;
	Equilateral_Triangele(int sides_count_ET = 3, std::string Figura_Name_ET = "Равносторонний треугольник") : Triangele(sides_count_ET, Figura_Name_ET), aET(10), AET(60), bET(10), BET(60), cET(20), CET(70) {}

	void print_sides_dim() override
	{
		std::cout << "стороны " << aET << ", " << bET << ", " << cET << "; ";
	}

	void print_engels_dim() override
	{
		std::cout << "углы "  << AET << ", " << BET <<", " << CET << ") создан " << std::endl;
	}

	~Equilateral_Triangele()
	{}
};

class Quadrangle : public Figuries, public MyExcept
{
public:
	int aQ, bQ, cQ, dQ, AQ, BQ, CQ, DQ;
	Quadrangle(int sides_count_Q = 4, std::string Figura_Name_Q = "Четырёхугольник") : Figuries(sides_count_Q, Figura_Name_Q), aQ(10), bQ(20), cQ(30), dQ(40), AQ(50), BQ(60), CQ(70), DQ(380) {}

	void print_sides_dim() override
	{
		std::cout << "стороны "  << aQ << ", " << bQ << ", " << cQ << ", " << dQ << "; ";
	}

	void print_engels_dim() override
	{
		std::cout << "углы "  << AQ << ", " << BQ << ", " << CQ << ", " << DQ << ") создан " << std::endl;
	}

	int Engels_Summ() override
	{
		return AQ + BQ + CQ + DQ;
	}

	~Quadrangle()
	{}
};

class Rectangle : public Quadrangle
{
public:
	int aR, bR, cR, dR, AR, BR, CR, DR;
	Rectangle(int sides_count_R = 4, std::string Figura_Name_R = "Прямоугольник") : Quadrangle(sides_count_R, Figura_Name_R), aR(10), bR(20), AR(90) {
		cR = aR;
		dR = bR;
		BR = CR = DR = AR;
	}

	void print_sides_dim() override
	{
		std::cout << "стороны "  << aR << ", " << bR << ", " << cR << ", " << dR << "; ";
	}

	void print_engels_dim() override
	{
		std::cout << "углы "  << AR << ", " << BR << ", " << CR << ", " << DR << ") создан " << std::endl;
	}

	int Engels_Summ() override
	{
		return AR + BR + CR + DR;
	}

	~Rectangle()
	{}
};

class Square : public Quadrangle
{
public:
	int aS, bS, cS, dS, AS, BS, CS, DS;
	Square(int sides_count_S = 4, std::string Figura_Name_S = "Квадрат") : Quadrangle(sides_count_S, Figura_Name_S), aS(20), AS(90) {
		dS = bS = cS = aS;
		BS = CS = DS = AS;
	}

	void print_sides_dim() override
	{
		std::cout << "стороны "  << aS << ", " << bS << ", " << cS << ", " << dS << "; ";
	}

	void print_engels_dim() override
	{
		std::cout << "углы "  << AS << ", " << BS << ", " << CS << ", " << DS << ") создан " << std::endl;
	}

	int Engels_Summ() override
	{
		return AS + BS + CS + DS;
	}

	~Square()
	{}
};

class Parallelogram : public Quadrangle
{
public:
	int aP, bP, cP, dP, AP, BP, CP, DP;
	Parallelogram(int sides_count_P = 4, std::string Figura_Name_P = "Параллелограмм") : Quadrangle(sides_count_P, Figura_Name_P), aP(20), bP(30), AP(30), BP(40), cP(20), dP(30), CP(30), DP(40) {	}

	void print_sides_dim() override
	{
		std::cout << "стороны "  << aP << ", " << bP << ", " << cP << ", " << dP << "; ";
	}

	void print_engels_dim() override
	{
		std::cout << "углы "  << AP << ", " << BP << ", " << CP << ", " << DP << ") создан " << std::endl;
	}

	int Engels_Summ() override
	{
		return AP + BP + CP + DP;
	}

	bool sides_compare() override
	{
		if (aP == cP && bP == dP)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	bool engels_compare() override
	{
		if (AP == CP && BP == DP)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}


	~Parallelogram()
	{}
};

class Rhombus : public Quadrangle
{
public:
	int aRS, bRS, cRS, dRS, ARS, BRS, CRS, DRS;
	Rhombus(int sides_count_RS = 4, std::string Figura_Name_RS = "Ромб") : Quadrangle(sides_count_RS, Figura_Name_RS), aRS(20), ARS(30), BRS(40) {
		dRS = bRS = cRS = aRS;
		CRS = ARS;
		DRS = BRS;
	}

	void print_sides_dim() override
	{
		std::cout << "стороны " << aRS << ", " << bRS << ", " << cRS << ", " << dRS << "; ";
	}

	void print_engels_dim() override
	{
		std::cout << "углы "  << ARS << ", " << BRS << ", " << CRS <<", " << DRS << ") создан " << std::endl;
	}

	int Engels_Summ() override
	{
		return ARS + BRS + CRS + DRS;
	}

	~Rhombus()
	{}
};

void print_info(Figuries* input_figures)
{
	std::cout << input_figures->get_figura_name() << " (";
	input_figures->print_sides_dim();
	input_figures->print_engels_dim();
	std::cout << std::endl;
	}

int main()
{
	setlocale(LC_ALL, "Russian"); // задать русский текст
	std::system("chcp 1251"); // настроить кодировку консоли
	std::system("cls"); // очистить экран

	Figuries* Custom_Figure[9];
	std::string Custom_Error[9], Custom_Name[9];
	int j = 0;

// Создание фигуры Треугольник. Элемент массива 0
	try
	{
		Triangele test;
		Custom_Name[j] = test.Figure_Name;
		if (test.get_sides_count() != 3)
		{
			throw MyExcept("Ошибка создания фигуры. Причина: количество сторон не равно 3");
		}

		if (test.Engels_Summ() != 180 )
		{
			throw MyExcept("Ошибка создания фигуры. Причина: сумма углов не равна 180");
		}
		Custom_Figure[j] = new Triangele{};
	}
		catch (const MyExcept& RetErr)
	{
		Custom_Error[j]= RetErr.get_error();
		Custom_Figure[j] = new Figuries{};
	}
j = j + 1;

// Создание фигуры Прямоугольный треугольник. Элемент массива 1
		try
		{
			Right_Triangele test;
			Custom_Name[j] = test.Figure_Name;
			if (test.get_sides_count() != 3)
			{
				throw MyExcept("Ошибка создания фигуры. Причина: количество сторон не равно 3");
			}

			if (test.CRT != 90)
			{
				throw MyExcept("Ошибка создания фигуры. Причина: угол С не равен 90");
			}

			if (test.Engels_Summ() != 180)
			{
				throw MyExcept("Ошибка создания фигуры. Причина: сумма углов не равна 180");
			}
			
			Custom_Figure[j] = new Right_Triangele{};
		}
		catch (const MyExcept& RetErr)
		{
			Custom_Error[j] = RetErr.get_error();
			Custom_Figure[j] = new Figuries{};
		}
j = j + 1;

// Создание фигуры Равнобедренный треугольник. Элемент массива 2
try
{
	Isosceles_Triangele test;
	Custom_Name[j] = test.Figure_Name;
	if (test.get_sides_count() != 3)
	{
		throw MyExcept("Ошибка создания фигуры. Причина: количество сторон не равно 3");
	}

	if (test.CIT != test.AIT)
	{
		throw MyExcept("Ошибка создания фигуры. Причина: углы А и С не равны");
	}

	if (test.cIT != test.aIT)
	{
		throw MyExcept("Ошибка создания фигуры. Причина: Стороны a и c не равны");
	}

	if (test.Engels_Summ() != 180)
	{
		throw MyExcept("Ошибка создания фигуры. Причина: сумма углов не равна 180");
	}

	Custom_Figure[j] = new Isosceles_Triangele{};
}
catch (const MyExcept& RetErr)
{
	Custom_Error[j] = RetErr.get_error();
	Custom_Figure[j] = new Figuries{};
}
j = j + 1;

// Создание фигуры Равносторонний треугольник. Элемент массива 3
try
{
	Equilateral_Triangele test;
	Custom_Name[j] = test.Figure_Name;
	if (test.get_sides_count() != 3)
	{
		throw MyExcept("Ошибка создания фигуры. Причина: количество сторон не равно 3");
	}

	if (test.CET != test.AET != test.BET)
	{
		throw MyExcept("Ошибка создания фигуры. Причина: углы А B С не равны");
	}

	if (test.cET != test.aET != test.bET)
	{
		throw MyExcept("Ошибка создания фигуры. Причина: Стороны a b c не равны");
	}

	if (test.Engels_Summ() != 180)
	{
		throw MyExcept("Ошибка создания фигуры. Причина: сумма углов не равна 180");
	}

	Custom_Figure[j] = new Equilateral_Triangele{};
}
catch (const MyExcept& RetErr)
{
	Custom_Error[j] = RetErr.get_error();
	Custom_Figure[j] = new Figuries{};
}
j = j + 1;

// Создание фигуры Четырёхугольник. Элемент массива 4
try
{
	Quadrangle test;
	Custom_Name[j] = test.Figure_Name;
	if (test.get_sides_count() != 4)
	{
		throw MyExcept("Ошибка создания фигуры. Причина: количество сторон не равно 4");
	}

		if (test.Engels_Summ() != 360)
	{
		throw MyExcept("Ошибка создания фигуры. Причина: сумма углов не равна 360");
	}

	Custom_Figure[j] = new Quadrangle{};
}
catch (const MyExcept& RetErr)
{
	Custom_Error[j] = RetErr.get_error();
	Custom_Figure[j] = new Figuries{};
}
j = j + 1;

// Создание фигуры Четырёхугольник. Элемент массива 5
try
{
	Rectangle test;
	Custom_Name[j] = test.Figure_Name;
	if (test.get_sides_count() != 4)
	{
		throw MyExcept("Ошибка создания фигуры. Причина: количество сторон не равно 4");
	}

	if (test.AR != test.BR != test.CR != test.DR)
	{
		throw MyExcept("Ошибка создания фигуры. Причина: углы не равны 90 градусам");
	}

	if (test.cR != test.aR && test.bR != test.dR)
	{
		throw MyExcept("Ошибка создания фигуры. Причина: Стороны попарно  не равны");
	}

	if (test.Engels_Summ() != 360)
	{
		throw MyExcept("Ошибка создания фигуры. Причина: сумма углов не равна 360");
	}

	Custom_Figure[j] = new Rectangle{};
}
catch (const MyExcept& RetErr)
{
	Custom_Error[j] = RetErr.get_error();
	Custom_Figure[j] = new Figuries{};
}
j = j + 1;

// Создание фигуры Квадрат. Элемент массива 6
try
{
	Square test;
	Custom_Name[j] = test.Figure_Name;
	if (test.get_sides_count() != 4)
	{
		throw MyExcept("Ошибка создания фигуры. Причина: количество сторон не равно 4");
	}

	if (test.AS != test.BS != test.CS != test.DS)
	{
		throw MyExcept("Ошибка создания фигуры. Причина: углы не равны 90 градусам");
	}

	if (test.cS != test.aS != test.bS != test.dS)
	{
		throw MyExcept("Ошибка создания фигуры. Причина: Стороны не равны");
	}

	if (test.Engels_Summ() != 360)
	{
		throw MyExcept("Ошибка создания фигуры. Причина: сумма углов не равна 360");
	}

	Custom_Figure[j] = new Square{};
}
catch (const MyExcept& RetErr)
{
	Custom_Error[j] = RetErr.get_error();
	Custom_Figure[j] = new Figuries{};
}
j = j + 1;

// Создание фигуры Параллелограмм. Элемент массива 7
try
{
	Custom_Figure[j] = new Parallelogram{};
	Custom_Name[j] = Custom_Figure[j]->get_figura_name();
	if (Custom_Figure[j]->get_sides_count() != 4)
	{
		throw MyExcept("Ошибка создания фигуры. Причина: количество сторон не равно 4");
	}

	if (Custom_Figure[j]->engels_compare() !=1)
	{
		throw MyExcept("Ошибка создания фигуры. Причина: углы не равны 90 градусам");
	}

	if (Custom_Figure[j]->sides_compare() != 1)
	{
		throw MyExcept("Ошибка создания фигуры. Причина: Стороны попарно  не равны");
	}

	if (Custom_Figure[j]->Engels_Summ() != 360)
	{
		throw MyExcept("Ошибка создания фигуры. Причина: сумма углов не равна 360");
	}

	
}
catch (const MyExcept& RetErr)
{
	Custom_Error[j] = RetErr.get_error();
	Custom_Figure[j] = new Figuries{};
}
j = j + 1;

// Создание фигуры Квадрат. Элемент массива 8
try
{
	Rhombus test;
	Custom_Name[j] = test.Figure_Name;
	if (test.get_sides_count() != 4)
	{
		throw MyExcept("Ошибка создания фигуры. Причина: количество сторон не равно 4");
	}

	if (test.ARS != test.CRS && test.DRS != test.DRS)
	{
		throw MyExcept("Ошибка создания фигуры. Причина: углы не равны попарно");
	}

	if (test.cRS != test.aRS != test.bRS != test.dRS)
	{
		throw MyExcept("Ошибка создания фигуры. Причина: Стороны не равны");
	}

	if (test.Engels_Summ() != 360)
	{
		throw MyExcept("Ошибка создания фигуры. Причина: сумма углов не равна 360");
	}

	Custom_Figure[j] = new Rhombus{};
}
catch (const MyExcept& RetErr)
{
	Custom_Error[j] = RetErr.get_error();
	Custom_Figure[j] = new Figuries{};
}

	for (int i = 0; i < 9; i++)
	{
		if (Custom_Figure[i]->sides_count != 0)
		{
			print_info(Custom_Figure[i]);
		}
		else
		{
			std::cout << Custom_Name[i]<< ": " << Custom_Error[i] << std::endl;
			std::cout << std::endl;
		}
	}

	for (int i = 0; i < 9; i++)
	{
		delete Custom_Figure[i];
		
	}
	return 52;
}