#include <gtest/gtest.h>
#include <limits>
#include "Monome.h"
#include "Polynome.h"
#include "HList.h"

class PolynomeTest : public ::testing::Test {
protected:
    void SetUp() override {
        m1 = Monome(2.0, degrees(5));
        m1.set_degree(X, 2);
        m1.set_degree(Y, 1);
        m1.set_degree(Z, 0);

        m2 = Monome(3.0, degrees(5));
        m2.set_degree(X, 1);
        m2.set_degree(Y, 2);
        m2.set_degree(Z, 0);

        m3 = Monome(1.0, degrees(3));
        m3.set_degree(X, 0);
        m3.set_degree(Y, 1);
        m3.set_degree(Z, 1);

        m4 = Monome(5.0, degrees(5));
        m4.set_degree(X, 2);
        m4.set_degree(Y, 1);
        m4.set_degree(Z, 0);

        zero_monome = Monome(0.0, degrees(0));
        zero_monome.set_degree(X, 0);
        zero_monome.set_degree(Y, 0);
        zero_monome.set_degree(Z, 0);
    }
    Monome m1, m2, m3, m4, zero_monome;
};

TEST_F(PolynomeTest, DefaultConstructor) {
    Polynome p;
    EXPECT_EQ(p.calculate(1.0, 1.0, 1.0), 0.0);
    EXPECT_EQ(p.calculate(2.0, 3.0, 4.0), 0.0);
}

TEST_F(PolynomeTest, ConstructorFromMonome) {
    Polynome p(m1);

    double expected = m1.value_in_point(2.0, 3.0, 4.0);
    EXPECT_EQ(p.calculate(2.0, 3.0, 4.0), expected);

    expected = m1.value_in_point(1.0, 1.0, 1.0);
    EXPECT_EQ(p.calculate(1.0, 1.0, 1.0), expected);
}

TEST_F(PolynomeTest, ConstructorFromString) {
    GTEST_SKIP() << "String constructor not implemented";
}

TEST_F(PolynomeTest, CopyConstructor) {
    Polynome p1(m1);
    Polynome p2(p1);

    EXPECT_EQ(p1.calculate(2.0, 3.0, 4.0), p2.calculate(2.0, 3.0, 4.0));
    EXPECT_EQ(p1.calculate(1.0, 5.0, 2.0), p2.calculate(1.0, 5.0, 2.0));
}

TEST_F(PolynomeTest, MoveConstructor) {
    Polynome p1(m1);
    double expected = p1.calculate(2.0, 3.0, 4.0);

    Polynome p2(std::move(p1));

    EXPECT_EQ(p2.calculate(2.0, 3.0, 4.0), expected);
}

TEST_F(PolynomeTest, CopyAssignment) {
    Polynome p1(m1);
    Polynome p2;

    p2 = p1;

    EXPECT_EQ(p1.calculate(2.0, 3.0, 4.0), p2.calculate(2.0, 3.0, 4.0));

    Polynome p3(m2);
    p1 = p3;
    EXPECT_EQ(p2.calculate(2.0, 3.0, 4.0), m1.value_in_point(2.0, 3.0, 4.0));
}

TEST_F(PolynomeTest, MoveAssignment) {
    Polynome p1(m1);
    double expected = p1.calculate(2.0, 3.0, 4.0);
    Polynome p2;

    p2 = std::move(p1);

    EXPECT_EQ(p2.calculate(2.0, 3.0, 4.0), expected);
}

TEST_F(PolynomeTest, AdditionOfPolynomes) {
    Polynome p1(m1);
    Polynome p2(m2);
    Polynome result = p1 + p2;
    
    double expected = m1.value_in_point(2.0, 3.0, 1.0) +
        m2.value_in_point(2.0, 3.0, 1.0);

    EXPECT_EQ(result.calculate(2.0, 3.0, 1.0), expected);

    Polynome p3(zero_monome);
    result = p1 + p3;

    EXPECT_EQ(result.calculate(2.0, 3.0, 1.0),
        m1.value_in_point(2.0, 3.0, 1.0));
}

TEST_F(PolynomeTest, SubtractionOfPolynomes) {
    Polynome p1(m1);
    Polynome p2(m2);
    Polynome result = p1 - p2;

    double expected = m1.value_in_point(2.0, 3.0, 1.0) -
        m2.value_in_point(2.0, 3.0, 1.0);

    EXPECT_EQ(result.calculate(2.0, 3.0, 1.0), expected);

    result = p1 - p1;
    EXPECT_EQ(result.calculate(2.0, 3.0, 1.0), 0.0);
}

