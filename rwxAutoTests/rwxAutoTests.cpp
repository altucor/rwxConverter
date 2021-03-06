// rwxAutoTests.cpp : Defines the entry point for the console application.
//

#include "gtest/gtest.h"
#include "rwxLibClass.h"

// d - dash

rwxLibClass rwx;

TEST(RWX_String_To_Int, rwxrwxrwx__777)
{
	EXPECT_EQ(rwx.parseString("rwxrwxrwx"), std::string("777"));
}

TEST(RWX_String_To_Int, ddddddddd__000)
{
	EXPECT_EQ(rwx.parseString("---------"), std::string("000"));
}

TEST(RWX_String_To_Int, rwdrwdrwd__666)
{
	EXPECT_EQ(rwx.parseString("rw-rwxrwx"), std::string("677"));
	EXPECT_EQ(rwx.parseString("rwxrw-rwx"), std::string("767"));
	EXPECT_EQ(rwx.parseString("rwxrwxrw-"), std::string("776"));
}

TEST(RWX_String_To_Int, rdxrdxrdx__555)
{
	EXPECT_EQ(rwx.parseString("r-xrwxrwx"), std::string("577"));
	EXPECT_EQ(rwx.parseString("rwxr-xrwx"), std::string("757"));
	EXPECT_EQ(rwx.parseString("rwxrwxr-x"), std::string("775"));
}

TEST(RWX_String_To_Int, dwxdwxdwx__333)
{
	EXPECT_EQ(rwx.parseString("-wxrwxrwx"), std::string("377"));
	EXPECT_EQ(rwx.parseString("rwx-wxrwx"), std::string("737"));
	EXPECT_EQ(rwx.parseString("rwxrwx-wx"), std::string("773"));
}

TEST(RWX_String_To_Int, PSEUDO_RANDOM)
{
	EXPECT_EQ(rwx.parseString("-wxrw-r-x"), std::string("365"));
	EXPECT_EQ(rwx.parseString("-w-r----x"), std::string("241"));
	EXPECT_EQ(rwx.parseString("--xr--rw-"), std::string("146"));
}

// ------------------------------------------------------------------

TEST(RWX_Int_To_String, _777__rwxrwxrwx)
{
	EXPECT_EQ(rwx.parseNumber("777"), std::string("rwxrwxrwx"));
}

TEST(RWX_Int_To_String, _000__ddddddddd)
{
	EXPECT_EQ(rwx.parseNumber("000"), std::string("---------"));
}

TEST(RWX_Int_To_String, _542__rdxrdddwd)
{
	EXPECT_EQ(rwx.parseNumber("542"), std::string("r-xr---w-"));
}

TEST(RWX_Int_To_String, _123__ddxdwddwx)
{
	EXPECT_EQ(rwx.parseNumber("123"), std::string("--x-w--wx"));
}

TEST(RWX_Int_To_String, _456__rddrdxrwd)
{
	EXPECT_EQ(rwx.parseNumber("456"), std::string("r--r-xrw-"));
}

TEST(RWX_Int_To_String, _567__rdxrwdrwx)
{
	EXPECT_EQ(rwx.parseNumber("567"), std::string("r-xrw-rwx"));
}

// ------------------------------------------------------------------

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

