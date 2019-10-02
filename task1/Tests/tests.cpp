//
// Created by Андрей Гайдамака on 30.09.2019.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "TritSet.h"

class Declaration: public testing::Test{
public:
    TritSet obj;
    Declaration(){
        obj;
    }
};

TEST_F(Declaration, Memory){
    ASSERT_EQ(0, obj.capacity());
    obj[1000] = Trit(trit::UNKNOWN);
    ASSERT_EQ(0, obj.capacity());
    obj[1000] = Trit(trit::FALSE);
    ASSERT_LE(1000, obj.capacity());
    ASSERT_EQ(Trit(trit::FALSE), Trit(obj[1000]));
    ASSERT_EQ(1001, obj.length());
    obj.resize(5000);
    ASSERT_LE(5000,obj.size());
    ASSERT_EQ(1001, obj.length());
    obj.shrink();
    ASSERT_LE(obj.size(), 1008);
    ASSERT_GE(obj.size(), 1000);
}

TEST_F(Declaration, construction){
    ASSERT_EQ(0, obj.capacity());
    TritSet s(100);
    ASSERT_LE(s.capacity(), 112);
    ASSERT_GE(s.capacity(), 96);
    s[45] = Trit(trit::TRUE);
    TritSet l(s);
    ASSERT_EQ(s.capacity(), l.capacity());
    ASSERT_EQ(Trit(s[45]), Trit(l[45]));
}

TEST_F(Declaration, trim){
    obj[30] = Trit(trit::TRUE);
    obj[5] = Trit(trit::TRUE);
    obj[40] = Trit(trit::FALSE);
    obj[45] = Trit(trit::TRUE);
    obj.trim(30);
    ASSERT_EQ(Trit(obj[30]), Trit(true));
    ASSERT_EQ(Trit(obj[5]), Trit(true));
    ASSERT_EQ(Trit(obj[40]), Trit(trit::UNKNOWN));
    ASSERT_EQ(Trit(obj[45]), Trit(trit::UNKNOWN));
}

TEST_F(Declaration, binary){
    obj[2] = Trit(true);
    obj[1] = Trit(false);
    obj[0] = Trit(trit::UNKNOWN);
    TritSet s(3);
    s[2] = Trit(false);
    s[1] = Trit(trit::UNKNOWN);
    s[0] = Trit(true);
    obj &= s;
    ASSERT_EQ(Trit(obj[2]), Trit(false));
    ASSERT_EQ(Trit(obj[1]), Trit(false));
    ASSERT_EQ(Trit(obj[0]), Trit(trit::UNKNOWN));
}

TEST_F(Declaration, cardinality){
    obj[100] = Trit(trit::TRUE);
    obj[30] = Trit(trit::TRUE);
    obj[2] = Trit(trit::TRUE);
    obj[3] = Trit(trit::FALSE);
    obj[15] = Trit(trit::FALSE);
    obj[60] = Trit(trit::FALSE);
    obj[5] = Trit(trit::FALSE);
    obj[90] = Trit(trit::FALSE);
    for (int i = 0; i <= 100; ++i){
        std::cout << obj[i] << std::endl;
    }
    ASSERT_EQ(Trit(obj[30]), Trit(true));
    //ASSERT_EQ(obj.cardinality(Trit(trit::TRUE)), 3);
    ASSERT_EQ(obj.cardinality(Trit(trit::FALSE)), 5);
    ASSERT_EQ(obj.cardinality(Trit(trit::UNKNOWN)), 100 - 5 - 3);

}




