#include "gtest/gtest.h"
#include "Quaternion.h"
#include "Vector.h"
#include <cmath>

class PhysQuaternionTest: public ::testing::Test {

};
TEST(PhysQuaternionTest, ExplicitConstructor){
	auto t = mathengine::PhysQuaternion(3, 1, 0, 0);
	auto v = mathengine::PhysVector(1,0,0);
	EXPECT_EQ(v, t.v());
	EXPECT_DOUBLE_EQ(3, t.s());
}
TEST(PhysQuaternionTest, VectorConstructor){
	auto v = mathengine::PhysVector(1,0,0);
	auto t = mathengine::PhysQuaternion(3, v);
	EXPECT_EQ(v, t.v());
	EXPECT_DOUBLE_EQ(3, t.s());
	v.i(0);
	EXPECT_NE(v,t.v());
}
TEST(PhysQuaternionTest, OnlyVectorConstructor){
	auto v = mathengine::PhysVector(1,0,0);
	auto t = mathengine::PhysQuaternion(v);
	EXPECT_EQ(v, t.v());
	EXPECT_DOUBLE_EQ(0, t.s());
	v.i(0);
	EXPECT_NE(v,t.v());
}
TEST(PhysQuaternionTest, Equality){
	auto v = mathengine::PhysQuaternion(1,1,1,1);
	auto u = mathengine::PhysQuaternion(1,1,1,1);
	EXPECT_EQ(v,u);
}
TEST(PhysQuaternionTest, InEquality){
	auto v = mathengine::PhysQuaternion(1,1,1,1);
	auto u = mathengine::PhysQuaternion(0,1,1,1);
	EXPECT_NE(v,u);
}
TEST(PhysQuaternionTest, CopyConstructor){
	auto v = mathengine::PhysQuaternion(1,1,1,1);
	auto u = mathengine::PhysQuaternion(v);
	EXPECT_EQ(v, u);
	v.s(0);
	EXPECT_NE(v,u);
}
TEST(PhysQuaternionTest, MoveConstructor){
	auto v = mathengine::PhysQuaternion(1,1,1,1);
	auto u = mathengine::PhysQuaternion(std::move(v));
	auto t = mathengine::PhysVector(1,1,1);
	EXPECT_EQ(t, u.v());
	EXPECT_EQ(1, u.s());
}
TEST(PhysQuaternionTest, AdditionAssign){
	auto v = mathengine::PhysQuaternion(1,1,1,1);
	auto u = mathengine::PhysQuaternion(2,3,4,5);
	v += u;
	auto t = mathengine::PhysVector(4,5,6);
	EXPECT_EQ(3, v.s());
	EXPECT_EQ(t, v.v());
}
TEST(PhysQuaternionTest, Addition){
	auto v = mathengine::PhysQuaternion(1,1,1,1);
	auto u = mathengine::PhysQuaternion(2,3,4,5);
	auto w = v + u;
	auto t = mathengine::PhysVector(4,5,6);
	EXPECT_EQ(3, w.s());
	EXPECT_EQ(t, w.v());
}
TEST(PhysQuaternionTest, SubtractionAssign){
	auto v = mathengine::PhysQuaternion(2,3,4,5);
	auto u = mathengine::PhysQuaternion(1,1,1,1);
	v -= u;
	auto t = mathengine::PhysVector(2,3,4);
	EXPECT_EQ(1, v.s());
	EXPECT_EQ(t, v.v());
}
TEST(PhysQuaternionTest, Subtraction){
	auto v = mathengine::PhysQuaternion(1,1,1,1);
	auto u = mathengine::PhysQuaternion(2,3,4,5);
	auto w = u - v;
	auto t = mathengine::PhysVector(2,3,4);
	EXPECT_EQ(1, w.s());
	EXPECT_EQ(t, w.v());
}
TEST(PhysQuaternionTest, ScalarMultAssign){
	auto v = mathengine::PhysQuaternion(1,1,1,1);
	v *= 3;
	auto t = mathengine::PhysQuaternion(3,3,3,3);
	EXPECT_EQ(t,v);
}
TEST(PhysQuaternionTest, ScalarMult){
	auto v = mathengine::PhysQuaternion(1,1,1,1);
	auto u = v*3;
	auto t = mathengine::PhysQuaternion(3,3,3,3);
	EXPECT_EQ(t,u);
	u = 3*v;
	EXPECT_EQ(t,u);
}
TEST(PhysQuaternionTest, ScalarDivAssign){
	auto v = mathengine::PhysQuaternion(3,3,3,3);
	v /= 3;
	auto t = mathengine::PhysQuaternion(1,1,1,1);
	EXPECT_EQ(t,v);
}
TEST(PhysQuaternionTest, ScalarDiv){
	auto v = mathengine::PhysQuaternion(3,3,3,3);
	auto u = v/3;
	auto t = mathengine::PhysQuaternion(1,1,1,1);
	EXPECT_EQ(t,u);
}
TEST(PhysQuaternionTest, QuartMultAssign){
	auto v = mathengine::PhysQuaternion(2,3,4,5);
	auto u = mathengine::PhysQuaternion(6,7,8,9);
	v *= u;
	EXPECT_DOUBLE_EQ(-86,v.s());
	auto t = mathengine::PhysVector(28,48,44);
	EXPECT_EQ(t,v.v());
}
TEST(PhysQuaternionTest, QuartMult){
	auto v = mathengine::PhysQuaternion(2,3,4,5);
	auto u = mathengine::PhysQuaternion(6,7,8,9);
	auto w = v * u;
	EXPECT_DOUBLE_EQ(-86,w.s());
	auto t = mathengine::PhysVector(28,48,44);
	EXPECT_EQ(t,w.v());
}
TEST(PhysQuaternionTest, Magnitude){
	auto v = mathengine::PhysQuaternion(2,3,4,5);
	EXPECT_DOUBLE_EQ(std::sqrt(2*2+3*3+4*4+5*5), v.magnitude());
}
TEST(PhysQuaternionTest, Normalize){
	auto v = mathengine::PhysQuaternion(2,3,4,5);
	v.normalize();
	EXPECT_DOUBLE_EQ(2/std::sqrt(2*2+3*3+4*4+5*5), v.s());
	auto t = v.v();
	EXPECT_DOUBLE_EQ(3/std::sqrt(2*2+3*3+4*4+5*5), t.i());
	EXPECT_DOUBLE_EQ(4/std::sqrt(2*2+3*3+4*4+5*5), t.j());
	EXPECT_DOUBLE_EQ(5/std::sqrt(2*2+3*3+4*4+5*5), t.k());
}
TEST(PhysQuaternionTest, Norm){
	auto v = mathengine::PhysQuaternion(2,3,4,5);
	auto u = v.norm();
	EXPECT_DOUBLE_EQ(2/std::sqrt(2*2+3*3+4*4+5*5), u.s());
	auto t = u.v();
	EXPECT_DOUBLE_EQ(3/std::sqrt(2*2+3*3+4*4+5*5), t.i());
	EXPECT_DOUBLE_EQ(4/std::sqrt(2*2+3*3+4*4+5*5), t.j());
	EXPECT_DOUBLE_EQ(5/std::sqrt(2*2+3*3+4*4+5*5), t.k());

}
TEST(PhysQuaternionTest, ConjugateOf){
	auto t = mathengine::PhysVector(3,4,5);
	auto v = mathengine::PhysQuaternion(2,t);
	auto w = v.conjugate_of();
	EXPECT_EQ(t, v.v());
	EXPECT_EQ(2, v.s());
	t *= -1;
	EXPECT_EQ(t, w.v());
	EXPECT_EQ(2, w.s());
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
