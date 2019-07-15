
#include <check.h>

#include "msign.h"

Suite* msign_suite();

int main( void ) {
   int number_failed = 0;

   Suite* s_msign = msign_suite();
   SRunner* sr_msign = srunner_create( s_msign );
   srunner_run_all( sr_msign, CK_VERBOSE );
   number_failed += srunner_ntests_failed( sr_msign );
   srunner_free( sr_msign );

   return( number_failed == 0 ) ? 0 : 1;
}

START_TEST( msign_check_crc32 ) {
   char* test_str = "The quick brown fox jumped over the lazy dog.";
   int test_len = 45;
   uint32_t test_crc = msign_crc32( test_str, test_len );
   ck_assert_uint_eq( 0x4746cf86, test_crc );
}
END_TEST

Suite* msign_suite( void ) {
   Suite* s;
   TCase* tc_core;

   s = suite_create( "msign" );

   /* Core test case */
   tc_core = tcase_create( "Core" );

   //tcase_add_loop_test( tc_core, msign_check_lex_token, 0, 13 );
   //tcase_add_loop_test( tc_core, msign_check_hash, 0, CHECK_STR_COUNT );
   tcase_add_test( tc_core, msign_check_crc32 );

   suite_add_tcase( s, tc_core );

   return s;
}


