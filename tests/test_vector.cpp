#include "Vector.h"
#include "gtest/gtest.h"
#include <cmath>

class PhysVectorTest : public ::testing::Test {

};

TEST(PhysVectorTest, DefaultConstructor) {
	auto t = mathengine::PhysVector();
	EXPECT_EQ(t.i(), 0);
	EXPECT_EQ(t.j(), 0);
	EXPECT_EQ(t.k(), 0);
}

TEST(PhysVectorTest, CustomConstructor) {
	auto t = mathengine::PhysVector(1.0,2.0,3.0);
	EXPECT_EQ(t.i(), 1.0);
	EXPECT_EQ(t.j(), 2.0);
	EXPECT_EQ(t.k(), 3.0);
}
TEST(PhysVectorTest, CopyConstructor) {
	auto t = mathengine::PhysVector(1.0,2.0,3.0);
	auto s = mathengine::PhysVector(t);
	EXPECT_EQ(t, s);
}
TEST(PhysVectorTest, MoveConstructor) {
	auto t = mathengine::PhysVector(1.0,2.0,3.0);
	auto s = mathengine::PhysVector(std::move(t));
	EXPECT_EQ(s.i(), 1.0);
	EXPECT_EQ(s.j(), 2.0);
	EXPECT_EQ(s.k(), 3.0);
}
TEST(PhysVectorTest, Equate) {
	auto t = mathengine::PhysVector(1.0,2.0,3.0);
	auto s = t;
	EXPECT_EQ(s.i(), 1.0);
	EXPECT_EQ(s.j(), 2.0);
	EXPECT_EQ(s.k(), 3.0);
}

TEST(PhysVectorTest, Equality) {
	auto t1 = mathengine::PhysVector(1.0,2.0,3.0);
	auto t2 = mathengine::PhysVector(1.0,2.0,3.0);
	EXPECT_TRUE(t1 == t2);
}
TEST(PhysVectorTest, Inequality) {
	auto t1 = mathengine::PhysVector(1.0,2.0,3.0);
	auto t2 = mathengine::PhysVector();
	EXPECT_TRUE(t1 != t2);
}
TEST(PhysVectorTest, AdditionAssign) {
	auto s = mathengine::PhysVector(1.0,2.0,3.0);
	auto t = mathengine::PhysVector(3.0,2.0,1.0);
	s += t;
	EXPECT_EQ(s.i(), 4.0);
	EXPECT_EQ(s.j(), 4.0);
	EXPECT_EQ(s.k(), 4.0);
}
TEST(PhysVectorTest, Addition) {
	auto s = mathengine::PhysVector(1.0,2.0,3.0);
	auto t = mathengine::PhysVector(3.0,2.0,1.0);
	auto u = s + t;
	EXPECT_EQ(u.i(), 4.0);
	EXPECT_EQ(u.j(), 4.0);
	EXPECT_EQ(u.k(), 4.0);
}
TEST(PhysVectorTest, SubtractionAssign) {
	auto s = mathengine::PhysVector(1.0,2.0,3.0);
	auto t = mathengine::PhysVector(3.0,2.0,1.0);
	s -= t;
	EXPECT_EQ(s.i(), -2.0);
	EXPECT_EQ(s.j(), 0);
	EXPECT_EQ(s.k(), 2.0);
}
TEST(PhysVectorTest, Subtraction) {
	auto s = mathengine::PhysVector(1.0,2.0,3.0);
	auto t = mathengine::PhysVector(3.0,2.0,1.0);
	auto u = s - t;
	EXPECT_EQ(u.i(), -2.0);
	EXPECT_EQ(u.j(), 0);
	EXPECT_EQ(u.k(), 2.0);
}
TEST(PhysVectorTest, MultiplyAssign) {
	auto s = mathengine::PhysVector(1.0,2.0,3.0);
	auto k = 2.0;
	s *= k;
	EXPECT_EQ(s.i(), 2.0);
	EXPECT_EQ(s.j(), 4.0);
	EXPECT_EQ(s.k(), 6.0);
}
TEST(PhysVectorTest, Multiply) {
	auto s = mathengine::PhysVector(1.0,2.0,3.0);
	auto k = 2.0;
	auto t = k*s;
	EXPECT_EQ(t.i(), 2.0);
	EXPECT_EQ(t.j(), 4.0);
	EXPECT_EQ(t.k(), 6.0);
}
TEST(PhysVectorTest, DivideAssign) {
	auto s = mathengine::PhysVector(1.0,2.0,3.0);
	auto k = 2.0;
	s /= k;
	EXPECT_EQ(s.i(), 0.5);
	EXPECT_EQ(s.j(), 1.0);
	EXPECT_EQ(s.k(), 1.5);
}
TEST(PhysVectorTest, Divide) {
	auto s = mathengine::PhysVector(1.0,2.0,3.0);
	auto k = 2.0;
	auto t = s/k;
	EXPECT_EQ(t.i(), 0.5);
	EXPECT_EQ(t.j(), 1.0);
	EXPECT_EQ(t.k(), 1.5);
}
TEST(PhysVectorTest, Dot) {
	auto s = mathengine::PhysVector(1.0,2.0,3.0);
	auto t = mathengine::PhysVector(3.0,2.0,1.0);
	auto n = s.dot(t);
	auto m = t.dot(s);
	EXPECT_EQ(n, m);
	EXPECT_EQ(n, 10);
}
TEST(PhysVectorTest, Cross1) {
	auto s = mathengine::PhysVector(1.0,2.0,3.0);
	auto t = mathengine::PhysVector(3.0,2.0,1.0);
	auto u = s.cross(t);
	EXPECT_EQ(u.i(), -4.0);
	EXPECT_EQ(u.j(), 8.0);
	EXPECT_EQ(u.k(), -4.0);
}
TEST(PhysVectorTest, Cross2) {
	auto s = mathengine::PhysVector(3,4,5);
	auto t = mathengine::PhysVector(7,8,9);
	auto u = s.cross(t);
	EXPECT_EQ(u.i(), -4.0);
	EXPECT_EQ(u.j(), 8.0);
	EXPECT_EQ(u.k(), -4.0);
}
TEST(PhysVectorTest, Magnitude) {
	auto s = mathengine::PhysVector(1.0,2.0,3.0);
	auto n = s.magnitude();
	EXPECT_EQ(n, std::sqrt(14));
}
TEST(PhysVectorTest, Normalize) {
	auto s = mathengine::PhysVector(1.0,2.0,3.0);
	auto n = s.magnitude();
	s.normalize();
	EXPECT_EQ(s.magnitude(), 1);
	EXPECT_EQ(s.i(), 1.0/n);
	EXPECT_EQ(s.j(), 2.0/n);
	EXPECT_EQ(s.k(), 3.0/n);
}
TEST(PhysVectorTest, Unit) {
	auto s = mathengine::PhysVector(1.0,2.0,3.0);
	auto t = s.unit();
	auto n = s.magnitude();
	EXPECT_EQ(t.magnitude(), 1);
	EXPECT_EQ(t.i(), 1.0/n);
	EXPECT_EQ(t.j(), 2.0/n);
	EXPECT_EQ(t.k(), 3.0/n);
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
