// Copyright 2017 Arden Rasmussen

#include "gtest/gtest.h"
#include "variable.hpp"

TEST(VariableTest, Bool) {
  estl::Variable var(false);
  EXPECT_EQ(false, var.GetBool());
  EXPECT_EQ(estl::Variable::BOOL, var.Type());
  bool test = var;
  EXPECT_EQ(false, test);
}
TEST(VariableTest, Char) {
  char a = 'a';
  signed char b = 'b';
  unsigned char c = 'c';
  estl::Variable vara(a);
  EXPECT_EQ('a', vara.GetChar());
  EXPECT_EQ(estl::Variable::CHAR, vara.Type());
  char testa = vara;
  EXPECT_EQ('a', testa);
  estl::Variable varb(b);
  EXPECT_EQ('b', varb.GetSignedChar());
  EXPECT_EQ(estl::Variable::SIGNED_CHAR, varb.Type());
  signed char testb = varb;
  EXPECT_EQ('b', testb);
  estl::Variable varc(c);
  EXPECT_EQ('c', varc.GetUnsignedChar());
  EXPECT_EQ(estl::Variable::UNSIGNED_CHAR, varc.Type());
  unsigned char testc = varc;
  EXPECT_EQ('c', testc);
}
TEST(VariableTest, Integer) {
  signed short int a = 1;
  unsigned short int b = 2;
  signed int c = 3;
  unsigned int d = 4;
  signed long int e = 5;
  unsigned long int f = 6;
  signed long long int g = 7;
  unsigned long long int h = 8;
  estl::Variable vara(a);
  EXPECT_EQ(1, vara.GetSignedShortInt());
  EXPECT_EQ(estl::Variable::SIGNED_SHORT_INT, vara.Type());
  signed short int testa = vara;
  EXPECT_EQ(1, testa);
  estl::Variable varb(b);
  EXPECT_EQ(2, varb.GetUnsignedShortInt());
  EXPECT_EQ(estl::Variable::UNSIGNED_SHORT_INT, varb.Type());
  unsigned short int testb = varb;
  EXPECT_EQ(2, testb);
  estl::Variable varc(c);
  EXPECT_EQ(3, varc.GetSignedInt());
  EXPECT_EQ(estl::Variable::SIGNED_INT, varc.Type());
  signed int testc = varc;
  EXPECT_EQ(3, testc);
  estl::Variable vard(d);
  EXPECT_EQ(4, vard.GetUnsignedInt());
  EXPECT_EQ(estl::Variable::UNSIGNED_INT, vard.Type());
  unsigned int testd = vard;
  EXPECT_EQ(4, testd);
  estl::Variable vare(e);
  EXPECT_EQ(5, vare.GetSignedLongInt());
  EXPECT_EQ(estl::Variable::SIGNED_LONG_INT, vare.Type());
  signed long int teste = vare;
  EXPECT_EQ(5, teste);
  estl::Variable varf(f);
  EXPECT_EQ(6, varf.GetUnsignedLongInt());
  EXPECT_EQ(estl::Variable::UNSIGNED_LONG_INT, varf.Type());
  unsigned long int testf = varf;
  EXPECT_EQ(6, testf);
  estl::Variable varg(g);
  EXPECT_EQ(7, varg.GetSignedLongLongInt());
  EXPECT_EQ(estl::Variable::SIGNED_LONG_LONG_INT, varg.Type());
  signed long long int testg = varg;
  EXPECT_EQ(7, testg);
  estl::Variable varh(h);
  EXPECT_EQ(8, varh.GetUnsignedLongLongInt());
  EXPECT_EQ(estl::Variable::UNSIGNED_LONG_LONG_INT, varh.Type());
  unsigned long long int testh = varh;
  EXPECT_EQ(8, testh);
}
TEST(VariableTest, Float) {
  float a = 3.1415;
  double b = 2.7182;
  long double c = 1.4142;
  estl::Variable vara(a);
  EXPECT_EQ(float(3.1415), vara.GetFloat());
  EXPECT_EQ(estl::Variable::FLOAT, vara.Type());
  float testa = vara;
  EXPECT_EQ(float(3.1415), testa);
  estl::Variable varb(b);
  EXPECT_EQ(2.7182, varb.GetDouble());
  EXPECT_EQ(estl::Variable::DOUBLE, varb.Type());
  double testb = varb;
  EXPECT_EQ(2.7182, testb);
  estl::Variable varc(c);
  EXPECT_EQ(1.4142, varc.GetLongDouble());
  EXPECT_EQ(estl::Variable::LONG_DOUBLE, varc.Type());
  long double testc = varc;
  EXPECT_EQ(1.4142, testc);
}
TEST(VariableTest, String) {
  std::string a = "Hello World!";
  const char* b = "Good Bye World!";
  estl::Variable vara(a);
  EXPECT_EQ("Hello World!", vara.GetString());
  EXPECT_EQ(estl::Variable::STRING, vara.Type());
  std::string testa = vara;
  EXPECT_EQ("Hello World!", testa);
  estl::Variable varb(b);
  EXPECT_EQ("Good Bye World!", varb.GetCharArray());
  EXPECT_EQ(estl::Variable::CHAR_ARRAY, varb.Type());
  const char* testb = varb;
  EXPECT_EQ("Good Bye World!", testb);
}

