#include "calculator.hh"
#include "lexer.hh"

std::string add_strings(std::string lhs, std::string rhs)
{
    size_t l_size = lhs.size();
    size_t r_size = rhs.size();
    std::string max = l_size > r_size ? lhs : rhs;
    std::string min = l_size > r_size ? rhs : lhs;
    std::string res("");
    unsigned carry = 0;
    int i = max.size() - 1;
    for (int j = min.size() - 1; j >= 0; --i, --j)
    {
        char tmp = max[i] + min[j] - '0' + carry;
        if (tmp - '0' >= 10)
        {
            carry = 1;
            tmp -= 10;
        }
        else
            carry = 0;
        res.insert(0, std::string(1, tmp));
    }
    for (; i >= 0; --i)
    {
        char c = max[i] - '0' + carry;
        if (c >= 10)
            carry = 1;
        else
            carry = 0;
        res.insert(0, std::string(1, c + '0'));
    }
    if (carry)
        res.insert(0, std::string(1, '1'));
    return res;
}

std::ostream& operator<<(std::ostream& os, const Token& t);

Calculator::Calculator()
{
    values_ = std::vector<Token>();
    operators_ = std::vector<Token>();
}

Calculator::add_tkn(Token t)
{
    if (t.get_type() == NUMBER)
    {
        values_.push_back(t);
    }
    else if (t.get_type() == LPAR)
    {
        operators_.push_back(t);
    }
    else if (t.get_type() == RPAR)
    {
        while (operators_.back().type != LPAR)
            //pop -> compute -> pushback onto value
    }
}
