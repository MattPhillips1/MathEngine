#include "Matrix.h"
#include "Vector.h"
#include "gtest/gtest.h"

class PhysMatrixTest : public ::testing::Test {

};

TEST(PhysMatrixTestInt, DefaultConstructor) {
	auto t = mathengine::Matrix<int>();
	for(int i = 0; i < 3; ++i){
		const auto& r = t[i];
		EXPECT_EQ(0, r.i());
		EXPECT_EQ(0, r.j());
		EXPECT_EQ(0, r.k());
	}
}

TEST(PhysMatrixTestDouble, DefaultConstructor) {
    auto t = mathengine::Matrix<double>();
    for(int i = 0; i < 3; ++i){
        const auto& r = t[i];
        EXPECT_DOUBLE_EQ(0, r.i());
        EXPECT_DOUBLE_EQ(0, r.j());
        EXPECT_DOUBLE_EQ(0, r.k());
    }
}
TEST(PhysMatrixTest, ExplicitConstructor) {
	auto t = mathengine::Matrix<double>(1, 0, 0, 0, 1, 0, 0, 0, 1);
	EXPECT_DOUBLE_EQ(1, t[0].i());
	EXPECT_DOUBLE_EQ(0, t[0].j());
	EXPECT_DOUBLE_EQ(0, t[0].k());
	EXPECT_DOUBLE_EQ(0, t[1].i());
	EXPECT_DOUBLE_EQ(1, t[1].j());
	EXPECT_DOUBLE_EQ(0, t[1].k());
	EXPECT_DOUBLE_EQ(0, t[2].i());
	EXPECT_DOUBLE_EQ(0, t[2].j());
	EXPECT_DOUBLE_EQ(1, t[2].k());
}
TEST(PhysMatrixTest, ExplicitConstructor) {
    auto t = mathengine::Matrix<int>(1, 0, 0, 0, 1, 0, 0, 0, 1);
    EXPECT_DOUBLE_EQ(1, t[0].i());
    EXPECT_DOUBLE_EQ(0, t[0].j());
    EXPECT_DOUBLE_EQ(0, t[0].k());
    EXPECT_DOUBLE_EQ(0, t[1].i());
    EXPECT_DOUBLE_EQ(1, t[1].j());
    EXPECT_DOUBLE_EQ(0, t[1].k());
    EXPECT_DOUBLE_EQ(0, t[2].i());
    EXPECT_DOUBLE_EQ(0, t[2].j());
    EXPECT_DOUBLE_EQ(1, t[2].k());
}
TEST(PhysMatrixTest, VectorCopyConstructor) {
	auto r1 = mathengine::Vector(2, 3, 4);
	auto r2 = mathengine::Vector(5, 12, 6);
	auto r3 = mathengine::Vector(28, 8, 6);
	auto t = mathengine::Matrix(r1, r2, r3);
	EXPECT_EQ(t[0], r1);
	r1.i(0);
	EXPECT_NE(t[0], r1);

	EXPECT_EQ(t[1], r2);
	r2.i(0);
	EXPECT_NE(t[1], r2);

	EXPECT_EQ(t[2], r3);
	r3.i(0);
	EXPECT_NE(t[2], r3);
}
TEST(PhysMatrixTest, VectorMoveConstructor) {
	auto r1 = mathengine::Vector(2, 3, 4);
	auto r2 = mathengine::Vector(5, 12, 6);
	auto r3 = mathengine::Vector(28, 8, 6);
	auto t1 = mathengine::Matrix(r1, r2, r3);
	auto t2 = mathengine::Matrix(std::move(r1), std::move(r2), std::move(r3));

	EXPECT_EQ(t1, t2);
}
TEST(PhysMatrixTest, AdditionAssign) {
	auto t1 = mathengine::Matrix(1, 0, 0, 0, 1, 0, 0, 0, 1);
	auto t2 = mathengine::Matrix(1, 4, 3, 0, 1, 0, 6, 7, 1);
	t1 += t2;
	EXPECT_DOUBLE_EQ(2, t1[0].i());
	EXPECT_DOUBLE_EQ(4, t1[0].j());
	EXPECT_DOUBLE_EQ(3, t1[0].k());
	EXPECT_DOUBLE_EQ(0, t1[1].i());
	EXPECT_DOUBLE_EQ(2, t1[1].j());
	EXPECT_DOUBLE_EQ(0, t1[1].k());
	EXPECT_DOUBLE_EQ(6, t1[2].i());
	EXPECT_DOUBLE_EQ(7, t1[2].j());
	EXPECT_DOUBLE_EQ(2, t1[2].k());
}
TEST(PhysMatrixTest, Addition) {
	auto t1 = mathengine::Matrix(1, 0, 0, 0, 1, 0, 0, 0, 1);
	auto t2 = mathengine::Matrix(1, 4, 3, 0, 1, 0, 6, 7, 1);
	auto t3 = t1 + t2;
	EXPECT_DOUBLE_EQ(2, t3[0].i());
	EXPECT_DOUBLE_EQ(4, t3[0].j());
	EXPECT_DOUBLE_EQ(3, t3[0].k());
	EXPECT_DOUBLE_EQ(0, t3[1].i());
	EXPECT_DOUBLE_EQ(2, t3[1].j());
	EXPECT_DOUBLE_EQ(0, t3[1].k());
	EXPECT_DOUBLE_EQ(6, t3[2].i());
	EXPECT_DOUBLE_EQ(7, t3[2].j());
	EXPECT_DOUBLE_EQ(2, t3[2].k());
}
TEST(PhysMatrixTest, SubtractionAssign) {
	auto t1 = mathengine::Matrix(1, 0, 0, 0, 1, 0, 0, 0, 1);
	auto t2 = mathengine::Matrix(1, 4, 3, 0, 1, 0, 6, 7, 1);
	t1 -= t2;
	EXPECT_DOUBLE_EQ(0, t1[0].i());
	EXPECT_DOUBLE_EQ(-4, t1[0].j());
	EXPECT_DOUBLE_EQ(-3, t1[0].k());
	EXPECT_DOUBLE_EQ(0, t1[1].i());
	EXPECT_DOUBLE_EQ(0, t1[1].j());
	EXPECT_DOUBLE_EQ(0, t1[1].k());
	EXPECT_DOUBLE_EQ(-6, t1[2].i());
	EXPECT_DOUBLE_EQ(-7, t1[2].j());
	EXPECT_DOUBLE_EQ(0, t1[2].k());
}
TEST(PhysMatrixTest, Subtraction) {
	auto t1 = mathengine::Matrix(1, 0, 0, 0, 1, 0, 0, 0, 1);
	auto t2 = mathengine::Matrix(1, 4, 3, 0, 1, 0, 6, 7, 1);
	auto t3 = t1 - t2;
	EXPECT_DOUBLE_EQ(0, t3[0].i());
	EXPECT_DOUBLE_EQ(-4, t3[0].j());
	EXPECT_DOUBLE_EQ(-3, t3[0].k());
	EXPECT_DOUBLE_EQ(0, t3[1].i());
	EXPECT_DOUBLE_EQ(0, t3[1].j());
	EXPECT_DOUBLE_EQ(0, t3[1].k());
	EXPECT_DOUBLE_EQ(-6, t3[2].i());
	EXPECT_DOUBLE_EQ(-7, t3[2].j());
	EXPECT_DOUBLE_EQ(0, t3[2].k());
}
TEST(PhysMatrixTest, ScalarMultiplicationAssign){
	auto t = mathengine::Matrix(1, 4, 3, 0, 1, 0, 6, 7, 1);
	t *= 2;

	EXPECT_DOUBLE_EQ(2, t[0].i());
	EXPECT_DOUBLE_EQ(8, t[0].j());
	EXPECT_DOUBLE_EQ(6, t[0].k());
	EXPECT_DOUBLE_EQ(0, t[1].i());
	EXPECT_DOUBLE_EQ(2, t[1].j());
	EXPECT_DOUBLE_EQ(0, t[1].k());
	EXPECT_DOUBLE_EQ(12, t[2].i());
	EXPECT_DOUBLE_EQ(14, t[2].j());
	EXPECT_DOUBLE_EQ(2, t[2].k());
}
TEST(PhysMatrixTest, ScalarMultiplication){
	auto t = mathengine::Matrix(1, 4, 3, 0, 1, 0, 6, 7, 1);
	auto t2 = 2*t;

	EXPECT_DOUBLE_EQ(2, t2[0].i());
	EXPECT_DOUBLE_EQ(8, t2[0].j());
	EXPECT_DOUBLE_EQ(6, t2[0].k());
	EXPECT_DOUBLE_EQ(0, t2[1].i());
	EXPECT_DOUBLE_EQ(2, t2[1].j());
	EXPECT_DOUBLE_EQ(0, t2[1].k());
	EXPECT_DOUBLE_EQ(12, t2[2].i());
	EXPECT_DOUBLE_EQ(14, t2[2].j());
	EXPECT_DOUBLE_EQ(2, t2[2].k());
}
TEST(PhysMatrixTest, ScalarDivisionAssign){
	auto t = mathengine::Matrix(1, 2, 3, 4, 5, 6, 7, 8, 9);
	t /= 2;

	EXPECT_DOUBLE_EQ(0.5, t[0].i());
	EXPECT_DOUBLE_EQ(1, t[0].j());
	EXPECT_DOUBLE_EQ(1.5, t[0].k());
	EXPECT_DOUBLE_EQ(2, t[1].i());
	EXPECT_DOUBLE_EQ(2.5, t[1].j());
	EXPECT_DOUBLE_EQ(3, t[1].k());
	EXPECT_DOUBLE_EQ(3.5, t[2].i());
	EXPECT_DOUBLE_EQ(4, t[2].j());
	EXPECT_DOUBLE_EQ(4.5, t[2].k());
}
TEST(PhysMatrixTest, ScalarDivision){
	auto t1 = mathengine::Matrix(1, 2, 3, 4, 5, 6, 7, 8, 9);
	auto t = t1/2;

	EXPECT_DOUBLE_EQ(0.5, t[0].i());
	EXPECT_DOUBLE_EQ(1, t[0].j());
	EXPECT_DOUBLE_EQ(1.5, t[0].k());
	EXPECT_DOUBLE_EQ(2, t[1].i());
	EXPECT_DOUBLE_EQ(2.5, t[1].j());
	EXPECT_DOUBLE_EQ(3, t[1].k());
	EXPECT_DOUBLE_EQ(3.5, t[2].i());
	EXPECT_DOUBLE_EQ(4, t[2].j());
	EXPECT_DOUBLE_EQ(4.5, t[2].k());
}
TEST(PhysMatrixTest, VectorMultiplication){
	auto v = mathengine::Vector(1, 2, 3);
	auto m = mathengine::Matrix(3, 3, 3, 3, 3, 3, 3, 3, 3);
	auto u = m*v;
	EXPECT_DOUBLE_EQ(18, u.i());
	EXPECT_DOUBLE_EQ(18, u.j());
	EXPECT_DOUBLE_EQ(18, u.k());
}
TEST(PhysMatrixTest, MatrixMultiplicationAssign){
	auto a = mathengine::Matrix(1, 2, 3, 4, 5, 6, 7, 8, 9);
	auto b = mathengine::Matrix(7, 8, 9, 1, 2, 3, 4, 5, 6);
	a *= b;
	EXPECT_EQ(7+2+3*4, a[0].i());
	EXPECT_EQ(8+2*2+3*5, a[0].j());
	EXPECT_EQ(9+2*3+3*6, a[0].k());
	EXPECT_EQ(4*7+5+6*4, a[1].i());
	EXPECT_EQ(4*8+5*2+6*5, a[1].j());
	EXPECT_EQ(4*9+5*3+6*6, a[1].k());
	EXPECT_EQ(7*7+8*1+9*4, a[2].i());
	EXPECT_EQ(7*8+8*2+9*5, a[2].j());
	EXPECT_EQ(7*9+8*3+9*6, a[2].k());
}
TEST(PhysMatrixTest, MatrixMultiplication){
	auto c = mathengine::Matrix(1, 2, 3, 4, 5, 6, 7, 8, 9);
	auto b = mathengine::Matrix(7, 8, 9, 1, 2, 3, 4, 5, 6);
	auto a = c*b;
	EXPECT_EQ(7+2+3*4, a[0].i());
	EXPECT_EQ(8+2*2+3*5, a[0].j());
	EXPECT_EQ(9+2*3+3*6, a[0].k());
	EXPECT_EQ(4*7+5+6*4, a[1].i());
	EXPECT_EQ(4*8+5*2+6*5, a[1].j());
	EXPECT_EQ(4*9+5*3+6*6, a[1].k());
	EXPECT_EQ(7*7+8*1+9*4, a[2].i());
	EXPECT_EQ(7*8+8*2+9*5, a[2].j());
	EXPECT_EQ(7*9+8*3+9*6, a[2].k());
}
TEST(PhysMatrixTest, Transpose){
	auto r1 = mathengine::Vector(1, 2, 3);
	auto r2 = mathengine::Vector(4, 5, 6);
	auto r3 = mathengine::Vector(7, 8, 9);
	auto t = mathengine::Matrix(r1, r2, r3);
	t.transpose();
	EXPECT_EQ(t.i(), r1);
	EXPECT_EQ(t.j(), r2);
	EXPECT_EQ(t.k(), r3);
}
TEST(PhysMatrixTest, TransposeOf){
	auto r1 = mathengine::Vector(1, 2, 3);
	auto r2 = mathengine::Vector(4, 5, 6);
	auto r3 = mathengine::Vector(7, 8, 9);
	auto u = mathengine::Matrix(r1, r2, r3);
	auto t = u.transpose_of();
	EXPECT_EQ(t.i(), r1);
	EXPECT_EQ(t.j(), r2);
	EXPECT_EQ(t.k(), r3);
}
TEST(PhysMatrixTest, InverseOfIdentity){
	auto t = mathengine::Matrix(1, 0, 0, 0, 1, 0, 0, 0, 1);
	auto u = t.inverse_of();
	EXPECT_EQ(t,u);
}
TEST(PhysMatrixTest, InverseOfException){
	auto t = mathengine::Matrix(1, 2, 3, 4, 5, 6, 7, 8, 9);
	ASSERT_THROW(t.inverse_of(), std::runtime_error);
}
TEST(PhysMatrixTest, InverseOf){
	auto t = mathengine::Matrix(1, 4, 5, 7, 2, 8, 9, 1, 2);
	t = t.inverse_of();
	EXPECT_DOUBLE_EQ(-4.0/173.0, t[0].i());
	EXPECT_DOUBLE_EQ(-3.0/173.0, t[0].j());
	EXPECT_DOUBLE_EQ(22.0/173.0, t[0].k());
	EXPECT_DOUBLE_EQ(58.0/173.0, t[1].i());
	EXPECT_DOUBLE_EQ(-43.0/173.0, t[1].j());
	EXPECT_DOUBLE_EQ(27.0/173.0, t[1].k());
	EXPECT_DOUBLE_EQ(-11.0/173.0, t[2].i());
	EXPECT_DOUBLE_EQ(35.0/173.0, t[2].j());
	EXPECT_DOUBLE_EQ(-26.0/173.0, t[2].k());
}
TEST(PhysMatrixTest, Determinate){
	auto t = mathengine::Matrix(1, 2, 3, 4, 5, 6, 7, 8, 9);
	auto d = t.det();
	EXPECT_DOUBLE_EQ(0,d);
}
int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
