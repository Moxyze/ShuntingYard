#include "shunting_yard.hh"

void print(std::vector<std::string> line)
{
    unsigned sz = line.size();
    for (unsigned i = 0; i < sz; ++i)
    {
        std::cout << line[i];
    }
}

std::vector<std::string> *parser(std::string)
{
    std::vector<std::string> *line = new std::vector<std::string>;
    return line;
}


int shunting_yard(std::vector<std::string> str)
{
    if (str.empty())
    {
        return 0;
    }
    return -1; // FIXME
}