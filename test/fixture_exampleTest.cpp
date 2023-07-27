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

class FixtureTestSuite: public testing::Test{
protected:
    A* aPtr;
    B* bPtr;
    C* cPtr;
    FixtureTestSuite(){
        //initialization
    }
    ~FixtureTestSuite(){
        //Release the Resources
    }
    // You can define per-test set-up logic as usual.
    void SetUp() override {
        //Arrange
        this->cPtr = new C();
        this->bPtr = new B(cPtr);
        this->aPtr = new A(bPtr);
    }

    // You can define per-test tear-down logic as usual.
    void TearDown() override {
        //delete resources
        delete cPtr;
        delete bPtr;
        delete aPtr;
    }
};


TEST_F(FixtureTestSuite, Operation_Test_True) {
  //Act and Assert
  ASSERT_TRUE(aPtr->operation());
}

// TEST_F(FixtureTestSuite, Operation_Test_False) {
//   //Act and Assert
//   ASSERT_FALSE(aPtr->operation());
// }

