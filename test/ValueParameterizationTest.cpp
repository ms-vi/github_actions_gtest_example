#include <gtest/gtest.h>

int divFunc(int numerator, int denominator){
    if(denominator <= 0){
        return 0;
    }
    return numerator/denominator;
}

class DivFuncTestSuite:public testing::TestWithParam<std::tuple<int, int, int>[>]{
protected:
    DivFuncTestSuite(){}
    ~DivFuncTestSuite(){}
};

TEST_P(DivFuncTestSuite, HandleInputs){
    int numerator = std::get<0>(GetParam());
    int denominator = std::get<1>(GetParam());
    int expectedValue = std::get<2>(GetParam());
    int actualValue = divFunc(numerator, denominator);
    ASSERT_EQ(actualValue, expectedValue);
}

INSTANTIATE_TEST_SUITE_P(
    DivFuncTestSuiteParameterExample,
    DivFuncTestSuite,
    ::testing::Values(
        std::make_tuple(10, 5, 20),
        std::make_tuple(10, 0, 0),
        std::make_tuple(10, -5, 0)
    )
);