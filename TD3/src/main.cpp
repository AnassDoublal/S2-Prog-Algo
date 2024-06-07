#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <iostream>
#include <cctype>
#include <stack>
#include <math.h>

bool is_floating(std::string const& s);

enum class Operator { ADD, SUB, MUL, DIV, POW, OPEN_PAREN, CLOSE_PAREN};
enum class TokenType { OPERATOR, OPERAND };
struct Token {
  TokenType type;
  float value;
  Operator op;
};

Token make_token(float value);
Token make_token(Operator op);

Token make_token(float value)
{
    Token token;
    token.type = TokenType::OPERAND;
    token.value = value;

    return token;
}

Token make_token(Operator op)
{
    Token token;
    token.type = TokenType::OPERATOR;
    token.op = op;

    return token;
}

std::vector<Token> tokenize(std::vector<std::string> const& words);

std::vector<Token> tokenize(std::vector<std::string> const& words)
{
    std::vector<Token> tokens;

    for (int i = 0; i < words.size(); i++)
    {
        if(is_floating(words[i]))
            tokens.push_back(make_token(stof(words[i])));
        else
            if(words[i] == "+")
                tokens.push_back(make_token(Operator::ADD));
            else if(words[i] == "-")
                tokens.push_back(make_token(Operator::SUB));
            else if(words[i] == "*")
                tokens.push_back(make_token(Operator::MUL));
            else if(words[i] == "/")
                tokens.push_back(make_token(Operator::DIV));
            else if (words[i] == "^") {
                tokens.push_back(make_token(Operator::POW));
            } else if (words[i] == "(") {
                tokens.push_back(make_token(Operator::OPEN_PAREN));
            } else if (words[i] == ")") {
                tokens.push_back(make_token(Operator::CLOSE_PAREN));
            }
    }

    return tokens;
}

float npi_evaluate(std::vector<Token> const& tokens);

float npi_evaluate(std::vector<Token> const& tokens)
{
    std::stack<float> stack;

    for (int i = 0; i < tokens.size(); i++)
    {
        if(tokens[i].type == TokenType::OPERAND)
            stack.push(tokens[i].value);
        else
        {
            // Je récupère l'élément en haut de la pile
            float rightOperand { stack.top() };
            // Je l'enlève de la stack (la méthode top ne fait que lire l’élément en dessus de la pile)
            stack.pop();
            float leftOperand { stack.top() };
            stack.pop();

            // Il faut ensuite en fonction de l'opérateur calculer le résultat pour le remettre dans la pile
            float result { };

            switch (tokens[i].op)
            {
            case Operator::ADD:
                result = leftOperand + rightOperand;
                break;
            case Operator::SUB:
                result = leftOperand - rightOperand;
                break;
            case Operator::MUL:
                result = leftOperand * rightOperand;
                break;
            case Operator::DIV:
                result = leftOperand / rightOperand;
                break;
            case Operator::POW:
                    result = std::pow(leftOperand, rightOperand);
                    break;
            default:
                break;
            }

            stack.push(result);
        }
    }

    return stack.top();
}

std::vector<std::string> split_string(std::string const& s)
{
    std::istringstream in(s); // transforme une chaîne en flux de caractères, cela simule un flux comme l'est std::cin
    // l’itérateur va lire chaque element de "in", comme un flux d'entrée, chaque élément est séparé par un espace
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>()); 
}

bool is_floating(std::string const& s)
{
    if(!std::isdigit(s[0]) && s != ".")
        return false;
    else
        return true;
}

float npi_evaluate(std::vector<std::string> const& tokens);

float npi_evaluate(std::vector<std::string> const& tokens)
{
    std::stack<float> stack;

    for (int i = 0; i < tokens.size(); i++)
    {
        if(is_floating(tokens[i]))
            stack.push(std::stof(tokens[i]));
        else
        {
            // Je récupère l'élément en haut de la pile
            float rightOperand { stack.top() };
            // Je l'enlève de la stack (la méthode top ne fait que lire l’élément en dessus de la pile)
            stack.pop();
            float leftOperand { stack.top() };
            stack.pop();

            // Il faut ensuite en fonction de l'opérateur calculer le résultat pour le remettre dans la pile
            float result { };

            if(tokens[i] == "+")
                result = leftOperand + rightOperand;
            else if(tokens[i] == "-")
                result = leftOperand - rightOperand;
            else if(tokens[i] == "*")
                result = leftOperand * rightOperand;
            else if(tokens[i] == "/")
                result = leftOperand / rightOperand;

            stack.push(result);
        }
    }

    return stack.top();
}

size_t operator_precedence(Operator const op) {
    switch (op) {
        case Operator::ADD:
        case Operator::SUB:
            return 1;
        case Operator::MUL:
        case Operator::DIV:
            return 2;
        case Operator::POW:
            return 3;
        case Operator::OPEN_PAREN:
        case Operator::CLOSE_PAREN:
            return 0;
        default:
            return 0;
    }
}

std::vector<Token> infix_to_npi_tokens(std::string const& expression) {
    std::vector<std::string> infix_tokens = split_string(expression);
    std::vector<Token> tokens = tokenize(infix_tokens);
    std::vector<Token> output;
    std::stack<Token> operators;

    for (const auto& token : tokens) {
        if (token.type == TokenType::OPERAND) {
            output.push_back(token);
        } else if (token.op == Operator::OPEN_PAREN) {
            operators.push(token);
        } else if (token.op == Operator::CLOSE_PAREN) {
            while (!operators.empty() && operators.top().op != Operator::OPEN_PAREN) {
                output.push_back(operators.top());
                operators.pop();
            }
            if (!operators.empty() && operators.top().op == Operator::OPEN_PAREN) {
                operators.pop();
            }
        } else {
            while (!operators.empty() &&
                   operator_precedence(operators.top().op) >= operator_precedence(token.op)) {
                output.push_back(operators.top());
                operators.pop();
            }
            operators.push(token);
        }
    }

     while (!operators.empty()) {
        output.push_back(operators.top());
        operators.pop();
    }

    return output;
}

int main()
{
    std::string NPI_val;

    std::cout << "Entrer operation en NPI (inclure des espaces) : ";
    std::getline(std::cin, NPI_val);

    std::cout << NPI_val;

    std::vector<std::string> tokens = split_string(NPI_val);
    std::vector<Token> tokenized = tokenize(tokens);

    float res = npi_evaluate(tokenized);

    std::cout << "\n" << res << "\n";

    // Ex 3

    std::string infix_expression;

    std::cout << "Entrer une expression en notation infixe (inclure des espaces) : ";
    std::getline(std::cin, infix_expression);

    std::vector<Token> npi_tokens = infix_to_npi_tokens(infix_expression);

    float result = npi_evaluate(npi_tokens);

    std::cout << result << "\n";
}