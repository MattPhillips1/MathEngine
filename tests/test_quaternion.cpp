#include "gtest/gtest.h"
#include "Quaternion.h"
#include "Vector.h"
#include <cmath>

class PhysQuaternionTest: public ::testing::Test {

};
TEST(PhysQuaternionTest, ExplicitConstructor){
	auto t = mathengine::Quaternion(3, 1, 0, 0);
	auto v = mathengine::Vector(1, 0, 0);
	EXPECT_EQ(v, t.v());
	EXPECT_DOUBLE_EQ(3, t.s());
}
TEST(PhysQuaternionTest, VectorConstructor){
	auto v = mathengine::Vector(1, 0, 0);
	auto t = mathengine::Quaternion(3, v);
	EXPECT_EQ(v, t.v());
	EXPECT_DOUBLE_EQ(3, t.s());
	v.i(0);
	EXPECT_NE(v,t.v());
}
TEST(PhysQuaternionTest, OnlyVectorConstructor){
	auto v = mathengine::Vector(1, 0, 0);
	auto t = mathengine::Quaternion(v);
	EXPECT_EQ(v, t.v());
	EXPECT_DOUBLE_EQ(0, t.s());
	v.i(0);
	EXPECT_NE(v,t.v());
}
TEST(PhysQuaternionTest, Equality){
	auto v = mathengine::Quaternion(1, 1, 1, 1);
	auto u = mathengine::Quaternion(1, 1, 1, 1);
	EXPECT_EQ(v,u);
}
TEST(PhysQuaternionTest, InEquality){
	auto v = mathengine::Quaternion(1, 1, 1, 1);
	auto u = mathengine::Quaternion(0, 1, 1, 1);
	EXPECT_NE(v,u);
}
TEST(PhysQuaternionTest, CopyConstructor){
	auto v = mathengine::Quaternion(1, 1, 1, 1);
	auto u = mathengine::Quaternion(v);
	EXPECT_EQ(v, u);
	v.s(0);
	EXPECT_NE(v,u);
}
TEST(PhysQuaternionTest, MoveConstructor){
	auto v = mathengine::Quaternion(1, 1, 1, 1);
	auto u = mathengine::Quaternion(std::move(v));
	auto t = mathengine::Vector(1, 1, 1);
	EXPECT_EQ(t, u.v());
	EXPECT_EQ(1, u.s());
}
TEST(PhysQuaternionTest, AdditionAssign){
	auto v = mathengine::Quaternion(1, 1, 1, 1);
	auto u = mathengine::Quaternion(2, 3, 4, 5);
	v += u;
	auto t = mathengine::Vector(4, 5, 6);
	EXPECT_EQ(3, v.s());
	EXPECT_EQ(t, v.v());
}
TEST(PhysQuaternionTest, Addition){
	auto v = mathengine::Quaternion(1, 1, 1, 1);
	auto u = mathengine::Quaternion(2, 3, 4, 5);
	auto w = v + u;
	auto t = mathengine::Vector(4, 5, 6);
	EXPECT_EQ(3, w.s());
	EXPECT_EQ(t, w.v());
}
TEST(PhysQuaternionTest, SubtractionAssign){
	auto v = mathengine::Quaternion(2, 3, 4, 5);
	auto u = mathengine::Quaternion(1, 1, 1, 1);
	v -= u;
	auto t = mathengine::Vector(2, 3, 4);
	EXPECT_EQ(1, v.s());
	EXPECT_EQ(t, v.v());
}
TEST(PhysQuaternionTest, Subtraction){
	auto v = mathengine::Quaternion(1, 1, 1, 1);
	auto u = mathengine::Quaternion(2, 3, 4, 5);
	auto w = u - v;
	auto t = mathengine::Vector(2, 3, 4);
	EXPECT_EQ(1, w.s());
	EXPECT_EQ(t, w.v());
}
TEST(PhysQuaternionTest, ScalarMultAssign){
	auto v = mathengine::Quaternion(1, 1, 1, 1);
	v *= 3;
	auto t = mathengine::Quaternion(3, 3, 3, 3);
	EXPECT_EQ(t,v);
}
TEST(PhysQuaternionTest, ScalarMult){
	auto v = mathengine::Quaternion(1, 1, 1, 1);
	auto u = v*3;
	auto t = mathengine::Quaternion(3, 3, 3, 3);
	EXPECT_EQ(t,u);
	u = 3*v;
	EXPECT_EQ(t,u);
}
TEST(PhysQuaternionTest, ScalarDivAssign){
	auto v = mathengine::Quaternion(3, 3, 3, 3);
	v /= 3;
	auto t = mathengine::Quaternion(1, 1, 1, 1);
	EXPECT_EQ(t,v);
}
TEST(PhysQuaternionTest, ScalarDiv){
	auto v = mathengine::Quaternion(3, 3, 3, 3);
	auto u = v/3;
	auto t = mathengine::Quaternion(1, 1, 1, 1);
	EXPECT_EQ(t,u);
}
TEST(PhysQuaternionTest, QuartMultAssign){
	auto v = mathengine::Quaternion(2, 3, 4, 5);
	auto u = mathengine::Quaternion(6, 7, 8, 9);
	v *= u;
	EXPECT_DOUBLE_EQ(-86,v.s());
	auto t = mathengine::Vector(28, 48, 44);
	EXPECT_EQ(t,v.v());
}
TEST(PhysQuaternionTest, QuartMult){
	auto v = mathengine::Quaternion(2, 3, 4, 5);
	auto u = mathengine::Quaternion(6, 7, 8, 9);
	auto w = v * u;
	EXPECT_DOUBLE_EQ(-86,w.s());
	auto t = mathengine::Vector(28, 48, 44);
	EXPECT_EQ(t,w.v());
}
TEST(PhysQuaternionTest, SquareSum){
	auto v = mathengine::Quaternion(2, 3, 4, 5);
	EXPECT_DOUBLE_EQ(2*2+3*3+4*4+5*5, v.square_sum());
}
TEST(PhysQuaternionTest, Magnitude){
	auto v = mathengine::Quaternion(2, 3, 4, 5);
	EXPECT_DOUBLE_EQ(std::sqrt(2*2+3*3+4*4+5*5), v.magnitude());
}
TEST(PhysQuaternionTest, Normalize){
	auto v = mathengine::Quaternion(2, 3, 4, 5);
	v.normalize();
	EXPECT_DOUBLE_EQ(2/std::sqrt(2*2+3*3+4*4+5*5), v.s());
	auto t = v.v();
	EXPECT_DOUBLE_EQ(3/std::sqrt(2*2+3*3+4*4+5*5), t.i());
	EXPECT_DOUBLE_EQ(4/std::sqrt(2*2+3*3+4*4+5*5), t.j());
	EXPECT_DOUBLE_EQ(5/std::sqrt(2*2+3*3+4*4+5*5), t.k());
}
TEST(PhysQuaternionTest, Unit){
	auto v = mathengine::Quaternion(2, 3, 4, 5);
	auto u = v.unit();
	EXPECT_DOUBLE_EQ(2/std::sqrt(2*2+3*3+4*4+5*5), u.s());
	auto t = u.v();
	EXPECT_DOUBLE_EQ(3/std::sqrt(2*2+3*3+4*4+5*5), t.i());
	EXPECT_DOUBLE_EQ(4/std::sqrt(2*2+3*3+4*4+5*5), t.j());
	EXPECT_DOUBLE_EQ(5/std::sqrt(2*2+3*3+4*4+5*5), t.k());

}
TEST(PhysQuaternionTest, ConjugateOf){
	auto t = mathengine::Vector(3, 4, 5);
	auto v = mathengine::Quaternion(2, t);
	auto w = v.conjugate_of();
	EXPECT_EQ(t, v.v());
	EXPECT_EQ(2, v.s());
	t *= -1;
	EXPECT_EQ(t, w.v());
	EXPECT_EQ(2, w.s());
}
TEST(PhysQuaternionTest, InverseOf){
	auto t = mathengine::Quaternion(3, 5, 8, 2);
	auto d = t.square_sum();
	t = t.inverse_of();
	EXPECT_DOUBLE_EQ(3/d, t.s());
	auto v = t.v();
	EXPECT_DOUBLE_EQ(-5/d, v.i());
	EXPECT_DOUBLE_EQ(-8/d, v.j());
	EXPECT_DOUBLE_EQ(-2/d, v.k());
}
TEST(PhysQuaternionTest, MakeRotation){
	auto v = mathengine::Vector(1, 0, 0);
	auto t = mathengine::Quaternion(M_PI, v);
	t.make_rotation();
	auto u = mathengine::Vector(1, 0, 0);
	EXPECT_DOUBLE_EQ(cos(M_PI/2), t.s());
	EXPECT_EQ(u, t.v());
}
TEST(PhysQuaternionTest, RotationUnit){
	auto v = mathengine::Vector(2, 0, 0);
	auto t = mathengine::Quaternion(M_PI, v);
	t = t.rotation_unit();
	auto u = mathengine::Vector(1, 0, 0);
	EXPECT_DOUBLE_EQ(cos(M_PI/2), t.s());
	EXPECT_EQ(u, t.v());
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
