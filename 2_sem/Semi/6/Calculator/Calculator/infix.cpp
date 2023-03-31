#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "infix.h"

using Int = int64_t;

enum struct TokenType {
  TT_NUMBER,
  TT_OPERATION
};

enum struct Operation {
  OP_ADD,
  OP_SUB,
  OP_MUL,
  OP_DIV
};

struct Token {
  TokenType type;
  union {
    Int number;
    Operation operation;
  } value;
};

void SkipWhitespace(std::istream& istrm) {
  while (isspace(istrm.peek())) {
    istrm.get();
  }
}

TokenType GetNextTokenType(std::istream& istrm) {
  SkipWhitespace(istrm);

  switch(istrm.peek()) {
  case '+':
  case '-':
  case '*':
  case '/':
    return TokenType::TT_OPERATION;

  case '0': case '1': case '2': case '3':
  case '4': case '5': case '6': case '7':
  case '8': case '9':
    return TokenType::TT_NUMBER;

  default:
    throw std::logic_error("Bad token in stream, failed to detect type");
  }
}

Operation GetOperation(std::istream& istrm) {
  switch(istrm.get()) {
  case '+': return Operation::OP_ADD;
  case '-': return Operation::OP_SUB;
  case '*': return Operation::OP_MUL;
  case '/': return Operation::OP_DIV;
  default: throw std::logic_error("Bad operation in stream");
  }
}

Int GetNumber(std::istream& istrm) {
  Int value = 0;
  char c = istrm.peek();
  while(isdigit(c)) {
    c = istrm.get();
    value = value * 10 + (c - '0');
    c = istrm.peek();
  }

  return value;
}

std::string ReverseNumber(Int num)
{
    std::string res = "";
    while(num > 0){
        res += std::to_string(num%10);
        num /= 10;
    }
    return res;
}

Int EvalOperation(Operation op, Int l, Int r) {
  switch(op) {
  case Operation::OP_ADD: return l + r;
  case Operation::OP_SUB: return l - r;
  case Operation::OP_MUL: return l * r;
  case Operation::OP_DIV: return l / r;
  default: throw std::logic_error("Enum switch reached default, how come?");
  }
}

Int EvalRevPolishExpr(std::istream& istrm) {
  std::vector<Token> tokens;

  while (true) {
    Token next;
    bool need_stack_reduce = false;
    next.type = GetNextTokenType(istrm);

    switch(next.type) {
    case TokenType::TT_OPERATION:
      next.value.operation = GetOperation(istrm);
      tokens.push_back(next);
      break;

    case TokenType::TT_NUMBER:
      next.value.number = GetNumber(istrm);
      tokens.push_back(next);
      need_stack_reduce = true;
      break;
    default:
    throw std::logic_error("Default case triggered in enum switch, this should be impossible!");
    }

    if (!need_stack_reduce) continue;
    while  (
        (tokens[tokens.size() - 2].type == TokenType::TT_NUMBER) &&
        (tokens[tokens.size() - 1].type == TokenType::TT_NUMBER)) {
      Int l = tokens.back().value.number;
      tokens.pop_back();
      Int r = tokens.back().value.number;
      tokens.pop_back();
      if (tokens.back().type != TokenType::TT_OPERATION) {
    throw std::logic_error("Three non-ops in a row on stack, bad input?");
      }
      Operation op = tokens.back().value.operation;
      tokens.pop_back();

      l = EvalOperation(op, l, r);

      if (tokens.empty()) return l;

      next.type = TokenType::TT_NUMBER;
      next.value.number = l;
      tokens.push_back(next);
    }
  }
}

bool PriorityNotLess(Operation lhs, Operation rhs)
{
    if(lhs == Operation::OP_MUL || lhs == Operation::OP_DIV)
        return true;
    if(rhs == Operation::OP_ADD || rhs == Operation::OP_SUB)
        return true;
    return false;
}

std::string GetOperRepresentation(Operation oper)
{
    switch (oper){
    case Operation::OP_ADD: return "+";
    case Operation::OP_SUB: return "-";
    case Operation::OP_MUL: return "*";
    case Operation::OP_DIV: return "/";
    default: throw std::logic_error("Enum switch reached default, how come?");
    }
}

std::ostringstream EvalSortStationAlg(std::istream& istrm)
{
    std::ostringstream res;
    std::vector<Operation> opers;
    while(!istrm.eof()){
        Token next;
        next.type = GetNextTokenType(istrm);
        switch(next.type) {
        case TokenType::TT_NUMBER:
            res << ReverseNumber(GetNumber(istrm)) << " ";
            break;

        case TokenType::TT_OPERATION:
            {
            auto oper = GetOperation(istrm);
            while(!opers.empty() && PriorityNotLess(opers.back(), oper)){
                res << GetOperRepresentation(opers.back()) << " ";
                opers.pop_back();
            }
            opers.push_back(oper);
            break;
            }
        default:
            throw std::logic_error("TT enum switch reached default, how come?");
        }
    }
    while(!opers.empty()){
        res << GetOperRepresentation(opers.back()) << " ";
        opers.pop_back();
    }
    return res;
}

std::string ReverseString(std::string str)
{
    auto n = str.size();
    std::string res(" ", n);
    for(int i = n - 1; i >= 0; --i){
        res[n - i - 1] = str[i];
    }
    return res;
}

Int EvalInfixNotation(std::istream& istrm)
{
    std::string postfixExpr = EvalSortStationAlg(istrm).str();
    std::string prefixExpr = ReverseString(postfixExpr);
    std::istringstream prefixNotationISS(prefixExpr);
    return EvalRevPolishExpr(prefixNotationISS);
}