TEST_F(PolynomeTest, MultiplicationOfPolynomes) {
    Polynome p1(m1);
    Polynome p2(m2);

    Polynome result = p1 * p2;

    Monome expected_mon(6.0, degrees(5));
    expected_mon.set_degree(X, 3);
    expected_mon.set_degree(Y, 3);
    expected_mon.set_degree(Z, 0);

    double expected = expected_mon.value_in_point(2.0, 3.0, 1.0);
    EXPECT_EQ(result.calculate(2.0, 3.0, 1.0), expected);

    Polynome p3(zero_monome);
    result = p1 * p3;
    EXPECT_EQ(result.calculate(2.0, 3.0, 1.0), 0.0);
}

TEST_F(PolynomeTest, CompoundAddition) {
    Polynome p1(m1);
    Polynome p2(m2);

    p1 += p2;

    double expected = m1.value_in_point(2.0, 3.0, 1.0) +
        m2.value_in_point(2.0, 3.0, 1.0);

    EXPECT_EQ(p1.calculate(2.0, 3.0, 1.0), expected);
}

TEST_F(PolynomeTest, CompoundSubtraction) {
    Polynome p1(m1);
    Polynome p2(m2);

    p1 -= p2;

    double expected = m1.value_in_point(2.0, 3.0, 1.0) -
        m2.value_in_point(2.0, 3.0, 1.0);

    EXPECT_EQ(p1.calculate(2.0, 3.0, 1.0), expected);
}

TEST_F(PolynomeTest, CompoundMultiplication) {
    Polynome p1(m1);
    Polynome p2(m2);

    p1 *= p2;

    Monome expected_mon(6.0, degrees(5));
    expected_mon.set_degree(X, 3);
    expected_mon.set_degree(Y, 3);
    expected_mon.set_degree(Z, 0);

    double expected = expected_mon.value_in_point(2.0, 3.0, 1.0);
    EXPECT_EQ(p1.calculate(2.0, 3.0, 1.0), expected);
}

TEST_F(PolynomeTest, AddMonomeToPolynome) {
    Polynome p(m1);
    Polynome result = p + m2;

    double expected = m1.value_in_point(2.0, 3.0, 1.0) +
        m2.value_in_point(2.0, 3.0, 1.0);

    EXPECT_EQ(result.calculate(2.0, 3.0, 1.0), expected);

    result = p + m4;
    expected = (m1.get_coeff() + m4.get_coeff()) *
        pow(2.0, 2) * pow(3.0, 1);

    EXPECT_EQ(result.calculate(2.0, 3.0, 1.0), expected);
}

TEST_F(PolynomeTest, SubtractMonomeFromPolynome) {
    Polynome p(m1);
    Polynome result = p - m2;

    double expected = m1.value_in_point(2.0, 3.0, 1.0) -
        m2.value_in_point(2.0, 3.0, 1.0);

    EXPECT_EQ(result.calculate(2.0, 3.0, 1.0), expected);

    result = p - m4;
    expected = (m1.get_coeff() - m4.get_coeff()) *
        pow(2.0, 2) * pow(3.0, 1);

    EXPECT_EQ(result.calculate(2.0, 3.0, 1.0), expected);
}

TEST_F(PolynomeTest, MultiplyPolynomeByMonome) {
    Polynome p(m1);
    Polynome result = p * m2;

    Monome expected_mon(6.0, degrees(5));
    expected_mon.set_degree(X, 3);
    expected_mon.set_degree(Y, 3);
    expected_mon.set_degree(Z, 0);

    double expected = expected_mon.value_in_point(2.0, 3.0, 1.0);
    EXPECT_EQ(result.calculate(2.0, 3.0, 1.0), expected);

    result = p * zero_monome;
    EXPECT_EQ(result.calculate(2.0, 3.0, 1.0), 0.0);
}

TEST_F(PolynomeTest, DividePolynomeByMonome) {
    Polynome p(m1);

    Monome divisor(2.0, degrees(0));
    divisor.set_degree(X, 1);
    divisor.set_degree(Y, 0);
    divisor.set_degree(Z, 0);

    Polynome result = p / divisor;

    Monome expected_mon(1.0, degrees(5));
    expected_mon.set_degree(X, 1);
    expected_mon.set_degree(Y, 1);
    expected_mon.set_degree(Z, 0);

    double expected = expected_mon.value_in_point(2.0, 3.0, 1.0);
    EXPECT_EQ(result.calculate(2.0, 3.0, 1.0), expected);
}

