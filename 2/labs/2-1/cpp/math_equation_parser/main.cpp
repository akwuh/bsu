// ����� ������
// 13.02.2015
// ������ �������������� ��������� � ������������� ����������� ������

#include <iostream>
#include "parser.h"
#include <clocale>

#define BUFFER_LENGTH 1024

int main() {
 
  setlocale(LC_ALL, "RU");
  setlocale(LC_NUMERIC,"C");
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  
  std::cout << "\n��� ������������ ������ 1.0!";
  std::cout << "\n�������� \"exit\" ��� ������";
  std::cout << "\n�� ������ ������������:";
  std::cout << "\n\t����� � ������� \"1\", \"3.14\" ��� \"3,14\", � ����� ���� ����� \"-+/*^\"";
  std::cout << "\n\t���������� � ������� \"a\", \"var\" ��� ���� \"BSU\"";
  std::cout << "\n\t������ ���� �����: \"([])\"";
  std::cout << "\n\t������� ���� f(x) ����� ��� sin, cos, tan, asin, acos, atan, "
               "log, ln, log10, sqrt (����� ���������� �����...)";
  printf("\n\n������� ���������:\t");

  char buffer[BUFFER_LENGTH];
  while (gets(buffer) != NULL && strstr(buffer, "exit") == NULL) {
    if (strlen(buffer) == 0 || strstr(buffer, "//") != NULL) continue;
    try {
      Parser* parser = new Parser;
      parser->parse(buffer);
      printf("\n\nYour equation:   %s\nPostfix notation:   %s\nResult:   %G",
             parser->getEquation().c_str(), parser->getPolishNotation().c_str(),
             static_cast<float>(parser->calculate()));
    } catch (utils::BaseException& e) {
      printf("\nERROR:\t%s\n", e.getDescription().c_str());
    } catch (std::exception& e) {
      std::cerr << "exception caught: " << e.what() << '\n';
    }
    printf("\n\n������� ���������:\t");
  }
  return 0;
}