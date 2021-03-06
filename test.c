#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include <assert.h>
START_TEST(sumtest)
{
ck_assert(add(3,4) == 7);
ck_assert(add(-1,4) == 3);
}
END_TEST

START_TEST(subtest)
{
ck_assert(sub(3,4) == -1);
ck_assert(sub(-1,4) == -5);
}
END_TEST

START_TEST(mixtest)
{
ck_assert(add(sub(3,4),sub(-1,4)) == -6);
}
END_TEST

int main()
{
    Suite *s1 = suite_create("Sum");
    TCase *tc1_1 = tcase_create("Core");
    Suite *s2 = suite_create("mix");
    TCase *tc1_2 = tcase_create("MixCore");
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, sumtest);
    tcase_add_test(tc1_1, subtest);

    suite_add_tcase(s2, tc1_2);
    tcase_add_test(tc1_2, mixtest);
    
    SRunner *sr = srunner_create(s1);
    srunner_add_suite(sr,s2);
    
    srunner_run_all(sr, CK_NORMAL);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
