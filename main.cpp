//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include <string>
#include <iostream>
#include "catch.hpp"
using Catch::Matchers::Equals;
//------------------------------

// Fix the following class
class Complex {
  int a,b;
public:
  Complex(int = 0, int = 0);
  int re();
  int im();
  void operator>>(std::string&) const;
  void operator<<(const std::string&);
 };

 Complex::Complex(int x, int y) : a{x}, b{y} {}
 int Complex::re() {return a;}
 int Complex::im() {return b;}
 void Complex::operator>>(std::string& out) const {
   out += std::to_string(a);
   if (b >= 0)
    out += '+'
   out.append(std::to_string(a));
   out += "i";
 }
 void Complex::operator<<(const std::string& in){
   int idx{1};
   std::string tmp{""};

   while( !(in[idx] == '+' || in[idx] == '-') )
     idx++;

  
    a = std::stoi(in, substr(0, idx));

    b = std::stoi(in, substr(idx, in.length() - idx - 1));

    
 }
//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------
TEST_CASE( "Assignment" ) {
    SECTION( "c1" ) {
        Complex c;
        REQUIRE( c.re() == 0 );
        REQUIRE( c.im() == 0 );
    }
    SECTION( "c2" ) {
        Complex c{1};
        REQUIRE( c.re() == 1 );
        REQUIRE( c.im() == 0 );
    }
    SECTION( "c3" ) {
        Complex c{1,1};
        REQUIRE( c.re() == 1 );
        REQUIRE( c.im() == 1 );
    }
    SECTION( "o1" ) {
        Complex c; std::string s{""};
        c >> s;
        REQUIRE_THAT( s, Equals("0+0i") );
    }
    SECTION( "o2" ) {
        Complex c{1, 2}; std::string s{""};
        c >> s;
        REQUIRE_THAT( s, Equals("1+2i") );
    }
    SECTION( "o3" ) {
        Complex c{2, -2}; std::string s{""};
        c >> s;
        REQUIRE_THAT( s, Equals("2-2i") );
    }
    SECTION( "o4" ) {
        Complex c{-2, 2}; std::string s{""};
        c >> s;
        REQUIRE_THAT( s, Equals("-2+2i") );
    }
    SECTION( "p1" ) {
        Complex c;
        c << "1+1i";
        REQUIRE( c.re() == 1 );
        REQUIRE( c.im() == 1 );
    }
    SECTION( "p2" ) {
        Complex c;
        c << "1-1i";
        REQUIRE( c.re() == 1 );
        REQUIRE( c.im() == -1 );
    }
    SECTION( "p3" ) {
        Complex c;
        c << "-1+0i";
        REQUIRE( c.re() == -1 );
        REQUIRE( c.im() == 0 );
    }
    SECTION( "p4" ) {
        Complex c;
        c << "-1-2i";
        REQUIRE( c.re() == -1 );
        REQUIRE( c.im() == -2 );
    }
}
//------------------------------