TEST(VariableTest, BoolVector) {
  estl::Variable var({false, true});
  var.PushBack(true);
  EXPECT_EQ(std::vector<bool>({false, true, true}), var.GetBoolVector());
  EXPECT_EQ(estl::Variable::BOOL_VECTOR, var.Type());
  std::vector<bool> test = var;
  EXPECT_EQ(std::vector<bool>({false, true, true}), test);
}

TEST(VariableTest, CharVector) {
  char a = 'a', b = 'b';
  signed char c = 'c', d = 'd';
  unsigned char e = 'e', f = 'f';
  estl::Variable vara({a, b});
  vara.PushBack(b);
  EXPECT_EQ(std::vector<char>({'a', 'b', 'b'}), vara.GetCharVector());
  EXPECT_EQ(estl::Variable::CHAR_VECTOR, vara.Type());
  std::vector<char> testa = vara;
  EXPECT_EQ(std::vector<char>({'a', 'b', 'b'}), testa);
  estl::Variable varb({c, d});
  varb.PushBack(d);
  EXPECT_EQ(std::vector<signed char>({'c', 'd', 'd'}),
            varb.GetSignedCharVector());
  EXPECT_EQ(estl::Variable::SIGNED_CHAR_VECTOR, varb.Type());
  std::vector<signed char> testb = varb;
  EXPECT_EQ(std::vector<signed char>({'c', 'd', 'd'}), testb);
  estl::Variable varc({e, f});
  varc.PushBack(f);
  EXPECT_EQ(std::vector<unsigned char>({'e', 'f', 'f'}),
            varc.GetUnsignedCharVector());
  EXPECT_EQ(estl::Variable::UNSIGNED_CHAR_VECTOR, varc.Type());
  std::vector<unsigned char> testc = varc;
  EXPECT_EQ(std::vector<unsigned char>({'e', 'f', 'f'}), testc);
}

