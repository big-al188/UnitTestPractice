/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, mixed_simple_true)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("aA");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, mixed_simple_false)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("aaaaa");
	ASSERT_EQ(false, actual);

}

TEST(PasswordTest, mixed_simple_empty_false)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("");
	ASSERT_EQ(false, actual);

}

TEST(PasswordTest, mixed_lastChar_true)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("AAAAAAADSSFASFa");
	ASSERT_EQ(true, actual);

}

TEST(PasswordTest, mixed_with_num_true)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("sdfgsdfh3g456Asgh");
	ASSERT_EQ(true, actual);

}

TEST(PasswordTest, mixed_with_num_false)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("sdfgsdfh3g456sgh");
	ASSERT_EQ(false, actual);

}


TEST(PasswordTest, mixed_with_symbols_false)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("sdfgsdfh(;@3g456sgh");
	ASSERT_EQ(false, actual);

}

TEST(PasswordTest, mixed_with_symbols_true)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("sdfgsdfh3$g4X5[6sgh");
	ASSERT_EQ(true, actual);

}