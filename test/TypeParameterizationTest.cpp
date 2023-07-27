#include "gtest/gtest.h"
using testing::Types;

class ITempSensor{
    public:
    virtual int getOutSideTemp()=0;
};
class ModelATempSensor:public ITempSensor{
    public:
    int getOutSideTemp(){
        return 23;
    }
};
class ModelBTempSensor:public ITempSensor{
    public:
    int getOutSideTemp(){
        return 23;
    }
};
class AutoTempRegulator{
    //DIP: Abstraction
    ITempSensor* tempSensorPtr;
    public:
    AutoTempRegulator(ITempSensor* address):tempSensorPtr(address){}
    int regulateTemp(){
        return this->tempSensorPtr->getOutSideTemp();
    }
};

template <typename T>
ITempSensor* createObject();
template <>
ITempSensor* createObject<ModelATempSensor>() { return new ModelATempSensor(); }
template <>
ITempSensor* createObject<ModelBTempSensor>() { return new ModelBTempSensor(); }

template <typename T>
class TempSensorFixture:public testing::Test{
    protected:
    //Arrange
    ITempSensor* objUnderTest;
    TempSensorFixture() :objUnderTest{ createObject<T>() } 
};

typedef Types<ModelATempSensor,ModelBTempSensor> Implementations;

TYPED_TEST_SUITE(TempSensorFixture, Implementations);

TYPED_TEST(TempSensorFixture, GetTempTest) {
	ASSERT_EQ(objUnderTest.getOutSideTemp(),23);
}
