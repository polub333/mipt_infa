#include "infix.h"
#include "catch.hpp"
#include <string>


Int EvalString(const std::string& s) {
  std::istringstream iss(s);
  return EvalInfixNotation(iss);
}

TEST_CASE ("InfNot 2+2") {
  REQUIRE(EvalString("2 + 2") == 4);
}

TEST_CASE ("InfNot subtraction operand order") {
  REQUIRE(EvalString("4 - 2") == 2);
  REQUIRE(EvalString("2 - 4") == -2);
}
TEST_CASE("Devision and multiplication") {
    REQUIRE(EvalString("2 * 6") == 12);
    REQUIRE(EvalString("6 * 2") == 12);
    REQUIRE(EvalString("6 / 2") == 3);
    REQUIRE(EvalString("6 / 3") == 2);
}

TEST_CASE("Operation order") {
    REQUIRE(EvalString("2 + 5 * 6") == 32);
    REQUIRE(EvalString("5 * 6 + 2") == 32);
    REQUIRE(EvalString("30 / 10 + 2") == 5);
    REQUIRE(EvalString("2 + 30 / 10") == 5);
    REQUIRE(EvalString("5 * 6 / 3 * 7") == 70);
    REQUIRE(EvalString("5 * 6 + 21 / 7") == 33);
}
