
#include "msign.h"

uint32_t msign_crc32( char* buffer, int buffer_len ) {
   uint32_t crc = 0;
   size_t i;

   while( --buffer_len >= 0 ) {
      crc = crc ^ *(buffer++) << 8;
      for( i = 8 ; 0 < i ; i-- ) {
         if( crc & 0x8000 ) {
            crc = crc << 1 ^ 0x1021;
         } else {
            crc = crc << 1;
         }
      }
   }

   return crc;
}

