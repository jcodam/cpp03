#include <iostream>
#include <fstream>
#include <sstream>
#include "point.hpp"

bool bsp( point const a, point const b, point const c, point const point);

bool	convert_file_to_string(std::fstream *file)
{
	int y = 0;
	int x = 0;
	int index = 0;
	std::string	buf;
	point points[4];

	// buffer << file->rdbuf();
	// file.
	while (std::getline(*file, buf))
	{
		std::cout << buf << std::endl;
		x = buf.find('.');
		if (x != -1)
		{
			points[3] = point(x, y);
			x = -1;
		}
		x = buf.find('*');
		while (x != -1 && index < 3)
		{
			points[index] = point(x, y);
			index++;
			x = buf.find('*', x + 1);

		}
		y++;
	}
	// points[0].printData();
	// points[1].printData();
	// points[2].printData();
	// points[3].printData();
	return (bsp(points[0], points[1], points[2],  points[3]));
}

// void	get_star_dot(std::string content)
// {
// 	(void)content;
// }

int main(int argc, char *argv[])
{
	std::fstream	rd_file;
	std::string		file_name;
	bool			in_out;
	if (argc != 2)
	{
		std::cout << "program need all arguments" << std::endl << "1.filename--2.string to be replaced--3.the replacement string" << std::endl;
		return 1;
	}
	file_name = argv[1];
	rd_file.open(file_name, std::ios::in);
	if (!rd_file.is_open())
	{
		std::cout << "program can't open file check if it exist" << std::endl;
		return 1;
	}
	in_out = convert_file_to_string(&rd_file);
	// std::cout << file_content << std::endl;
	rd_file.close();
	if (in_out)
		std::cout << "is inside" << std::endl;
	else
		std::cout << "is outside" << std::endl;
	return 0;
}