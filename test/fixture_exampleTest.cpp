#include <gtest/gtest.h>

class C{};

class B{
    C* ptr;
    //DIP
    public:
    B(C* addressOfObject): ptr(addressOfObject){}
};

class A{
    B* ptr;
    //DIP
    public:
    A(B* addressOfObject): ptr(addressOfObject){}

    bool operation(){
        return true;
    }
};


TEST(FixtureTestSuite, OperationTest) {
  //Arrange
  C cObj;
  B bObj(&cObj)
  A obj(&bObj);

  //Act and Assert
  ASSERT_TRUE(obj.operation());
}

TEST(FixtureTestSuite, OperationTest) {
  //Arrange
  C cObj;
  B bObj(&cObj)
  A obj(&bObj);

  //Act and Assert
  ASSERT_FALSE(obj.operation());
}

