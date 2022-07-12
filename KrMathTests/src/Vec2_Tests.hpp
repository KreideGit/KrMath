#pragma once

#include "KrMath/vec2.hpp"
#include <gtest/gtest.h>

TEST(Vec2_Instantiation, Default)
{
	KrMath::Vec2<float> vec;
	EXPECT_EQ(vec.x, 0.0f);
	EXPECT_EQ(vec.y, 0.0f);
}

TEST(Vec2_Instantiation, XY)
{
	KrMath::Vec2<float> vec(1.0f, 2.0f);
	EXPECT_EQ(vec.x, 1.0f);
	EXPECT_EQ(vec.y, 2.0f);
}

TEST(Vec2_Function, Length)
{
	KrMath::Vec2<float> vec(3.0f, 4.0f);
	EXPECT_EQ(vec.Length(), 5.0f);
}

TEST(Vec2_Function, Distance)
{
	KrMath::Vec2<float> vecA(1.0f, 5.0f);
	KrMath::Vec2<float> vecB(2.0f, 3.0f);
	EXPECT_EQ(vecA.Distance(vecB), (vecB - vecA).Length());
}

TEST(Vec2_Function, Normalize)
{
	KrMath::Vec2<float> vec(3.0f, 4.0f);
	vec.Normalize();
	EXPECT_EQ(vec.x, 3.0f / 5.0f);
	EXPECT_EQ(vec.y, 4.0f / 5.0f);
}

TEST(Vec2_Function, Normalized)
{
	KrMath::Vec2<float> vecA(3.0f, 4.0f);
	KrMath::Vec2<float> vecB = vecA.Normalized();
	EXPECT_EQ(vecB.x, 3.0f / 5.0f);
	EXPECT_EQ(vecB.y, 4.0f / 5.0f);
}

TEST(Vec2_Function, DotProduct)
{
	KrMath::Vec2<float> vecA(1.0f, 3.0f);
	KrMath::Vec2<float> vecB(2.0f, 4.0f);
	EXPECT_EQ(vecA.DotProduct(vecB), 14.0f);
}

TEST(Vec2_Function, Angle)
{
	KrMath::Vec2<float> vecA(2.0f, 2.0f);
	KrMath::Vec2<float> vecB(1.0f, 0.0f);
	EXPECT_EQ(vecA.Angle(vecB), (float)M_PI_4);
}

TEST(Vec2_Operation, Addition)
{
	KrMath::Vec2<float> vecA(1.0f, 2.0f);
	KrMath::Vec2<float> vecB(2.0f, 1.0f);
	KrMath::Vec2<float> vecC = vecA + vecB;
	EXPECT_EQ(vecC.x, 3.0f);
	EXPECT_EQ(vecC.y, 3.0f);
}

TEST(Vec2_Operation, Subtraction)
{
	KrMath::Vec2<float> vecA(1.0f, 2.0f);
	KrMath::Vec2<float> vecB(2.0f, 1.0f);
	KrMath::Vec2<float> vecC = vecA - vecB;
	EXPECT_EQ(vecC.x, -1.0f);
	EXPECT_EQ(vecC.y, 1.0f);
}

TEST(Vec2_Operation, Multiplication)
{
	KrMath::Vec2<float> vecA(1.0f, 2.0f);
	KrMath::Vec2<float> vecB(2.0f, 1.0f);
	KrMath::Vec2<float> vecC = vecA * vecB;
	EXPECT_EQ(vecC.x, 2.0f);
	EXPECT_EQ(vecC.y, 2.0f);
}

TEST(Vec2_Operation, Division)
{
	KrMath::Vec2<float> vecA(1.0f, 2.0f);
	KrMath::Vec2<float> vecB(2.0f, 1.0f);
	KrMath::Vec2<float> vecC = vecA / vecB;
	EXPECT_EQ(vecC.x, 0.5f);
	EXPECT_EQ(vecC.y, 2.0f);
}