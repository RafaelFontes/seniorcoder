#include <gtest/gtest.h>
#include "../src/sclogger.h"

TEST(SCLoggerTestCase, TestCompilation)
{
  EXPECT_NO_THROW(
    std::cout << "sclogger version " << sc::logger::version() << std::endl;
  );
};

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
