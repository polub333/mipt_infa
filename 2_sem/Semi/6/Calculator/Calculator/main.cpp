

int main() {
  std::string s = "2 + 2 * 50 + 6 - 2";

  std::istringstream iss(s);
  std::string postfixNotation = EvalSortStationAlg(iss).str();
  std::reverse(postfixNotation.begin(), postfixNotation.end());
  std::istringstream prefixNotationISS(postfixNotation);
  std::cout << EvalRevPolishExpr(prefixNotationISS) << std::endl;;
  return 0;
}
