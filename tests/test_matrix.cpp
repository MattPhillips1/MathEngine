#include "Matrix.h"
#include "gtest/gtest.h"

class PhysMatrixTest : public ::testing::Test {

};

TEST(PhysMatrixTest, DefaultConstructor) {
	EXPECT_TRUE(true);
}
int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