TEST_F(PolynomeTest, CompoundAddMonome) {
    Polynome p(m1);
    p += m2;

    double expected = m1.value_in_point(2.0, 3.0, 1.0) +
        m2.value_in_point(2.0, 3.0, 1.0);

    EXPECT_EQ(p.calculate(2.0, 3.0, 1.0), expected);
}

TEST_F(PolynomeTest, CompoundSubtractMonome) {
    Polynome p(m1);
    p -= m2;

    double expected = m1.value_in_point(2.0, 3.0, 1.0) -
        m2.value_in_point(2.0, 3.0, 1.0);

    EXPECT_EQ(p.calculate(2.0, 3.0, 1.0), expected);
}

TEST_F(PolynomeTest, CompoundMultiplyByMonome) {
    Polynome p(m1);
    p *= m2;

    Monome expected_mon(6.0, degrees(5));
    expected_mon.set_degree(X, 3);
    expected_mon.set_degree(Y, 3);
    expected_mon.set_degree(Z, 0);

    double expected = expected_mon.value_in_point(2.0, 3.0, 1.0);
    EXPECT_EQ(p.calculate(2.0, 3.0, 1.0), expected);
}

TEST_F(PolynomeTest, CompoundDivideByMonome) {
    Polynome p(m1);

    Monome divisor(2.0, degrees(0));
    divisor.set_degree(X, 1);
    divisor.set_degree(Y, 0);
    divisor.set_degree(Z, 0);

    p /= divisor;

    Monome expected_mon(1.0, degrees(5));
    expected_mon.set_degree(X, 1);
    expected_mon.set_degree(Y, 1);
    expected_mon.set_degree(Z, 0);

    double expected = expected_mon.value_in_point(2.0, 3.0, 1.0);
    EXPECT_EQ(p.calculate(2.0, 3.0, 1.0), expected);
}

TEST_F(PolynomeTest, CalculateComplexPolynome) {
    Polynome p(m1);
    p += m2;
    p += m3;

    double expected = 2.0 * pow(2.0, 2) * 3.0 +
        3.0 * 2.0 * pow(3.0, 2) +
        1.0 * 3.0 * 4.0;

    EXPECT_EQ(p.calculate(2.0, 3.0, 4.0), expected);

    expected = 2.0 * pow(1.0, 2) * 2.0 +
        3.0 * 1.0 * pow(2.0, 2) +
        1.0 * 2.0 * 3.0;

    EXPECT_EQ(p.calculate(1.0, 2.0, 3.0), expected);
}

TEST_F(PolynomeTest, AssociativityOfAddition) {
    Polynome p1(m1);
    Polynome p2(m2);
    Polynome p3(m3);

    Polynome left = (p1 + p2) + p3;
    Polynome right = p1 + (p2 + p3);

    double x = 2.0, y = 3.0, z = 4.0;
    EXPECT_EQ(left.calculate(x, y, z), right.calculate(x, y, z));
}

TEST_F(PolynomeTest, CommutativityOfAddition) {
    Polynome p1(m1);
    Polynome p2(m2);

    Polynome left = p1 + p2;
    Polynome right = p2 + p1;

    double x = 2.0, y = 3.0, z = 4.0;
    EXPECT_EQ(left.calculate(x, y, z), right.calculate(x, y, z));
}

TEST_F(PolynomeTest, Distributivity) {
    Polynome p1(m1);
    Polynome p2(m2);
    Polynome p3(m3);

    Polynome left = p1 * (p2 + p3);
    Polynome right = (p1 * p2) + (p1 * p3);

    double x = 2.0, y = 3.0, z = 4.0;
    EXPECT_EQ(left.calculate(x, y, z), right.calculate(x, y, z));
}

TEST_F(PolynomeTest, DegreeRangeCheck) {
    Monome high_degree(1.0, degrees(0));
    high_degree.set_degree(X, DEGR_MAX + 1);

    Polynome p;
    p += high_degree;

    EXPECT_EQ(p.calculate(2.0, 3.0, 4.0), 0.0);

    Monome low_degree(1.0, degrees(0));
    low_degree.set_degree(Y, DEGR_MIN - 1);

    p += low_degree;
    EXPECT_EQ(p.calculate(2.0, 3.0, 4.0), 0.0);
}