TEST(VariableTest, IntegerVector) {
  signed short int aa = 1, ab = 2;
  unsigned short int ba = 3, bb = 4;
  signed int ca = 5, cb = 6;
  unsigned int da = 7, db = 8;
  signed long int ea = 9, eb = 10;
  unsigned long int fa = 11, fb = 12;
  signed long long int ga = 13, gb = 14;
  unsigned long long int ha = 15, hb = 16;
  estl::Variable vara({aa, ab});
  vara.PushBack(ab);
  EXPECT_EQ(std::vector<signed short int>({1, 2, 2}),
            vara.GetSignedShortIntVector());
  std::vector<signed short int> testa = vara;
  EXPECT_EQ(std::vector<signed short int>({1, 2, 2}), testa);
  estl::Variable varb({ba, bb});
  varb.PushBack(bb);
  EXPECT_EQ(std::vector<unsigned short int>({3, 4, 4}),
            varb.GetUnsignedShortIntVector());
  std::vector<unsigned short int> testb = varb;
  EXPECT_EQ(std::vector<unsigned short int>({3, 4, 4}), testb);
  estl::Variable varc({ca, cb});
  varc.PushBack(cb);
  EXPECT_EQ(std::vector<signed int>({5, 6, 6}), varc.GetSignedIntVector());
  std::vector<signed int> testc = varc;
  EXPECT_EQ(std::vector<signed int>({5, 6, 6}), testc);
  estl::Variable vard({da, db});
  vard.PushBack(db);
  EXPECT_EQ(std::vector<unsigned int>({7, 8, 8}), vard.GetUnsignedIntVector());
  std::vector<unsigned int> testd = vard;
  EXPECT_EQ(std::vector<unsigned int>({7, 8, 8}), testd);
  estl::Variable vare({ea, eb});
  vare.PushBack(eb);
  EXPECT_EQ(std::vector<signed long int>({9, 10, 10}),
            vare.GetSignedLongIntVector());
  std::vector<signed long int> teste = vare;
  EXPECT_EQ(std::vector<signed long int>({9, 10, 10}), teste);
  estl::Variable varf({fa, fb});
  varf.PushBack(fb);
  EXPECT_EQ(std::vector<unsigned long int>({11, 12, 12}),
            varf.GetUnsignedLongIntVector());
  std::vector<unsigned long int> testf = varf;
  EXPECT_EQ(std::vector<unsigned long int>({11, 12, 12}), testf);
  estl::Variable varg({ga, gb});
  varg.PushBack(gb);
  EXPECT_EQ(std::vector<signed long long int>({13, 14, 14}),
            varg.GetSignedLongLongIntVector());
  std::vector<signed long long int> testg = varg;
  EXPECT_EQ(std::vector<signed long long int>({13, 14, 14}), testg);
  estl::Variable varh({ha, hb});
  varh.PushBack(hb);
  EXPECT_EQ(std::vector<unsigned long long int>({15, 16, 16}),
            varh.GetUnsignedLongLongIntVector());
  std::vector<unsigned long long int> testh = varh;
  EXPECT_EQ(std::vector<unsigned long long int>({15, 16, 16}), testh);
}

TEST(VariableTest, FloatVector) {
  float a = 1.1, b = 1.2;
  double c = 2.1, d = 2.2;
  long double e = 3.1, f = 3.2;
  estl::Variable vara({a, b});
  vara.PushBack(b);
  EXPECT_EQ(std::vector<float>({1.1, 1.2, 1.2}), vara.GetFloatVector());
  EXPECT_EQ(estl::Variable::FLOAT_VECTOR, vara.Type());
  std::vector<float> testa = vara;
  EXPECT_EQ(std::vector<float>({1.1, 1.2, 1.2}), testa);
  estl::Variable varb({c, d});
  varb.PushBack(d);
  EXPECT_EQ(std::vector<double>({2.1, 2.2, 2.2}), varb.GetDoubleVector());
  EXPECT_EQ(estl::Variable::DOUBLE_VECTOR, varb.Type());
  std::vector<double> testb = varb;
  EXPECT_EQ(std::vector<double>({2.1, 2.2, 2.2}), testb);
  estl::Variable varc({e, f});
  varc.PushBack(f);
  EXPECT_EQ(std::vector<long double>({3.1, 3.2, 3.2}),
            varc.GetLongDoubleVector());
  EXPECT_EQ(estl::Variable::LONG_DOUBLE_VECTOR, varc.Type());
  std::vector<long double> testc = varc;
  EXPECT_EQ(std::vector<long double>({3.1, 3.2, 3.2}), testc);
}
