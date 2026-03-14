#include <gtest/gtest.h>
#include <limits>
#include <sstream>
#include "Monome.h"

TEST(MonomeTest, DefaultConstructor) {
    Monome m;
    EXPECT_EQ(m.get_coeff(), 1.0);
    EXPECT_EQ(m.get_degr().N, 0u);
}

TEST(MonomeTest, ParameterizedConstructor) {
    degrees d(5);
    Monome m(2.5, d);
    EXPECT_EQ(m.get_coeff(), 2.5);
    EXPECT_EQ(m.get_degr().N, 5u);
}

TEST(MonomeTest, SetCoefficient) {
    Monome m;
    m.set_coefficient(3.14);
    EXPECT_EQ(m.get_coeff(), 3.14);
}

TEST(MonomeTest, SetDegree) {
    Monome m;
    m.set_degree(X, 3);
    m.set_degree(Y, -2);
    m.set_degree(Z, 5);

    EXPECT_EQ(m.get_degr().s[X], 3);
    EXPECT_EQ(m.get_degr().s[Y], -2);
    EXPECT_EQ(m.get_degr().s[Z], 5);
}

TEST(MonomeTest, AdditionSimilarMonomes) {
    Monome m1(2.0, degrees(5));
    Monome m2(3.0, degrees(5));
    Monome result = m1 + m2;

    EXPECT_EQ(result.get_coeff(), 5.0);
    EXPECT_EQ(result.get_degr().N, 5u);
}

TEST(MonomeTest, AdditionDifferentDegreesThrows) {
    Monome m1(2.0, degrees(5));
    Monome m2(3.0, degrees(6));

    EXPECT_THROW(m1 + m2, int);
}

TEST(MonomeTest, AdditionOverflowProtection) {
    Monome m1(std::numeric_limits<double>::max() / 2, degrees(5));
    Monome m2(std::numeric_limits<double>::max() / 2, degrees(5));
    Monome result = m1 + m2;

    EXPECT_EQ(result.get_coeff(), std::numeric_limits<double>::max());
}

TEST(MonomeTest, SubtractionSimilarMonomes) {
    Monome m1(5.0, degrees(5));
    Monome m2(3.0, degrees(5));
    Monome result = m1 - m2;

    EXPECT_EQ(result.get_coeff(), 2.0);
    EXPECT_EQ(result.get_degr().N, 5u);
}

TEST(MonomeTest, Multiplication) {
    Monome m1(2.0, degrees(5));
    m1.set_degree(X, 2);
    m1.set_degree(Y, 1);
    m1.set_degree(Z, 0);

    Monome m2(3.0, degrees(5));
    m2.set_degree(X, 1);
    m2.set_degree(Y, 2);
    m2.set_degree(Z, 0);

    Monome result = m1 * m2;

    EXPECT_EQ(result.get_coeff(), 6.0);
    EXPECT_EQ(result.get_degr().s[X], 3);
    EXPECT_EQ(result.get_degr().s[Y], 3);
    EXPECT_EQ(result.get_degr().s[Z], 0);
}

TEST(MonomeTest, Division) {
    Monome m1(6.0, degrees(5));
    m1.set_degree(X, 3);
    m1.set_degree(Y, 2);
    m1.set_degree(Z, 1);

    Monome m2(2.0, degrees(5));
    m2.set_degree(X, 1);
    m2.set_degree(Y, 1);
    m2.set_degree(Z, 1);

    Monome result = m1 / m2;

    EXPECT_EQ(result.get_coeff(), 3.0);
    EXPECT_EQ(result.get_degr().s[X], 2);
    EXPECT_EQ(result.get_degr().s[Y], 1);
    EXPECT_EQ(result.get_degr().s[Z], 0);
}

TEST(MonomeTest, MultiplyByScalar) {
    Monome m(2.5, degrees(5));
    Monome result = m * 3.0;

    EXPECT_EQ(result.get_coeff(), 7.5);
    EXPECT_EQ(result.get_degr().N, 5u);
}

TEST(MonomeTest, DivideByScalar) {
    Monome m(7.5, degrees(5));
    Monome result = m / 3.0;

    EXPECT_EQ(result.get_coeff(), 2.5);
    EXPECT_EQ(result.get_degr().N, 5u);
}

TEST(MonomeTest, UnaryMinus) {
    Monome m(2.5, degrees(5));
    Monome result = -m;

    EXPECT_EQ(result.get_coeff(), -2.5);
    EXPECT_EQ(result.get_degr().N, 5u);
}

TEST(MonomeTest, CompoundAddition) {
    Monome m1(2.0, degrees(5));
    Monome m2(3.0, degrees(5));
    m1 += m2;

    EXPECT_EQ(m1.get_coeff(), 5.0);
}

TEST(MonomeTest, CompoundMultiplication) {
    Monome m1(2.0, degrees(5));
    m1.set_degree(X, 2);

    Monome m2(3.0, degrees(5));
    m2.set_degree(X, 1);

    m1 *= m2;

    EXPECT_EQ(m1.get_coeff(), 6.0);
    EXPECT_EQ(m1.get_degr().s[X], 3);
}

TEST(MonomeTest, EqualityOperator) {
    Monome m1(2.5, degrees(5));
    Monome m2(2.5, degrees(5));
    Monome m3(3.0, degrees(5));
    Monome m4(2.5, degrees(6));

    EXPECT_TRUE(m1 == m2);
    EXPECT_FALSE(m1.fully_equals(m3));
    EXPECT_FALSE(m1 == m4);
}

TEST(MonomeTest, InequalityOperator) {
    Monome m1(2.5, degrees(5));
    Monome m2(2.5, degrees(5));
    Monome m3(3.0, degrees(5));

    EXPECT_FALSE(m1 != m2);
    EXPECT_FALSE(m1.fully_equals(m3));
}

TEST(MonomeTest, IsSimilarTo) {
    Monome m1(2.5, degrees(5));
    Monome m2(3.0, degrees(5));
    Monome m3(2.5, degrees(6));

    EXPECT_TRUE(m1 == m2);
    EXPECT_FALSE(m1 == m3);
}

TEST(MonomeTest, ValueInPoint) {
    Monome m(2.0, degrees(5));
    m.set_degree(X, 2);
    m.set_degree(Y, 1);
    m.set_degree(Z, 0);

    double result = m.value_in_point(3.0, 2.0, 5.0);
    EXPECT_EQ(result, 2.0 * 9.0 * 2.0);
}